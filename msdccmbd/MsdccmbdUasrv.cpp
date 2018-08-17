/**
	* \file MsdccmbdUasrv.cpp
	* OPC UA server based on Matrikon FLEX OPC UA SDK for Msdc combined daemon (implementation)
	* \author Alexander Wirthmueller
	* \date created: 15 Aug 2018
	* \date modified: 15 Aug 2018
	*/

#include "Msdccmbd.h"

#include "MsdccmbdUasrv.h"

/******************************************************************************
 class MsdccmbdUasrv::Session
 ******************************************************************************/

MsdccmbdUasrv::Session::Session() : IUserPermissions_t() {
	jrefM2msess = 0;
};

void MsdccmbdUasrv::Session::Initialise(
			const string& sref
			, const string& Password
		) {
	if ((sref == "") || (Password == "")) return;

	ReqMsdc* req = NULL;

	RootMsdc::DpchAppLogin* dpchapplogin = NULL;

	uint ixAcc;

	// - start M2M session
	req = new ReqMsdc(ReqMsdc::VecVBasetype::REGULAR, ReqMsdc::VecVState::RECEIVE, "127.0.0.1");

	req->jref = xchg->jrefRoot;

	dpchapplogin = new RootMsdc::DpchAppLogin();
	dpchapplogin->jref = xchg->jrefRoot;
	dpchapplogin->username = sref;
	dpchapplogin->password = Password;
	dpchapplogin->m2mNotReg = true;

	req->dpchapp = dpchapplogin;

	xchg->addReq(req);

	Mutex::lock(&(req->mcReady), "req->mcReady", "MsdccmbdUasrv::Session", "Session");
	if (req->ixVState != ReqMsdc::VecVState::REPLY) Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "MsdccmbdUasrv::Session", "Session");
	Mutex::unlock(&(req->mcReady), "req->mcReady", "MsdccmbdUasrv::Session", "Session");

	if (req->dpcheng) if (req->dpcheng->ixMsdcVDpch == VecMsdcVDpch::DPCHENGMSDCCONFIRM) if (((DpchEngMsdcConfirm*) (req->dpcheng))->accepted) jrefM2msess = req->dpcheng->jref;

	delete req;

	if (jrefM2msess != 0) {
		// - determine available jobs
		req = new ReqMsdc(ReqMsdc::VecVBasetype::REGULAR, ReqMsdc::VecVState::RECEIVE, "127.0.0.1");

		req->jref = jrefM2msess;

		req->dpchapp = new DpchAppMsdcInit();
		req->dpchapp->jref = jrefM2msess;

		xchg->addReq(req);

		Mutex::lock(&(req->mcReady), "req->mcReady", "MsdccmbdUasrv::Session", "Session");
		if (req->ixVState != ReqMsdc::VecVState::REPLY) Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "MsdccmbdUasrv::Session", "Session");
		Mutex::unlock(&(req->mcReady), "req->mcReady", "MsdccmbdUasrv::Session", "Session");

		if (req->dpcheng) if (req->dpcheng->ixMsdcVDpch == VecMsdcVDpch::DPCHENGM2MSESSMSDCDATA) if (req->dpcheng->has(M2msessMsdc::DpchEngData::STATSHR)) statshr = ((M2msessMsdc::DpchEngData*) (req->dpcheng))->statshr;

		delete req;

		// - probe access rights and add call listeners
		if (statshr.jrefAcqadxl != 0) {
			insert(jobaccs, VecMsdcVJob::JOBMSDCACQADXL);

			ixVFeatgroups[statshr.jrefAcqadxl] = VecMsdcVFeatgroup::VECVJOBMSDCACQADXLVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqadxl, VecMsdcVFeatgroup::VECVJOBMSDCACQADXLVAR, "alphaBeta", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQADXLVAR, "alphaBeta")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefAcqadxl, "alphaBeta");
			};
		};
		if (statshr.jrefAcqlwir != 0) {
			insert(jobaccs, VecMsdcVJob::JOBMSDCACQLWIR);

			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "setOutput", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "setOutput")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "start", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "start")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "stop", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "stop")] = ixAcc;

			ixVFeatgroups[statshr.jrefAcqlwir] = VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqlwir, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRVAR, "seqnoTGray16", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRVAR, "seqnoTGray16")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefAcqlwir, "seqnoTGray16");
			};
		};
		if (statshr.jrefAcqvisl != 0) {
			insert(jobaccs, VecMsdcVJob::JOBMSDCACQVISL);

			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setFocus", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setFocus")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setOutput", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setOutput")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setTint", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setTint")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "start", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "start")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "stop", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "stop")] = ixAcc;

			ixVFeatgroups[statshr.jrefAcqvisl] = VecMsdcVFeatgroup::VECVJOBMSDCACQVISLVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisl, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLVAR, "seqnoTRgbx8Gray8", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISLVAR, "seqnoTRgbx8Gray8")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefAcqvisl, "seqnoTRgbx8Gray8");
			};
		};
		if (statshr.jrefAcqvisr != 0) {
			insert(jobaccs, VecMsdcVJob::JOBMSDCACQVISR);

			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setFocus", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setFocus")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setOutput", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setOutput")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setTint", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setTint")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "start", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "start")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "stop", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "stop")] = ixAcc;

			ixVFeatgroups[statshr.jrefAcqvisr] = VecMsdcVFeatgroup::VECVJOBMSDCACQVISRVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefAcqvisr, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRVAR, "seqnoTRgbx8Gray8", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACQVISRVAR, "seqnoTRgbx8Gray8")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefAcqvisr, "seqnoTRgbx8Gray8");
			};
		};
		if (statshr.jrefActalign != 0) {
			insert(jobaccs, VecMsdcVJob::JOBMSDCACTALIGN);

			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActalign, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "setWave", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "setWave")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActalign, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "start", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "start")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActalign, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "stop", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "stop")] = ixAcc;

		};
		if (statshr.jrefActled != 0) {
			insert(jobaccs, VecMsdcVJob::JOBMSDCACTLED);

			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActled, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setFlood", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setFlood")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActled, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setSpot", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setSpot")] = ixAcc;

			ixVFeatgroups[statshr.jrefActled] = VecMsdcVFeatgroup::VECVJOBMSDCACTLEDVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActled, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDVAR, "floodSpot", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTLEDVAR, "floodSpot")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefActled, "floodSpot");
			};
		};
		if (statshr.jrefActservo != 0) {
			insert(jobaccs, VecMsdcVJob::JOBMSDCACTSERVO);

			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActservo, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setPhi", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setPhi")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActservo, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setTheta", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setTheta")] = ixAcc;

			ixVFeatgroups[statshr.jrefActservo] = VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecMsdcVCall::CALLMSDCACCESS, statshr.jrefActservo, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOVAR, "thetaPhi", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOVAR, "thetaPhi")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefActservo, "thetaPhi");
			};
		};
	};
};

