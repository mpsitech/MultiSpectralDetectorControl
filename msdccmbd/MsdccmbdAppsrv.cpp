/**
  * \file MsdccmbdAppsrv.cpp
  * application server for Msdc combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#include "Msdccmbd.h"

#include "MsdccmbdAppsrv.h"

/******************************************************************************
 namespace MsdccmbdAppsrv
 ******************************************************************************/

MHD_Daemon* MsdccmbdAppsrv::start(
			XchgMsdccmbd* xchg
		) {
	if (xchg->stgmsdccmbd.https) {
		return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL | MHD_USE_SSL, xchg->stgmsdccmbd.appsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_HTTPS_MEM_KEY, xchg->key.c_str(), MHD_OPTION_HTTPS_MEM_CERT, xchg->cert.c_str(), MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
	} else {
		return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL, xchg->stgmsdccmbd.appsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
	};
};

void MsdccmbdAppsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

int MsdccmbdAppsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

int MsdccmbdAppsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgMsdc* xchg = (XchgMsdc*) cls;

  MHD_Response* response;
	int retval = MHD_YES;

	ReqMsdc* req;
	uint ixVBasetype = ReqMsdc::VecVBasetype::NONE;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	string mimetype;
	size_t ptr;

	uint ixMsdcVDpch;

	ubigint jrefNotify;

	DcolMsdc* dcol;

	char empty[] = "\n";
	char invalid[] = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	string s, s2;

	bool valid;

	if (*con_cls == NULL) {
		// new request
		s = string(url);

		if (strcmp(method, "GET") == 0) {
			// cout << "have GET request, url is '" << s << "'" << endl;

			if (s.find("/web/") != string::npos) {
				// cout << "request for '" << s.substr(4) << "' by html transfer" << endl;

				// ex. "/html/CrdMsdcNav/CrdMsdcNav.html" ; note that eventual parameters such as "?scrJref=abcd1234efgh5678" are not included in url

				// inhibit requests to ../ directories
				if (s.find("../") == string::npos) {

					// check if file exists
					s2 = xchg->stgmsdcpath.webpath + s.substr(4);
					if (access(s2.c_str(), R_OK) == 0) {
						ixVBasetype = ReqMsdc::VecVBasetype::WEB;
						// cout << "MhdCallback() HTML request for '" << s2 << "'" << endl;
					};
				};

			} else if (s.find("/notify") != string::npos) {
				// always "/notify/abcd1234efgh5678"
				ixVBasetype = ReqMsdc::VecVBasetype::NOTIFY;

			} else if (s.find("/poll") != string::npos) {
				// always "/poll/abcd1234efgh5678"
				ixVBasetype = ReqMsdc::VecVBasetype::POLL;

			} else if (s.find("/download/") != string::npos) {
				// ex. "/download/abcd1234efgh5678"
				ixVBasetype = ReqMsdc::VecVBasetype::DOWNLOAD;
			};

		} else if (strcmp(method, "POST") == 0) {
			if (s.find("/dpch") != string::npos) {
				// always "/dpch"
				ixVBasetype = ReqMsdc::VecVBasetype::REGULAR;

			} else if (s.find("/upload/") != string::npos) {
				// ex. "/upload/abcd1234efgh5678"
				ixVBasetype = ReqMsdc::VecVBasetype::UPLOAD;
			};
		};

		if (ixVBasetype == ReqMsdc::VecVBasetype::NONE) {
			// not a valid request
			response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
			//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);

		} else {
			addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

			if (addr->sa_family == AF_INET) {
#ifdef _WIN32
				ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
				inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
				ip = ipstr;
#endif
			};

			req = new ReqMsdc(ixVBasetype, ReqMsdc::VecVState::RECEIVE, ip);
			*con_cls = req;

			if (req->ixVBasetype == ReqMsdc::VecVBasetype::WEB) {
				// --- open file and initiate transmission
				req->filename = xchg->stgmsdcpath.webpath + s.substr(4);

				req->file = new fstream();
				req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

				// get file length
				req->file->seekg(0, ios::end);
				req->filelen = req->file->tellg();
				req->file->seekg(0, ios::beg);

				if (req->filelen == 0) {
					// empty files require special handling
					response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);

				} else {
					response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);

					// determine MIME type from file extension
					ptr = req->filename.rfind('.');
					if (ptr != string::npos) mimetype = VecMsdcVMimetype::getTitle(VecMsdcVMimetype::getIx(req->filename.substr(ptr+1)));
					if (mimetype.length() == 0) mimetype = VecMsdcVMimetype::getTitle(VecMsdcVMimetype::TXT);
					MHD_add_response_header(response, "Content-Type", mimetype.c_str());					

					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::REGULAR) {
				// --- prepare POST processor
				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::NOTIFY) {
				// --- notify on dispatch in dispatch collector
				req->jref = Scr::descramble(s.substr(s.find("/notify/")+8));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					jrefNotify = xchg->getRefPreset(VecMsdcVPreset::PREMSDCJREFNOTIFY, req->jref);

					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) {
						dcol = xchg->addDcol(req->jref);
						if (dcol) jrefNotify = req->jref;
					};

					valid = dcol;
				};

				if (valid) {
					req->ixMsdcVLocale = dcol->ixMsdcVLocale;

					if (dcol->dpchs.empty()) {
						if (dcol->hot) {
							// send default reply immediately
							req->dpcheng = new DpchEngMsdcAck(req->jref);

							dcol->hot = false;
							dcol->unlockAccess("MsdccmbdAppsrv", "MhdCallback[1]");

						} else if (jrefNotify != dcol->jref) {
							// ask client to resort to POLL mode
							req->dpcheng = new DpchEngMsdcSuspend(req->jref);

							dcol->unlockAccess("MsdccmbdAppsrv", "MhdCallback[2]");

						} else {
							// wait for next notification to arrive in dispatch collector
							
							// default req->dpcheng to be overwritten
							req->dpcheng = new DpchEngMsdcAck(req->jref);
							dcol->req = req;

							// note: when dcol with req != NULL is deleted, req->cReady will be broadcast
							req->cReady.lockMutex("MsdccmbdAppsrv", "MhdCallback[1]");
							dcol->unlockAccess("MsdccmbdAppsrv", "MhdCallback[3]");
							req->cReady.timedwait(15000000, "MsdccmbdAppsrv", "MhdCallback");
							// cout << "got one after timedwait" << endl;
							req->cReady.unlockMutex("MsdccmbdAppsrv", "MhdCallback[1]");

							dcol = xchg->getDcolByJref(req->jref);
							if (dcol) {
								// note: the destructor of dcol is called after dcol is removed from the list from which it can be found by getDcolByJref()
								dcol->req = NULL;
								dcol->unlockAccess("MsdccmbdAppsrv", "MhdCallback[4]");

							} else {
								delete req->dpcheng;
								req->dpcheng = new DpchEngMsdcConfirm(false, req->jref);
							};
						};

						writeDpchEng(xchg, req);
						req->ixVState = ReqMsdc::VecVState::REPLY;

						// send reply ; note that the result of timedwait() doesn't matter
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;

						dcol->hot = true;
						dcol->unlockAccess("MsdccmbdAppsrv", "MhdCallback[5]");

						writeDpchEng(xchg, req);
						req->ixVState = ReqMsdc::VecVState::REPLY;

						// send first dispatch available in dispatch collector
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::POLL) {
				// --- send first dispatch available in dispatch collector
				req->jref = Scr::descramble(s.substr(s.find("/poll/")+6));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) dcol = xchg->addDcol(req->jref);

					valid = dcol;
				};

				if (valid) {
					req->ixMsdcVLocale = dcol->ixMsdcVLocale;
					dcol->hot = false;

					if (dcol->dpchs.empty()) {
						// send default reply
						req->dpcheng = new DpchEngMsdcAck(req->jref);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;
					};

					dcol->unlockAccess("MsdccmbdAppsrv", "MhdCallback[6]");

					writeDpchEng(xchg, req);
					req->ixVState = ReqMsdc::VecVState::REPLY;

					// send reply
					response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::UPLOAD) {
				req->jref = Scr::descramble(s.substr(s.find("/upload/")+8));

				// generate file in tmp directory, and open it
				req->filename = xchg->stgmsdcpath.tmppath + "/" + Tmp::newfile(xchg->stgmsdcpath.tmppath, "");

				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::DOWNLOAD) {
				// --- pass request to jobprc, to ask for filename in tmp directory ; then proceed sending - same procedure as for HTML
				req->jref = Scr::descramble(s.substr(s.find("/download/")+10));
				valid = validateIp(xchg, req);

				if (valid) {
					validateJrefNotify(xchg, req);

					xchg->addReq(req);

					// wait for reply
					req->cReady.lockMutex("MsdccmbdAppsrv", "MhdCallback[2]");
					if (req->ixVState != ReqMsdc::VecVState::REPLY) req->cReady.wait("MsdccmbdAppsrv", "MhdCallback[1]");
					req->cReady.unlockMutex("MsdccmbdAppsrv", "MhdCallback[2]");

					// cout << "preparing '" << req->filename << "' for download transfer" << endl;

					valid = (access(req->filename.c_str(), R_OK) == 0);
				};

				if (valid) {
					req->file = new fstream();
					req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

					// get file length
					req->file->seekg(0, ios::end);
					req->filelen = req->file->tellg();
					req->file->seekg(0, ios::beg);

					if (req->filelen == 0) {
						// empty files require special handling
						response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};

	} else {
		// active/old request (GET: should not go through here ; POST: REGULAR, UPLOAD)
		req = (ReqMsdc*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

			} else {
				// POST done
				if (req->ixVBasetype == ReqMsdc::VecVBasetype::REGULAR) {
					// --- read dispatch, pass on to job processor, and wait for reply to be transmitted
					// cout << "MhdCallback() REGULAR request complete" << endl;
					valid = req->request;
					
					if (valid) {
						//cout << string(req->request, req->requestlen) << endl;
						ixMsdcVDpch = readDpchApp(xchg, req);
						valid = req->dpchapp;
					};

					if (valid) {
						req->jref = req->dpchapp->jref;
						valid = validateIp(xchg, req);

						if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPROOTMSDCLOGIN) req->jref = xchg->jrefRoot;
					};

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply
						req->cReady.lockMutex("MsdccmbdAppsrv", "MhdCallback[3]");
						if (req->ixVState != ReqMsdc::VecVState::REPLY) req->cReady.wait("MsdccmbdAppsrv", "MhdCallback[2]");
						req->cReady.unlockMutex("MsdccmbdAppsrv", "MhdCallback[3]");

						if (req->dpcheng) {
							writeDpchEng(xchg, req);
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};
					
					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};

				} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::UPLOAD) {
					// --- pass notification concerning uploaded file to job processor, and wait for acknowledgement
					valid = validateIp(xchg, req);

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply (usually empty)
						req->cReady.lockMutex("MsdccmbdAppsrv", "MhdCallback[4]");
						if (req->ixVState != ReqMsdc::VecVState::REPLY) req->cReady.wait("MsdccmbdAppsrv", "MhdCallback[3]");
						req->cReady.unlockMutex("MsdccmbdAppsrv", "MhdCallback[4]");

						if (req->reply) {
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};

					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};
				};
			};
		};
	};

	return retval;
};

