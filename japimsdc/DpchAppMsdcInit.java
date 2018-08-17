/**
  * \file DpchAppMsdcInit.java
  * Msdc Java API package init app dispatch block
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

package apimsdc;

public class DpchAppMsdcInit extends DpchAppMsdc {

	public DpchAppMsdcInit(
				String scrJref
			) {
		super(VecMsdcVDpch.DPCHAPPMSDCINIT, scrJref);
	};
};

