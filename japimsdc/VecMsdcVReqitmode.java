/**
  * \file VecMsdcVReqitmode.java
  * vector VecMsdcVReqitmode
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

public class VecMsdcVReqitmode {
	public static final int IDLE = 1;
	public static final int NOTIFY = 2;
	public static final int POLL = 3;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("idle")) return IDLE;
		if (s.equals("notify")) return NOTIFY;
		if (s.equals("poll")) return POLL;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == IDLE) return("idle");
		if (ix == NOTIFY) return("notify");
		if (ix == POLL) return("poll");

		return "";
	};

};

