/**
  * \file DpchEngMsdc.java
  * Msdc Java API package engine dispatch block
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchEngMsdc extends DpchMsdc {

	public static final int SCRJREF = 1;
	
	public DpchEngMsdc(
				int ixMsdcVDpch
			) {
		super(ixMsdcVDpch);
		
		scrJref = new String();
	};

	public String scrJref;
	
	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(SCRJREF)) return false;

		return true;
	};
	
	public String getSrefsMask() {
		if (has(SCRJREF)) return("scrJref");
		
		return "";
	};
	
	public void readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		clear();
		
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, VecMsdcVDpch.getSref(ixMsdcVDpch));

		if (Xmlio.checkXPath(doc, basexpath)) {
			scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
		};
	};
};

