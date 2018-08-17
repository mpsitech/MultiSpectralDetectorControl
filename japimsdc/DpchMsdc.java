/**
  * \file DpchMsdc.java
  * Msdc Java API package dispatch block
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

package apimsdc;

import sbecore.*;

public class DpchMsdc extends Block {

	public DpchMsdc(
				int ixMsdcVDpch
			) {
		this.ixMsdcVDpch = ixMsdcVDpch;
	};

	public int ixMsdcVDpch;
};

