/**
  * \file MsdccmbdJobprc.h
  * job processor for Msdc combined daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

#ifndef MSDCCMBDJOBPRC_H
#define MSDCCMBDJOBPRC_H

/**
  * MsdccmbdJobprc
  */
namespace MsdccmbdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgMsdccmbd* xchg, DbsMsdc* dbsmsdc, ReqMsdc* req);
};

#endif