Status_t MsdccmbdUasrv::Session::GetVariableNodeUserAccessLevel(
			const IVariableNode_t& node
			, AccessLevel_t& userAccessLevel
		) const {
	auto it = subvarsVars.find(node.NodeId()->Hash());

	if (it != subvarsVars.end()) {
		auto it2 = accs.find(it->second);

		if (it2 != accs.end()) {
			userAccessLevel = AccessLevel_t();
			userAccessLevel.CurrentRead(true);

			return OpcUa_Good;
		};
	};

	return OpcUa_BadNodeNotInView;
};

Status_t MsdccmbdUasrv::Session::GetNodeUserWriteMask(
			const INode_t& node
			, WriteMask_t& userWriteMask
		) const {
	userWriteMask = WriteMask_t();

	return OpcUa_Good;
};

Status_t MsdccmbdUasrv::Session::GetNodeUserVisibility(
			const INode_t& node
			, bool& visible
		) const {
	if (node.NodeId()->NamespaceIndex() == 0) {
		visible = true;

	} else {
		visible = false;

		auto it = jobs.find(node.NodeId()->Hash());
		if (it != jobs.end()) {
			auto it2 = jobaccs.find(it->second);
			visible = (it2 != jobaccs.end());
		} else {
			auto it2 = methods.find(node.NodeId()->Hash());
			if (it2 != methods.end()) {
				auto it3 = accs.find(it2->second);
				visible = (it3 != accs.end());
			} else {
				auto it3 = vars.find(node.NodeId()->Hash());
				if (it3 != vars.end()) {
					auto it4 = accs.find(it3->second);
					visible = (it4 != accs.end());
				} else {
					auto it4 = subvarsVars.find(node.NodeId()->Hash());
					if (it4 != subvarsVars.end()) {
						auto it5 = accs.find(it4->second);
						visible = (it5 != accs.end());
					};
				};
			};
		};
	};

	return OpcUa_Good;
};

Status_t MsdccmbdUasrv::Session::GetMethodNodeUserExecutable(
			const IMethodNode_t& method
			, bool& userExecutable
		) const {
	userExecutable = false;

	auto it = methods.find(method.NodeId()->Hash());

	if (it != methods.end()) {
		auto it2 = accs.find(it->second);
		if (it2 != accs.end()) userExecutable = ((it2->second & VecMsdcWAccess::EXEC) == VecMsdcWAccess::EXEC);
	};

	return OpcUa_Good;
};

/******************************************************************************
 class MsdccmbdUasrv::UserPermissionsProvider
 ******************************************************************************/

Status_t MsdccmbdUasrv::UserPermissionsProvider::GetUserPermissions(
			const NodeId_t& sessionId
			, const String_t& userName
			, const String_t& password
			, IntrusivePtr_t<IUserPermissions_t>& userPermissions
		) const {
	auto it = sessions.find(sessionId.Hash());

	if (it != sessions.end()) {
		userPermissions = it->second;
	} else {
		IntrusivePtr_t<Session> sess = new SafeRefCount_t<Session>();
		sess->Initialise(string((char*) userName.Payload().Data(), userName.Length()), string((char*) password.Payload().Data(), password.Length()));

		userPermissions = sess;

		if (sess->jrefM2msess != 0) sessions[sessionId.Hash()] = sess.get();
	};

	return OpcUa_Good;
};

Status_t MsdccmbdUasrv::UserPermissionsProvider::GetUserPermissions(
			const NodeId_t& sessionId
			, const X509IdentityToken_t& userIdentityToken
			, IntrusivePtr_t<IUserPermissions_t>& userPermissions
		) const {
	userPermissions = new SafeRefCount_t<Session>();
	return OpcUa_Good;
};

Status_t MsdccmbdUasrv::UserPermissionsProvider::GetUserPermissions(
			const NodeId_t& sessionId
			, const AnonymousIdentityToken_t& userIdentityToken
			, IntrusivePtr_t<IUserPermissions_t>& userPermissions
		) const {
	userPermissions = new SafeRefCount_t<Session>();
	return OpcUa_Good;
};

/******************************************************************************
 class MsdccmbdUasrv::ServerStateListener
 ******************************************************************************/

void MsdccmbdUasrv::ServerStateListener::StateHasChanged(
			ServerState_t::Enum_t state
		) const {
	if (state == ServerState_t::OPCUA_SERVER_STATE_FAILED) serverHasFailed = true;
};

void MsdccmbdUasrv::ServerStateListener::UnhandledError(
			Status_t errorCode
		) const {
	if (errorCode != OpcUa_Good) cout << "bad status code " << std::hex << errorCode.Value() << " not handled by OPC UA server" << endl;
};

/******************************************************************************
 class MsdccmbdUasrv::MethodHandler
 ******************************************************************************/

