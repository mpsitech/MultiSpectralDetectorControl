/**
  * \file MsdccmbdOpprc.h
  * operation processor for Msdc combined daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

#ifndef MSDCCMBDOPPRC_H
#define MSDCCMBDOPPRC_H

/**
  * MsdccmbdOpprc
  */
namespace MsdccmbdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif

