/**
  * \file VecMsdcVCamste.java
  * vector VecMsdcVCamste
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

public class VecMsdcVCamste {
	public static final int NC = 1;
	public static final int READY = 2;
	public static final int ACTIVE = 3;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("nc")) return NC;
		if (s.equals("ready")) return READY;
		if (s.equals("active")) return ACTIVE;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == NC) return("nc");
		if (ix == READY) return("ready");
		if (ix == ACTIVE) return("active");

		return "";
	};

};