Status_t MsdccmbdUasrv::MethodHandler::CallMethodBegin(
			IntrusivePtr_t<const NodeId_t> sessionId
			, uint32_t transactionId
			, const IUserPermissions_t& userPermissions
			, uint32_t timeoutHint
			, IntrusivePtr_t<INode_t>& componentOf
			, IntrusivePtr_t<IMethodNode_t>& method
			, IntrusivePtr_t<const CallMethodRequest_t>& requestParameters
			, IntrusivePtr_t<CallMethodResult_t>& result
			, IntrusivePtr_t<ICallbackCallMethodCompleted_t>& completedCallback
		) {
	UASDK_RETURN_INVALID_ARGUMENT_IF_NULL(method)

	if (!requestParameters.is_set()) UASDK_RETURN_BAD_STATUS(OpcUa_BadArgumentsMissing);

	uint ixMsdcVFeatgroup = 0;
	string srefIxVMethod;

	IntrusivePtr_t<Session> session;
	ubigint jref = 0;

	// identify method
	auto it = methods.find(method->NodeId()->Hash());
	if (it != methods.end()) {
		ixMsdcVFeatgroup = it->second.ixVFeatgroup;
		srefIxVMethod = it->second.srefIxVFeature;
	} else {
		return OpcUa_BadMethodInvalid;
	};

	// find session
	auto it2 = sessions.find(sessionId->Hash());
	if (it2 != sessions.end()) {
		session = it2->second;

		if (ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD) jref = session->statshr.jrefAcqlwir;
		else if (ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD) jref = session->statshr.jrefAcqvisl;
		else if (ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD) jref = session->statshr.jrefAcqvisr;
		else if (ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD) jref = session->statshr.jrefActalign;
		else if (ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD) jref = session->statshr.jrefActled;
		else if (ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD) jref = session->statshr.jrefActservo;
	} else {
		return OpcUa_BadSessionIdInvalid;
	};

	if (jref != 0) {
		if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD) && (srefIxVMethod == "setOutput")) {
			if (requestParameters->InputArguments().Size() == 1) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "setOutput",
							{requestParameters->InputArguments()[0].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD) && (srefIxVMethod == "start")) {
			if (requestParameters->InputArguments().Size() == 0) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "start",
							{},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD) && (srefIxVMethod == "stop")) {
			if (requestParameters->InputArguments().Size() == 0) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD, "stop",
							{},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD) && (srefIxVMethod == "setFocus")) {
			if (requestParameters->InputArguments().Size() == 1) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setFocus",
							{requestParameters->InputArguments()[0].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD) && (srefIxVMethod == "setOutput")) {
			if (requestParameters->InputArguments().Size() == 3) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setOutput",
							{requestParameters->InputArguments()[0].get(),requestParameters->InputArguments()[1].get(),requestParameters->InputArguments()[2].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD) && (srefIxVMethod == "setTint")) {
			if (requestParameters->InputArguments().Size() == 1) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "setTint",
							{requestParameters->InputArguments()[0].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD) && (srefIxVMethod == "start")) {
			if (requestParameters->InputArguments().Size() == 0) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "start",
							{},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD) && (srefIxVMethod == "stop")) {
			if (requestParameters->InputArguments().Size() == 0) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD, "stop",
							{},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD) && (srefIxVMethod == "setFocus")) {
			if (requestParameters->InputArguments().Size() == 1) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setFocus",
							{requestParameters->InputArguments()[0].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD) && (srefIxVMethod == "setOutput")) {
			if (requestParameters->InputArguments().Size() == 3) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setOutput",
							{requestParameters->InputArguments()[0].get(),requestParameters->InputArguments()[1].get(),requestParameters->InputArguments()[2].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD) && (srefIxVMethod == "setTint")) {
			if (requestParameters->InputArguments().Size() == 1) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "setTint",
							{requestParameters->InputArguments()[0].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD) && (srefIxVMethod == "start")) {
			if (requestParameters->InputArguments().Size() == 0) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "start",
							{},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD) && (srefIxVMethod == "stop")) {
			if (requestParameters->InputArguments().Size() == 0) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD, "stop",
							{},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD) && (srefIxVMethod == "setWave")) {
			if (requestParameters->InputArguments().Size() == 3) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "setWave",
							{requestParameters->InputArguments()[0].get(),requestParameters->InputArguments()[1].get(),requestParameters->InputArguments()[2].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD) && (srefIxVMethod == "start")) {
			if (requestParameters->InputArguments().Size() == 0) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "start",
							{},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD) && (srefIxVMethod == "stop")) {
			if (requestParameters->InputArguments().Size() == 0) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD, "stop",
							{},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD) && (srefIxVMethod == "setFlood")) {
			if (requestParameters->InputArguments().Size() == 1) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setFlood",
							{requestParameters->InputArguments()[0].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD) && (srefIxVMethod == "setSpot")) {
			if (requestParameters->InputArguments().Size() == 1) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD, "setSpot",
							{requestParameters->InputArguments()[0].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD) && (srefIxVMethod == "setPhi")) {
			if (requestParameters->InputArguments().Size() == 1) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setPhi",
							{requestParameters->InputArguments()[0].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD) && (srefIxVMethod == "setTheta")) {
			if (requestParameters->InputArguments().Size() == 1) {
				result.reset(new SafeRefCount_t<CallMethodResult_t>());

				IntrusivePtr_t<Boolean_t> success = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD, "setTheta",
							{requestParameters->InputArguments()[0].get()},
							{success.get()});

				result->OutputArguments().Initialise(1);

				success->CopyTo(result->OutputArguments()[0]);

				result->StatusCode() = OpcUa_Good;
			};
		};

	} else {
		return OpcUa_BadInternalError;
	};

	return completedCallback->CallMethodCompleted(result);
};

/******************************************************************************
 class MsdccmbdUasrv::ValueAttributeReaderWriter
 ******************************************************************************/

