/**
  * \file VecMsdcVCamres.java
  * vector VecMsdcVCamres
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

public class VecMsdcVCamres {
	public static final int OFF = 1;
	public static final int _160 = 2;
	public static final int _320 = 3;
	public static final int _640 = 4;
	public static final int _800 = 5;
	public static final int _1024 = 6;
	public static final int _1280 = 7;
	public static final int _720P = 8;
	public static final int _1080P = 9;
	public static final int MAX = 10;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("off")) return OFF;
		if (s.equals("_160")) return _160;
		if (s.equals("_320")) return _320;
		if (s.equals("_640")) return _640;
		if (s.equals("_800")) return _800;
		if (s.equals("_1024")) return _1024;
		if (s.equals("_1280")) return _1280;
		if (s.equals("_720p")) return _720P;
		if (s.equals("_1080p")) return _1080P;
		if (s.equals("max")) return MAX;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == OFF) return("off");
		if (ix == _160) return("_160");
		if (ix == _320) return("_320");
		if (ix == _640) return("_640");
		if (ix == _800) return("_800");
		if (ix == _1024) return("_1024");
		if (ix == _1280) return("_1280");
		if (ix == _720P) return("_720p");
		if (ix == _1080P) return("_1080p");
		if (ix == MAX) return("max");

		return "";
	};

};

