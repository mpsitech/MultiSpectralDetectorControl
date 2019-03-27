/**
  * \file VecMsdcVChannel.java
  * vector VecMsdcVChannel
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

public class VecMsdcVChannel {
	public static final int RED8 = 1;
	public static final int GREEN8 = 2;
	public static final int BLUE8 = 3;
	public static final int RGBX32 = 4;
	public static final int GRAY8 = 5;
	public static final int GRAY16 = 6;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("red8")) return RED8;
		if (s.equals("green8")) return GREEN8;
		if (s.equals("blue8")) return BLUE8;
		if (s.equals("rgbx32")) return RGBX32;
		if (s.equals("gray8")) return GRAY8;
		if (s.equals("gray16")) return GRAY16;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == RED8) return("red8");
		if (ix == GREEN8) return("green8");
		if (ix == BLUE8) return("blue8");
		if (ix == RGBX32) return("rgbx32");
		if (ix == GRAY8) return("gray8");
		if (ix == GRAY16) return("gray16");

		return "";
	};

};