Status_t MsdccmbdUasrv::ValueAttributeReaderWriter::ReadValueAttribute(
			const IVariableNode_t& node
			, uint32_t maxAge
			, bool setSourceTimestamp
			, const ArrayUA_t<String_t>& locales
			, const Array_t<IndexRange_t>& indexRange
			, uint32_t transactionId
			, uint32_t timeoutHint
			, IntrusivePtr_t<DataValue_t>& dataValue
			, IntrusivePtr_t<DiagnosticInfo_t>& diagnosticInfo
		) {
	uint ixMsdcVFeatgroup = 0;
	string srefIxVVar;
	string subvar;

	// identify variable
	auto it = subvarsVars.find(node.NodeId()->Hash());
	if (it != subvarsVars.end()) {
		ixMsdcVFeatgroup = it->second.ixVFeatgroup;
		srefIxVVar = it->second.srefIxVFeature;
	};

	auto it2 = subvars.find(node.NodeId()->Hash());
	if (it2 != subvars.end()) subvar = it2->second;

	if ((ixMsdcVFeatgroup != 0) && (srefIxVVar != "") && (subvar != "")) {
		dataValue = new SafeRefCount_t<DataValue_t>();
		*dataValue->StatusCode() = OpcUa_Good;

		if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQADXLVAR) && (srefIxVVar == "alphaBeta")) {
			JobMsdcAcqAdxl::shrdat.lockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "alpha") {
				IntrusivePtr_t<Float_t> alpha = new SafeRefCount_t<Float_t>();
				*alpha = JobMsdcAcqAdxl::shrdat.alpha;
				dataValue->Value() = alpha;
			} else if (subvar == "beta") {
				IntrusivePtr_t<Float_t> beta = new SafeRefCount_t<Float_t>();
				*beta = JobMsdcAcqAdxl::shrdat.beta;
				dataValue->Value() = beta;
			};

			JobMsdcAcqAdxl::shrdat.unlockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRVAR) && (srefIxVVar == "seqnoTGray16")) {
			JobMsdcAcqLwir::shrdat.lockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "seqno") {
				IntrusivePtr_t<UInt32_t> seqno = new SafeRefCount_t<UInt32_t>();
				*seqno = JobMsdcAcqLwir::shrdat.seqno;
				dataValue->Value() = seqno;
			} else if (subvar == "t") {
				IntrusivePtr_t<Double_t> t = new SafeRefCount_t<Double_t>();
				*t = JobMsdcAcqLwir::shrdat.t;
				dataValue->Value() = t;
			} else if (subvar == "gray16") {
				unsigned int len = JobMsdcAcqLwir::shrdat.gray16.size();
				IntrusivePtr_t<ArrayUA_t<UInt16_t> > gray16 = new SafeRefCount_t<ArrayUA_t<UInt16_t> >();
				gray16->Initialise(len);
				for (unsigned int i=0;i<len;i++) *((*gray16)[i]) = JobMsdcAcqLwir::shrdat.gray16[i];
				dataValue->Value() = gray16;
			};

			JobMsdcAcqLwir::shrdat.unlockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISLVAR) && (srefIxVVar == "seqnoTRgbx8Gray8")) {
			JobMsdcAcqVisl::shrdat.lockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "seqno") {
				IntrusivePtr_t<UInt32_t> seqno = new SafeRefCount_t<UInt32_t>();
				*seqno = JobMsdcAcqVisl::shrdat.seqno;
				dataValue->Value() = seqno;
			} else if (subvar == "t") {
				IntrusivePtr_t<Double_t> t = new SafeRefCount_t<Double_t>();
				*t = JobMsdcAcqVisl::shrdat.t;
				dataValue->Value() = t;
			} else if (subvar == "rgbx8") {
				unsigned int len = JobMsdcAcqVisl::shrdat.rgbx8.size();
				IntrusivePtr_t<ArrayUA_t<Byte_t> > rgbx8 = new SafeRefCount_t<ArrayUA_t<Byte_t> >();
				rgbx8->Initialise(len);
				for (unsigned int i=0;i<len;i++) *((*rgbx8)[i]) = JobMsdcAcqVisl::shrdat.rgbx8[i];
				dataValue->Value() = rgbx8;
			} else if (subvar == "gray8") {
				unsigned int len = JobMsdcAcqVisl::shrdat.gray8.size();
				IntrusivePtr_t<ArrayUA_t<Byte_t> > gray8 = new SafeRefCount_t<ArrayUA_t<Byte_t> >();
				gray8->Initialise(len);
				for (unsigned int i=0;i<len;i++) *((*gray8)[i]) = JobMsdcAcqVisl::shrdat.gray8[i];
				dataValue->Value() = gray8;
			};

			JobMsdcAcqVisl::shrdat.unlockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACQVISRVAR) && (srefIxVVar == "seqnoTRgbx8Gray8")) {
			JobMsdcAcqVisr::shrdat.lockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "seqno") {
				IntrusivePtr_t<UInt32_t> seqno = new SafeRefCount_t<UInt32_t>();
				*seqno = JobMsdcAcqVisr::shrdat.seqno;
				dataValue->Value() = seqno;
			} else if (subvar == "t") {
				IntrusivePtr_t<Double_t> t = new SafeRefCount_t<Double_t>();
				*t = JobMsdcAcqVisr::shrdat.t;
				dataValue->Value() = t;
			} else if (subvar == "rgbx8") {
				unsigned int len = JobMsdcAcqVisr::shrdat.rgbx8.size();
				IntrusivePtr_t<ArrayUA_t<Byte_t> > rgbx8 = new SafeRefCount_t<ArrayUA_t<Byte_t> >();
				rgbx8->Initialise(len);
				for (unsigned int i=0;i<len;i++) *((*rgbx8)[i]) = JobMsdcAcqVisr::shrdat.rgbx8[i];
				dataValue->Value() = rgbx8;
			} else if (subvar == "gray8") {
				unsigned int len = JobMsdcAcqVisr::shrdat.gray8.size();
				IntrusivePtr_t<ArrayUA_t<Byte_t> > gray8 = new SafeRefCount_t<ArrayUA_t<Byte_t> >();
				gray8->Initialise(len);
				for (unsigned int i=0;i<len;i++) *((*gray8)[i]) = JobMsdcAcqVisr::shrdat.gray8[i];
				dataValue->Value() = gray8;
			};

			JobMsdcAcqVisr::shrdat.unlockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTLEDVAR) && (srefIxVVar == "floodSpot")) {
			JobMsdcActLed::shrdat.lockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "flood") {
				IntrusivePtr_t<Float_t> flood = new SafeRefCount_t<Float_t>();
				*flood = JobMsdcActLed::shrdat.flood;
				dataValue->Value() = flood;
			} else if (subvar == "spot") {
				IntrusivePtr_t<Float_t> spot = new SafeRefCount_t<Float_t>();
				*spot = JobMsdcActLed::shrdat.spot;
				dataValue->Value() = spot;
			};

			JobMsdcActLed::shrdat.unlockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixMsdcVFeatgroup == VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOVAR) && (srefIxVVar == "thetaPhi")) {
			JobMsdcActServo::shrdat.lockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "theta") {
				IntrusivePtr_t<Float_t> theta = new SafeRefCount_t<Float_t>();
				*theta = JobMsdcActServo::shrdat.theta;
				dataValue->Value() = theta;
			} else if (subvar == "phi") {
				IntrusivePtr_t<Float_t> phi = new SafeRefCount_t<Float_t>();
				*phi = JobMsdcActServo::shrdat.phi;
				dataValue->Value() = phi;
			};

			JobMsdcActServo::shrdat.unlockAccess("MsdccmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");
		};
	};

	return OpcUa_Good;
};

/******************************************************************************
 namespace MsdccmbdUasrv
 ******************************************************************************/

void* MsdccmbdUasrv::run(
			void* arg
		) {
	xchg = (XchgMsdccmbd*) arg;

	Status_t status;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	uaserver = setupServer(status);
	if (status.IsBad()) return NULL;

	IntrusivePtr_t<IServerConfiguration_t> config = uaserver->GetConfiguration(status);
	if (status.IsBad()) return NULL;

	IntrusivePtr_t<INodeMethodHandler_t> methodHandler = new SafeRefCount_t<MethodHandler>();
	IntrusivePtr_t<INodeValueAttributeReaderWriter_t> readerWriter = new SafeRefCount_t<ValueAttributeReaderWriter>();

	status = fillAddressSpace(methodHandler, readerWriter, config->AddressSpace());
	if (status.IsBad()) return NULL;

	String_t dummy;
	uaserver->Start(dummy);

	while (true) {
		uaserver->Poll();

		Mutex::lock(&(xchg->mcUasrv), "xchg->mcUasrv", "MsdccmbdUasrv", "run");
		if (xchg->uasrvcall) {
			auto it = ixVFeatgroups.find(xchg->uasrvcall->jref);
			if (it != ixVFeatgroups.end()) timestamps[featix_t(it->second, xchg->uasrvcall->argInv.sref)] = UASDK_datetime();

			xchg->uasrvcall = NULL;

			Mutex::unlock(&(xchg->mcUasrv), "xchg->mcUasrv", "MsdccmbdUasrv", "run[1]");

			Cond::signal(&(xchg->cUasrv), &(xchg->mcUasrv), "xchg->cUasrv", "xchg->mcUasrv", "MsdccmbdUasrv", "run");

		} else {
			Mutex::unlock(&(xchg->mcUasrv), "xchg->mcUasrv", "MsdccmbdUasrv", "run[2]");
		};
	};

	pthread_cleanup_pop(0);

	return NULL;
};

void MsdccmbdUasrv::cleanup(
			void* arg
		) {
	XchgMsdccmbd* xchg = (XchgMsdccmbd*) arg;

	Mutex::unlock(&(xchg->mcUasrv), "xchg->mcUasrv", "MsdccmbdUasrv", "cleanup");

	if (uaserver.is_set()) {
		uaserver->Stop();
		uaserver->Terminate();
	};
};