#ifdef _WIN32
int MsdccmbdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, int max
		) {
#else
ssize_t MsdccmbdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, size_t max
		) {
#endif
	ReqMsdc* req = (ReqMsdc*) con_cls;

	int64_t spos = pos;
	int64_t len;

	if (req) {
		// determine length remaining
		req->file->seekg(0, ios::end);
		len = req->file->tellg();
		if (len != -1) {

			if (len > spos) {
				req->file->seekg(spos);
				req->file->read(buf, max);

				// check for errors
				if (req->file->bad()) return 0;

				if (len < (max+spos))
					return (len-spos);
				else
					return max;
			};
		};
	};

	return 0;
};

int MsdccmbdAppsrv::MhdPostrecv(
			void* con_cls
			, MHD_ValueKind kind
			, const char* key
			, const char* filename
			, const char* content_type
			, const char* transfer_encoding
			, const char* data
			, uint64_t off
			, size_t size
		) {
	ReqMsdc* req = (ReqMsdc*) con_cls;

	//cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	if (req->ixVBasetype == ReqMsdc::VecVBasetype::REGULAR) {
		// --- copy data into req->request (append if required)
		if (strcmp(key, "xml") != 0) return MHD_NO;

		if (size > 0) {
			if (!req->request) {
				req->request = new char[size];
				memcpy(req->request, data, size);
				req->requestlen = size;

			} else {
				olddata = req->request;

				req->request = new char[req->requestlen + size];
				memcpy(req->request, olddata, req->requestlen);
				memcpy(&(req->request[req->requestlen]), data, size);
				req->requestlen = req->requestlen + size;

				delete[] olddata;
			};
		};

	} else if (req->ixVBasetype == ReqMsdc::VecVBasetype::UPLOAD) {
		// --- write data into file
		if (strcmp(key, "file") != 0) return MHD_NO;

		if (size > 0) {
			req->file = new fstream();

			req->file->open(req->filename.c_str(), fstream::app | fstream::out | fstream::binary);
			req->file->write(data, size);
			req->file->close();

			delete(req->file);
			req->file = NULL;
		};

	} else {
		return MHD_NO;
	};

	return MHD_YES;
};

void MsdccmbdAppsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqMsdc* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqMsdc*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

bool MsdccmbdAppsrv::validateIp(
			XchgMsdccmbd* xchg
			, ReqMsdc* req
		) {
	bool retval = true;

	string ip;

	if (req->jref != 0) {
		if (xchg->getBoolvalPreset(VecMsdcVPreset::PREMSDCSUSPSESS, req->jref))
					if (req->jref != xchg->getRefPreset(VecMsdcVPreset::PREMSDCJREFSESS, req->jref)) retval = false;

		if (retval) {
			ip = xchg->getTxtvalPreset(VecMsdcVPreset::PREMSDCIP, req->jref);
			if (ip != req->ip) retval = false;
		};
	};

	return retval;
};

bool MsdccmbdAppsrv::validateJrefNotify(
			XchgMsdccmbd* xchg
			, ReqMsdc* req
		) {
	bool retval = false;

	ubigint jrefNotify;

	DcolMsdc* dcol = NULL;

	jrefNotify = xchg->getRefPreset(VecMsdcVPreset::PREMSDCJREFNOTIFY, req->jref);

	dcol = xchg->getDcolByJref(req->jref);

	if (dcol) {
		retval = (jrefNotify == dcol->jref);
		if (!retval) xchg->triggerIxRefCall(NULL, VecMsdcVCall::CALLMSDCREFPRESET, dcol->jref, VecMsdcVPreset::PREMSDCJREFNOTIFY, dcol->jref);

		dcol->unlockAccess("MsdccmbdAppsrv", "validateJrefNotify");
	};

	return retval;
};

