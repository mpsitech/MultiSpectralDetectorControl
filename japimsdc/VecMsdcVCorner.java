/**
  * \file VecMsdcVCorner.java
  * vector VecMsdcVCorner
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

public class VecMsdcVCorner {
	public static final int N = 1;
	public static final int NE = 2;
	public static final int E = 3;
	public static final int SE = 4;
	public static final int S = 5;
	public static final int SW = 6;
	public static final int W = 7;
	public static final int NW = 8;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("n")) return N;
		if (s.equals("ne")) return NE;
		if (s.equals("e")) return E;
		if (s.equals("se")) return SE;
		if (s.equals("s")) return S;
		if (s.equals("sw")) return SW;
		if (s.equals("w")) return W;
		if (s.equals("nw")) return NW;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == N) return("n");
		if (ix == NE) return("ne");
		if (ix == E) return("e");
		if (ix == SE) return("se");
		if (ix == S) return("s");
		if (ix == SW) return("sw");
		if (ix == W) return("w");
		if (ix == NW) return("nw");

		return "";
	};

};

