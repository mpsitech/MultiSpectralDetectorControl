/**
  * \file DpchAppMsdcResume.java
  * Msdc Java API package resume app dispatch block
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

package apimsdc;

public class DpchAppMsdcResume extends DpchAppMsdc {

	public DpchAppMsdcResume(
				String scrJref
			) {
		super(VecMsdcVDpch.DPCHAPPMSDCRESUME, scrJref);
	};
};