IntrusivePtr_t<UAServer_t> MsdccmbdUasrv::setupServer(
			Status_t& result
		) {
	IntrusivePtr_t<UAServer_t> uaserver;

	// populate the address space with the help of nodeset file
	IntrusivePtr_t<IAddressSpace_t> addressSpace;

	if (!addressSpace.is_set()) {
		addressSpace = UAServer_t::CreateAddressSpace(9973, result);

		if (!addressSpace.is_set()) {
			result = OpcUa_BadOutOfMemory;
			return uaserver;
		};

		IntrusivePtr_t<IXmlNodesetIO_t> xmlParser = UAServer_t::CreateXmlNodesetIO(true, result);
		if (!xmlParser.is_set()) {
			result = OpcUa_BadOutOfMemory;
			return uaserver;
		};

		IntrusivePtr_t<StdFile_t> nodesetFile = new SafeRefCount_t<StdFile_t>();
		if (!nodesetFile.is_set()) {
			result = OpcUa_BadOutOfMemory;
			return uaserver;
		};

		IntrusivePtr_t<String_t> filename = new SafeRefCount_t<String_t>();
		if (!filename.is_set()) {
			result = OpcUa_BadOutOfMemory;
			return uaserver;
		};

		result = filename->CopyFrom(xchg->stgmsdcuasrv.profile.c_str());
		if (result.IsBad()) return uaserver;

		result = nodesetFile->Initialise(false, filename);
		if (result.IsBad()) return uaserver;

		result = xmlParser->Import(*nodesetFile, *addressSpace);
		if (result.IsBad()) return uaserver;
	};

	// create and configure server

	// get the unique application URI from the Server Array in the address space (was imported from the nodeset file)
	NodeIdNumeric_t serverArrayNodeId;
	serverArrayNodeId.NamespaceIndex() = 0;
	serverArrayNodeId.Identifer() = OpcUaId_Server_ServerArray;
	IntrusivePtr_t<IVariableNode_t> serverArrayNode = addressSpace->FindVariableNode(serverArrayNodeId, result);

	if (!serverArrayNode.is_set()) {
		result = OpcUa_BadConfigurationError;
		return uaserver;
	};

	IntrusivePtr_t<const DataValue_t> serverArrayValue = serverArrayNode->Value();
	if (!serverArrayValue.is_set() || !serverArrayValue->Value().is_set()) {
		result = OpcUa_BadConfigurationError;
		return uaserver;
	};

	IntrusivePtr_t<const ArrayUA_t<String_t> > serverArray = RuntimeCast<const ArrayUA_t<String_t>*>(*serverArrayValue->Value());
	if (!serverArray.is_set() || (serverArray->Count() < 1) || !(*serverArray)[0].is_set()) {
		result = OpcUa_BadConfigurationError;
		return uaserver;
	};

	IntrusivePtr_t<String_t> applicationURI = new SafeRefCount_t<String_t>();
	if (!applicationURI.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	result = applicationURI->CopyFrom(*(*serverArray)[0]);
	if (result.IsBad()) return uaserver;

	IntrusivePtr_t<BuildInfo_t> buildInfo = new SafeRefCount_t<BuildInfo_t>();
	if (!buildInfo.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	result = buildInfo->ProductName().CopyFrom("MultiSpectralDetectorControl");
	if (result.IsBad()) return uaserver;

	result = buildInfo->ProductUri().CopyFrom("http://www.mpsitech.com/msdc");
	if (result.IsBad()) return uaserver;

	IntrusivePtr_t<IServerConfiguration_t> configuration = UAServer_t::CreateConfiguration(result);
	if (!configuration.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	result = configuration->AddEndpointUserTokenPolicy(SECURITY_POLICY_NONE, MessageSecurityMode_t::OPCUA_MESSAGE_SECURITY_MODE_NONE, UserIdentityTokenType_t::OPCUA_USER_IDENTITY_TOKEN_TYPE_USERNAME, SECURITY_POLICY_NONE);
	if (result.IsBad()) return uaserver;

	IntrusivePtr_t<const IUserPermissionsProvider_t> userPermissionsProvider = new SafeRefCount_t<UserPermissionsProvider>();
	if (!userPermissionsProvider.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	IntrusivePtr_t<IServerStateListener_t> serverStateListener = new SafeRefCount_t<ServerStateListener>();
	if (!serverStateListener.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	configuration->ServerStateListener(serverStateListener);
	configuration->UserPermissionsProvider(userPermissionsProvider);
	configuration->ApplicationURI(applicationURI);
	configuration->BuildInfo(buildInfo);
	configuration->ServerEndpointTCPPort(xchg->stgmsdcuasrv.port);
	configuration->ServerCyclicRateInMs(xchg->stgmsdcuasrv.cycle);
	configuration->MaxBrowseRefsPerNode(xchg->stgmsdcuasrv.maxbrowse);
	configuration->MaxMonitoredItems(xchg->stgmsdcuasrv.maxmon);
	configuration->AddressSpace(addressSpace);

	// create the server instance
	uaserver = new SafeRefCount_t<UAServer_t>();
	if (!uaserver.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	result = uaserver->Initialise(configuration);
	return uaserver;
};

Status_t MsdccmbdUasrv::fillAddressSpace(
			IntrusivePtr_t<INodeMethodHandler_t>& methodHandler
			, IntrusivePtr_t<INodeValueAttributeReaderWriter_t>& readerWriter
			, IntrusivePtr_t<IAddressSpace_t> addressSpace
		) {
	Status_t status;

	NodeIdNumeric_t targetId(0, OpcUaId_ObjectsFolder);
	IntrusivePtr_t<IObjectNode_t> objectsFolder = addressSpace->FindObjectNode(targetId, status);

	IntrusivePtr_t<IObjectNode_t> jobFolder;

	vector<string> srefsParsInv;
	vector<uint32_t> opcUaIdsParsInv;
	vector<string> srefsParsRet;
	vector<uint32_t> opcUaIdsParsRet;

	vector<string> srefsSubvars;
	vector<uint> icsVVartypeSubvars;

	fAS_addJobFolder(VecMsdcVJob::JOBMSDCACQADXL, addressSpace, objectsFolder, jobFolder);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "alpha"; icsVVartypeSubvars[0] = VecVVartype::FLOAT;
	srefsSubvars[1] = "beta"; icsVVartypeSubvars[1] = VecVVartype::FLOAT;

	fAS_addVar(VecMsdcVJob::JOBMSDCACQADXL, VecMsdcVFeatgroup::VECVJOBMSDCACQADXLVAR , "alphaBeta", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecMsdcVJob::JOBMSDCACQLWIR, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "ixMsdcVSqrgrp"; opcUaIdsParsInv[0] = OpcUaId_String;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQLWIR, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD , "setOutput", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQLWIR, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD , "start", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQLWIR, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRMETHOD , "stop", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(3); icsVVartypeSubvars.resize(3);
	srefsSubvars[0] = "seqno"; icsVVartypeSubvars[0] = VecVVartype::UINT;
	srefsSubvars[1] = "t"; icsVVartypeSubvars[1] = VecVVartype::DOUBLE;
	srefsSubvars[2] = "gray16"; icsVVartypeSubvars[2] = VecVVartype::USMALLINTVEC;

	fAS_addVar(VecMsdcVJob::JOBMSDCACQLWIR, VecMsdcVFeatgroup::VECVJOBMSDCACQLWIRVAR , "seqnoTGray16", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecMsdcVJob::JOBMSDCACQVISL, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "focus"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQVISL, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD , "setFocus", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(3); opcUaIdsParsInv.resize(3);
	srefsParsInv[0] = "ixMsdcVCamres"; opcUaIdsParsInv[0] = OpcUaId_String;
	srefsParsInv[1] = "ixMsdcVSqrgrp"; opcUaIdsParsInv[1] = OpcUaId_String;
	srefsParsInv[2] = "grayscale"; opcUaIdsParsInv[2] = OpcUaId_Boolean;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQVISL, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD , "setOutput", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "Tint"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQVISL, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD , "setTint", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQVISL, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD , "start", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQVISL, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLMETHOD , "stop", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(4); icsVVartypeSubvars.resize(4);
	srefsSubvars[0] = "seqno"; icsVVartypeSubvars[0] = VecVVartype::UINT;
	srefsSubvars[1] = "t"; icsVVartypeSubvars[1] = VecVVartype::DOUBLE;
	srefsSubvars[2] = "rgbx8"; icsVVartypeSubvars[2] = VecVVartype::UTINYINTVEC;
	srefsSubvars[3] = "gray8"; icsVVartypeSubvars[3] = VecVVartype::UTINYINTVEC;

	fAS_addVar(VecMsdcVJob::JOBMSDCACQVISL, VecMsdcVFeatgroup::VECVJOBMSDCACQVISLVAR , "seqnoTRgbx8Gray8", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecMsdcVJob::JOBMSDCACQVISR, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "focus"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQVISR, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD , "setFocus", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(3); opcUaIdsParsInv.resize(3);
	srefsParsInv[0] = "ixMsdcVCamres"; opcUaIdsParsInv[0] = OpcUaId_String;
	srefsParsInv[1] = "ixMsdcVSqrgrp"; opcUaIdsParsInv[1] = OpcUaId_String;
	srefsParsInv[2] = "grayscale"; opcUaIdsParsInv[2] = OpcUaId_Boolean;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQVISR, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD , "setOutput", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "Tint"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQVISR, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD , "setTint", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQVISR, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD , "start", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACQVISR, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRMETHOD , "stop", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(4); icsVVartypeSubvars.resize(4);
	srefsSubvars[0] = "seqno"; icsVVartypeSubvars[0] = VecVVartype::UINT;
	srefsSubvars[1] = "t"; icsVVartypeSubvars[1] = VecVVartype::DOUBLE;
	srefsSubvars[2] = "rgbx8"; icsVVartypeSubvars[2] = VecVVartype::UTINYINTVEC;
	srefsSubvars[3] = "gray8"; icsVVartypeSubvars[3] = VecVVartype::UTINYINTVEC;

	fAS_addVar(VecMsdcVJob::JOBMSDCACQVISR, VecMsdcVFeatgroup::VECVJOBMSDCACQVISRVAR , "seqnoTRgbx8Gray8", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecMsdcVJob::JOBMSDCACTALIGN, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(3); opcUaIdsParsInv.resize(3);
	srefsParsInv[0] = "ixVFunction"; opcUaIdsParsInv[0] = OpcUaId_String;
	srefsParsInv[1] = "N"; opcUaIdsParsInv[1] = OpcUaId_Byte;
	srefsParsInv[2] = "seq"; opcUaIdsParsInv[2] = OpcUaId_ByteString;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACTALIGN, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD , "setWave", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACTALIGN, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD , "start", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACTALIGN, VecMsdcVFeatgroup::VECVJOBMSDCACTALIGNMETHOD , "stop", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	fAS_addJobFolder(VecMsdcVJob::JOBMSDCACTLED, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "flood"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACTLED, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD , "setFlood", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "spot"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACTLED, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDMETHOD , "setSpot", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "flood"; icsVVartypeSubvars[0] = VecVVartype::FLOAT;
	srefsSubvars[1] = "spot"; icsVVartypeSubvars[1] = VecVVartype::FLOAT;

	fAS_addVar(VecMsdcVJob::JOBMSDCACTLED, VecMsdcVFeatgroup::VECVJOBMSDCACTLEDVAR , "floodSpot", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecMsdcVJob::JOBMSDCACTSERVO, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "phi"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACTSERVO, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD , "setPhi", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "theta"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecMsdcVJob::JOBMSDCACTSERVO, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOMETHOD , "setTheta", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "theta"; icsVVartypeSubvars[0] = VecVVartype::FLOAT;
	srefsSubvars[1] = "phi"; icsVVartypeSubvars[1] = VecVVartype::FLOAT;

	fAS_addVar(VecMsdcVJob::JOBMSDCACTSERVO, VecMsdcVFeatgroup::VECVJOBMSDCACTSERVOVAR , "thetaPhi", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	return status;
};

Status_t MsdccmbdUasrv::fAS_addJobFolder(
			const uint ixMsdcVJob
			, IntrusivePtr_t<IAddressSpace_t>& addressSpace
			, IntrusivePtr_t<IObjectNode_t>& objectsFolder
			, IntrusivePtr_t<IObjectNode_t>& jobFolder
		) {
	Status_t status;

	uint32_t nref = nrefseq.getNewRef();

	IntrusivePtr_t<String_t> browseNameString = new SafeRefCount_t<String_t>();
	browseNameString->CopyFrom(VecMsdcVJob::getSref(ixMsdcVJob).c_str());

	IntrusivePtr_t<Folder_t> folderObject = Folder_t::CreateWithNumericId(1, nref, addressSpace, *browseNameString, status);
	folderObject->Hide(false);

	jobFolder = folderObject->GetObjectNode();

	jobs[nref] = ixMsdcVJob;

	return AddressSpaceUtilities_t::CreateReference(*addressSpace, objectsFolder, jobFolder, OpcUaId_Organizes);
};

Status_t MsdccmbdUasrv::fAS_addVar(
			const uint ixMsdcVJob
			, const uint ixMsdcVFeatgroup
			, const string& srefIxVVar
			, IntrusivePtr_t<INodeValueAttributeReaderWriter_t>& readerWriter
			, IntrusivePtr_t<IAddressSpace_t>& addressSpace
			, IntrusivePtr_t<IObjectNode_t>& jobFolder
			, vector<string>& srefsSubvars
			, vector<uint>& icsVVartypeSubvars
		) {
	Status_t status;

	IntrusivePtr_t<BaseDataVariable_t> subvarObject;
	IntrusivePtr_t<IVariableNode_t> subvarNode;

	// variable folder
	uint32_t nref = nrefseq.getNewRef();

	IntrusivePtr_t<String_t> browseNameString = new SafeRefCount_t<String_t>();
	browseNameString->CopyFrom(srefIxVVar.c_str());

	IntrusivePtr_t<Folder_t> folderObject = Folder_t::CreateWithNumericId(1, nref, addressSpace, *browseNameString, status);
	folderObject->Hide(false);

	IntrusivePtr_t<IObjectNode_t> varFolder = folderObject->GetObjectNode();

	vars[nref] = featix_t(ixMsdcVFeatgroup, srefIxVVar);

	status = AddressSpaceUtilities_t::CreateReference(*addressSpace, jobFolder, varFolder, OpcUaId_Organizes);

	// sub-variables
	for (unsigned int i=0;i<srefsSubvars.size();i++) {
		nref = nrefseq.getNewRef();

		browseNameString = new SafeRefCount_t<String_t>();
		browseNameString->CopyFrom(srefsSubvars[i].c_str());

		status = fAS_addSubvar(icsVVartypeSubvars[i], nref, addressSpace, browseNameString, subvarObject);

		if (!subvarObject.is_set()) continue;

		subvarNode = subvarObject->GetVariableNode();

		status = subvarNode->ValueAttributeReaderWriter(readerWriter);

		subvarObject->Hide(false);

		subvarsVars[nref] = featix_t(ixMsdcVFeatgroup, srefIxVVar);
		subvars[nref] = srefsSubvars[i];

		status = AddressSpaceUtilities_t::CreateReference(*addressSpace, varFolder, subvarNode, OpcUaId_HasComponent);
	};

	return OpcUa_Good;
};

Status_t MsdccmbdUasrv::fAS_addSubvar(
			const uint ixVVartype
			, const uint32_t nref
			, IntrusivePtr_t<IAddressSpace_t>& addressSpace
			, IntrusivePtr_t<String_t>& browseNameString
			, IntrusivePtr_t<BaseDataVariable_t>& subvarObject
		) {
	Status_t status;

	subvarObject.reset();

	if (ixVVartype == VecVVartype::BOOLEAN) subvarObject = BaseDataVariable_t::CreateWithNumericId<Boolean_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::TINYINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<SByte_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UTINYINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<Byte_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::SMALLINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<Int16_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::USMALLINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<UInt16_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::INT) subvarObject = BaseDataVariable_t::CreateWithNumericId<Int32_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<UInt32_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::BIGINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<Int64_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UBIGINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<UInt64_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::FLOAT) subvarObject = BaseDataVariable_t::CreateWithNumericId<Float_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::DOUBLE) subvarObject = BaseDataVariable_t::CreateWithNumericId<Double_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::STRING) subvarObject = BaseDataVariable_t::CreateWithNumericId<String_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UTINYINTVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<Byte_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::USMALLINTVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<UInt16_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::INTVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<Int32_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UINTVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<UInt32_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UBIGINTVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<UInt64_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::FLOATVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<Float_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::DOUBLEVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<Double_t> >(1, nref, addressSpace, *browseNameString, status);
	//else if (ixVVartype == VecVVartype::FLOATMAT);
	//else if (ixVVartype == VecVVartype::DOUBLEMAT):
	else if (ixVVartype == VecVVartype::STRINGVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<String_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::VECSREF) subvarObject = BaseDataVariable_t::CreateWithNumericId<String_t>(1, nref, addressSpace, *browseNameString, status);

	return status;
};

Status_t MsdccmbdUasrv::fAS_addMethod(
			const uint ixMsdcVJob
			, const uint ixMsdcVFeatgroup
			, const string& srefIxVMethod
			, IntrusivePtr_t<INodeMethodHandler_t>& methodHandler
			, IntrusivePtr_t<IAddressSpace_t>& addressSpace
			, IntrusivePtr_t<IObjectNode_t>& jobFolder
			, vector<string>& srefsParsInv
			, vector<uint32_t>& opcUaIdsParsInv
			, vector<string>& srefsParsRet
			, vector<uint32_t>& opcUaIdsParsRet
		) {
	Status_t status;

	ArrayUA_t<Argument_t> args;
	IntrusivePtr_t<Argument_t> arg;

	uint32_t nref = nrefseq.getNewRef();

	IntrusivePtr_t<String_t> browseNameString = new SafeRefCount_t<String_t>();
	browseNameString->CopyFrom(srefIxVMethod.c_str());

	IntrusivePtr_t<Method_t> methodObject = Method_t::CreateWithNumericId(1, nref, addressSpace, *browseNameString, true, status);

	// invocation parameters
	status = args.Initialise(srefsParsInv.size());
	for (unsigned int i=0;i<srefsParsInv.size();i++) {
		status = methodObject->CreateArgument(srefsParsInv[i].c_str(), opcUaIdsParsInv[i], -1, arg);
		args[i] = arg;
	};

	status = methodObject->CreateInputArguments(nrefseq.getNewRef(), args);

	// return parameters
	status = args.Initialise(srefsParsRet.size());
	for (unsigned int i=0;i<srefsParsRet.size();i++) {
		status = methodObject->CreateArgument(srefsParsRet[i].c_str(), opcUaIdsParsRet[i], -1, arg);
		args[i] = arg;
	};

	status = methodObject->CreateOutputArguments(nrefseq.getNewRef(), args);

	IntrusivePtr_t<IMethodNode_t> methodNode = methodObject->GetMethodNode();

	status = methodNode->SetMethodHandler(methodHandler);

	methodObject->Hide(false);

	methods[nref] = featix_t(ixMsdcVFeatgroup, srefIxVMethod);

	return AddressSpaceUtilities_t::CreateReference(*addressSpace, jobFolder, methodNode, OpcUaId_HasComponent);
};

void MsdccmbdUasrv::runMethod(
			const ubigint jref
			, const uint ixMsdcVFeatgroup
			, const string& srefIxVMethod
			, const vector<const void*>& parsInv
			, const vector<void*>& parsRet
		) {
	ReqMsdc* req = new ReqMsdc(ReqMsdc::VecVBasetype::METHOD, ReqMsdc::VecVState::RECEIVE, "127.0.0.1");

	req->jref = jref;

	req->method = new Method(ixMsdcVFeatgroup, srefIxVMethod);
	req->method->parsInv = parsInv;
	req->method->parsRet = parsRet;

	xchg->addReq(req);

	Mutex::lock(&(req->mcReady), "req->mcReady", "MsdccmbdUasrv", "runMethod");
	if (req->ixVState != ReqMsdc::VecVState::REPLY) Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "MsdccmbdUasrv", "runMethod");
	Mutex::unlock(&(req->mcReady), "req->mcReady", "MsdccmbdUasrv", "runMethod");

	delete req;
};

XchgMsdccmbd* MsdccmbdUasrv::xchg;
IntrusivePtr_t<UAServer_t> MsdccmbdUasrv::uaserver;
bool MsdccmbdUasrv::serverHasFailed;
Refseq MsdccmbdUasrv::nrefseq;
map<uint32_t,IntrusivePtr_t<MsdccmbdUasrv::Session> > MsdccmbdUasrv::sessions;
map<ubigint,uint> MsdccmbdUasrv::ixVFeatgroups;
map<featix_t,DateTime_t> MsdccmbdUasrv::timestamps;
map<uint32_t,uint> MsdccmbdUasrv::jobs;
map<uint32_t,featix_t> MsdccmbdUasrv::methods;
map<uint32_t,featix_t> MsdccmbdUasrv::vars;
map<uint32_t,featix_t> MsdccmbdUasrv::subvarsVars;
map<uint32_t,string> MsdccmbdUasrv::subvars;

