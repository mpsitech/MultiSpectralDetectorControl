/**
  * \file DpchAppMsdcResume.java
  * Msdc Java API package resume app dispatch block
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

package apimsdc;

public class DpchAppMsdcResume extends DpchAppMsdc {

	public DpchAppMsdcResume(
				String scrJref
			) {
		super(VecMsdcVDpch.DPCHAPPMSDCRESUME, scrJref);
	};
};

