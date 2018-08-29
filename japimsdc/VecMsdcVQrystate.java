/**
  * \file VecMsdcVQrystate.java
  * vector VecMsdcVQrystate
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

public class VecMsdcVQrystate {
	public static final int MNR = 1;
	public static final int OOD = 2;
	public static final int SLM = 3;
	public static final int UTD = 4;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("mnr")) return MNR;
		if (s.equals("ood")) return OOD;
		if (s.equals("slm")) return SLM;
		if (s.equals("utd")) return UTD;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == MNR) return("mnr");
		if (ix == OOD) return("ood");
		if (ix == SLM) return("slm");
		if (ix == UTD) return("utd");

		return "";
	};

};

