/**
  * \file VecMsdcVCamtype.java
  * vector VecMsdcVCamtype
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

public class VecMsdcVCamtype {
	public static final int PGBFLY = 1;
	public static final int MSLIFE = 2;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("pgbfly")) return PGBFLY;
		if (s.equals("mslife")) return MSLIFE;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == PGBFLY) return("pgbfly");
		if (ix == MSLIFE) return("mslife");

		return "";
	};

};

