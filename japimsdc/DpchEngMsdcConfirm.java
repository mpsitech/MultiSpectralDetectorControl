/**
  * \file DpchEngMsdcConfirm.java
  * Msdc Java API package confirm engine dispatch block
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchEngMsdcConfirm extends DpchEngMsdc {

	public static final int ACCEPTED = 1;
	public static final int SCRJREF = 2;
	public static final int SREF = 3;

	public DpchEngMsdcConfirm() {
		super(VecMsdcVDpch.DPCHENGMSDCCONFIRM);

		accepted = false;
		scrJref = new String();
		sref = new String();
	};

	public boolean accepted;
	public String sref;

	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(ACCEPTED)) return false;
		if (!items.contains(SCRJREF)) return false;
		if (!items.contains(SREF)) return false;
	
		return true;
	};

	public String getSrefsMask() {
		ArrayList<String> ss = new ArrayList<String>();
	
		if (has(ACCEPTED)) ss.add("accepted");
		if (has(SCRJREF)) ss.add("scrJref");
		if (has(SREF)) ss.add("sref");
	
		return StrMod.vectorToString(ss, ';');
	};
	
	public void readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		clear();

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcConfirm");
	
		if (Xmlio.checkXPath(doc, basexpath)) {
			accepted = Xmlio.extractBooleanUclc(doc, basexpath, "accepted", "", mask, ACCEPTED);
			scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "", mask, SREF);
		} else {
		};
	};
};

