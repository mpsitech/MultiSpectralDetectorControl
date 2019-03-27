/**
  * \file VecMsdcVSqrgrp.java
  * vector VecMsdcVSqrgrp
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

public class VecMsdcVSqrgrp {
	public static final int R0 = 1;
	public static final int R1 = 2;
	public static final int R2 = 3;
	public static final int R3 = 4;
	public static final int S0 = 5;
	public static final int S1 = 6;
	public static final int S2 = 7;
	public static final int S3 = 8;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("r0")) return R0;
		if (s.equals("r1")) return R1;
		if (s.equals("r2")) return R2;
		if (s.equals("r3")) return R3;
		if (s.equals("s0")) return S0;
		if (s.equals("s1")) return S1;
		if (s.equals("s2")) return S2;
		if (s.equals("s3")) return S3;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == R0) return("r0");
		if (ix == R1) return("r1");
		if (ix == R2) return("r2");
		if (ix == R3) return("r3");
		if (ix == S0) return("s0");
		if (ix == S1) return("s1");
		if (ix == S2) return("s2");
		if (ix == S3) return("s3");

		return "";
	};

};