uint MsdccmbdAppsrv::readDpchApp(
			XchgMsdccmbd* xchg
			, ReqMsdc* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->request, req->requestlen, &doc, &docctx);

	uint ixMsdcVDpch = VecMsdcVDpch::getIx(extractRoot(doc));

	if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPDLGMSDCFILDOWNLOADDO) {
		req->dpchapp = new DlgMsdcFilDownload::DpchAppDo();
		((DlgMsdcFilDownload::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPDLGMSDCNAVLOAINIDATA) {
		req->dpchapp = new DlgMsdcNavLoaini::DpchAppData();
		((DlgMsdcNavLoaini::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPDLGMSDCNAVLOAINIDO) {
		req->dpchapp = new DlgMsdcNavLoaini::DpchAppDo();
		((DlgMsdcNavLoaini::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCALERT) {
		req->dpchapp = new DpchAppMsdcAlert();
		((DpchAppMsdcAlert*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATAPARDATA) {
		req->dpchapp = new PnlMsdcDatAPar::DpchAppData();
		((PnlMsdcDatAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATAPARDO) {
		req->dpchapp = new PnlMsdcDatAPar::DpchAppDo();
		((PnlMsdcDatAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATDETAILDATA) {
		req->dpchapp = new PnlMsdcDatDetail::DpchAppData();
		((PnlMsdcDatDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATDETAILDO) {
		req->dpchapp = new PnlMsdcDatDetail::DpchAppDo();
		((PnlMsdcDatDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATDO) {
		req->dpchapp = new CrdMsdcDat::DpchAppDo();
		((CrdMsdcDat::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATLISTDATA) {
		req->dpchapp = new PnlMsdcDatList::DpchAppData();
		((PnlMsdcDatList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATLISTDO) {
		req->dpchapp = new PnlMsdcDatList::DpchAppDo();
		((PnlMsdcDatList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATRECDO) {
		req->dpchapp = new PnlMsdcDatRec::DpchAppDo();
		((PnlMsdcDatRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATREF1NFILEDATA) {
		req->dpchapp = new PnlMsdcDatRef1NFile::DpchAppData();
		((PnlMsdcDatRef1NFile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCDATREF1NFILEDO) {
		req->dpchapp = new PnlMsdcDatRef1NFile::DpchAppDo();
		((PnlMsdcDatRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCFILDETAILDATA) {
		req->dpchapp = new PnlMsdcFilDetail::DpchAppData();
		((PnlMsdcFilDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCFILDETAILDO) {
		req->dpchapp = new PnlMsdcFilDetail::DpchAppDo();
		((PnlMsdcFilDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCFILDO) {
		req->dpchapp = new CrdMsdcFil::DpchAppDo();
		((CrdMsdcFil::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCFILLISTDATA) {
		req->dpchapp = new PnlMsdcFilList::DpchAppData();
		((PnlMsdcFilList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCFILLISTDO) {
		req->dpchapp = new PnlMsdcFilList::DpchAppDo();
		((PnlMsdcFilList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCFILRECDO) {
		req->dpchapp = new PnlMsdcFilRec::DpchAppDo();
		((PnlMsdcFilRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCINIT) {
		req->dpchapp = new DpchAppMsdcInit();
		((DpchAppMsdcInit*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVALIGNDATA) {
		req->dpchapp = new PnlMsdcLivAlign::DpchAppData();
		((PnlMsdcLivAlign::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVALIGNDO) {
		req->dpchapp = new PnlMsdcLivAlign::DpchAppDo();
		((PnlMsdcLivAlign::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVDO) {
		req->dpchapp = new CrdMsdcLiv::DpchAppDo();
		((CrdMsdcLiv::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVSCILLDATA) {
		req->dpchapp = new PnlMsdcLivScill::DpchAppData();
		((PnlMsdcLivScill::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVSCILLDO) {
		req->dpchapp = new PnlMsdcLivScill::DpchAppDo();
		((PnlMsdcLivScill::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVTRACKDO) {
		req->dpchapp = new PnlMsdcLivTrack::DpchAppDo();
		((PnlMsdcLivTrack::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVVIDEODATA) {
		req->dpchapp = new PnlMsdcLivVideo::DpchAppData();
		((PnlMsdcLivVideo::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCLIVVIDEODO) {
		req->dpchapp = new PnlMsdcLivVideo::DpchAppDo();
		((PnlMsdcLivVideo::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVADMINDATA) {
		req->dpchapp = new PnlMsdcNavAdmin::DpchAppData();
		((PnlMsdcNavAdmin::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVADMINDO) {
		req->dpchapp = new PnlMsdcNavAdmin::DpchAppDo();
		((PnlMsdcNavAdmin::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVDO) {
		req->dpchapp = new CrdMsdcNav::DpchAppDo();
		((CrdMsdcNav::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVOPRDATA) {
		req->dpchapp = new PnlMsdcNavOpr::DpchAppData();
		((PnlMsdcNavOpr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVOPRDO) {
		req->dpchapp = new PnlMsdcNavOpr::DpchAppDo();
		((PnlMsdcNavOpr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCNAVPREDO) {
		req->dpchapp = new PnlMsdcNavPre::DpchAppDo();
		((PnlMsdcNavPre::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRD1NDATADATA) {
		req->dpchapp = new PnlMsdcPrd1NData::DpchAppData();
		((PnlMsdcPrd1NData::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRD1NDATADO) {
		req->dpchapp = new PnlMsdcPrd1NData::DpchAppDo();
		((PnlMsdcPrd1NData::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRDDETAILDATA) {
		req->dpchapp = new PnlMsdcPrdDetail::DpchAppData();
		((PnlMsdcPrdDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRDDETAILDO) {
		req->dpchapp = new PnlMsdcPrdDetail::DpchAppDo();
		((PnlMsdcPrdDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRDDO) {
		req->dpchapp = new CrdMsdcPrd::DpchAppDo();
		((CrdMsdcPrd::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRDLISTDATA) {
		req->dpchapp = new PnlMsdcPrdList::DpchAppData();
		((PnlMsdcPrdList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRDLISTDO) {
		req->dpchapp = new PnlMsdcPrdList::DpchAppDo();
		((PnlMsdcPrdList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRDRECDO) {
		req->dpchapp = new PnlMsdcPrdRec::DpchAppDo();
		((PnlMsdcPrdRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRSDETAILDATA) {
		req->dpchapp = new PnlMsdcPrsDetail::DpchAppData();
		((PnlMsdcPrsDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRSDETAILDO) {
		req->dpchapp = new PnlMsdcPrsDetail::DpchAppDo();
		((PnlMsdcPrsDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRSDO) {
		req->dpchapp = new CrdMsdcPrs::DpchAppDo();
		((CrdMsdcPrs::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRSLISTDATA) {
		req->dpchapp = new PnlMsdcPrsList::DpchAppData();
		((PnlMsdcPrsList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRSLISTDO) {
		req->dpchapp = new PnlMsdcPrsList::DpchAppDo();
		((PnlMsdcPrsList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCPRSRECDO) {
		req->dpchapp = new PnlMsdcPrsRec::DpchAppDo();
		((PnlMsdcPrsRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCRESUME) {
		req->dpchapp = new DpchAppMsdcResume();
		((DpchAppMsdcResume*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFACQUISDATA) {
		req->dpchapp = new PnlMsdcScfAcquis::DpchAppData();
		((PnlMsdcScfAcquis::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFACQUISDO) {
		req->dpchapp = new PnlMsdcScfAcquis::DpchAppDo();
		((PnlMsdcScfAcquis::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFACTUDATA) {
		req->dpchapp = new PnlMsdcScfActu::DpchAppData();
		((PnlMsdcScfActu::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFACTUDO) {
		req->dpchapp = new PnlMsdcScfActu::DpchAppDo();
		((PnlMsdcScfActu::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFDO) {
		req->dpchapp = new CrdMsdcScf::DpchAppDo();
		((CrdMsdcScf::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFPRCCTLDO) {
		req->dpchapp = new PnlMsdcScfPrcctl::DpchAppDo();
		((PnlMsdcScfPrcctl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFSOURCEDATA) {
		req->dpchapp = new PnlMsdcScfSource::DpchAppData();
		((PnlMsdcScfSource::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCSCFSOURCEDO) {
		req->dpchapp = new PnlMsdcScfSource::DpchAppDo();
		((PnlMsdcScfSource::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGAACCESSDATA) {
		req->dpchapp = new PnlMsdcUsgAAccess::DpchAppData();
		((PnlMsdcUsgAAccess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGAACCESSDO) {
		req->dpchapp = new PnlMsdcUsgAAccess::DpchAppDo();
		((PnlMsdcUsgAAccess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGDETAILDATA) {
		req->dpchapp = new PnlMsdcUsgDetail::DpchAppData();
		((PnlMsdcUsgDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGDETAILDO) {
		req->dpchapp = new PnlMsdcUsgDetail::DpchAppDo();
		((PnlMsdcUsgDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGDO) {
		req->dpchapp = new CrdMsdcUsg::DpchAppDo();
		((CrdMsdcUsg::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGLISTDATA) {
		req->dpchapp = new PnlMsdcUsgList::DpchAppData();
		((PnlMsdcUsgList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGLISTDO) {
		req->dpchapp = new PnlMsdcUsgList::DpchAppDo();
		((PnlMsdcUsgList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGMNUSERDATA) {
		req->dpchapp = new PnlMsdcUsgMNUser::DpchAppData();
		((PnlMsdcUsgMNUser::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGMNUSERDO) {
		req->dpchapp = new PnlMsdcUsgMNUser::DpchAppDo();
		((PnlMsdcUsgMNUser::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSGRECDO) {
		req->dpchapp = new PnlMsdcUsgRec::DpchAppDo();
		((PnlMsdcUsgRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSR1NSESSIONDATA) {
		req->dpchapp = new PnlMsdcUsr1NSession::DpchAppData();
		((PnlMsdcUsr1NSession::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSR1NSESSIONDO) {
		req->dpchapp = new PnlMsdcUsr1NSession::DpchAppDo();
		((PnlMsdcUsr1NSession::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRAACCESSDATA) {
		req->dpchapp = new PnlMsdcUsrAAccess::DpchAppData();
		((PnlMsdcUsrAAccess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRAACCESSDO) {
		req->dpchapp = new PnlMsdcUsrAAccess::DpchAppDo();
		((PnlMsdcUsrAAccess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRDETAILDATA) {
		req->dpchapp = new PnlMsdcUsrDetail::DpchAppData();
		((PnlMsdcUsrDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRDETAILDO) {
		req->dpchapp = new PnlMsdcUsrDetail::DpchAppDo();
		((PnlMsdcUsrDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRDO) {
		req->dpchapp = new CrdMsdcUsr::DpchAppDo();
		((CrdMsdcUsr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRLISTDATA) {
		req->dpchapp = new PnlMsdcUsrList::DpchAppData();
		((PnlMsdcUsrList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRLISTDO) {
		req->dpchapp = new PnlMsdcUsrList::DpchAppDo();
		((PnlMsdcUsrList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRMNUSERGROUPDATA) {
		req->dpchapp = new PnlMsdcUsrMNUsergroup::DpchAppData();
		((PnlMsdcUsrMNUsergroup::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRMNUSERGROUPDO) {
		req->dpchapp = new PnlMsdcUsrMNUsergroup::DpchAppDo();
		((PnlMsdcUsrMNUsergroup::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPMSDCUSRRECDO) {
		req->dpchapp = new PnlMsdcUsrRec::DpchAppDo();
		((PnlMsdcUsrRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
	} else if (ixMsdcVDpch == VecMsdcVDpch::DPCHAPPROOTMSDCLOGIN) {
		req->dpchapp = new RootMsdc::DpchAppLogin();
		((RootMsdc::DpchAppLogin*) (req->dpchapp))->readXML(docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixMsdcVDpch;
};

void MsdccmbdAppsrv::writeDpchEng(
			XchgMsdccmbd* xchg
			, ReqMsdc* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);

	if (req->dpcheng) {
		req->dpcheng->writeXML(req->ixMsdcVLocale, wr);
	} else {
		DpchEngMsdcConfirm dpchconfirm(false, req->jref, "");
		dpchconfirm.writeXML(req->ixMsdcVLocale, wr);
	};

	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

