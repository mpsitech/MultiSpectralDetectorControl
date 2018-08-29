/**
  * \file DpchAppMsdc.java
  * Msdc Java API package app dispatch block
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchAppMsdc extends DpchMsdc {

	public static final int SCRJREF = 1;
	
	public DpchAppMsdc(
				int ixMsdcVDpch
				, String scrJref
			) {
		super(ixMsdcVDpch);
		
		this.scrJref = scrJref;
		
		mask = new HashSet<Integer>(Arrays.asList(SCRJREF));
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
	
	public void writeXML(
				Document doc
				, Element sup
			) {
		Element el = doc.createElement(VecMsdcVDpch.getSref(ixMsdcVDpch));

		if (sup == null) doc.appendChild(el);
		else sup.appendChild(el);

		el.setAttribute("xmlns", "http://www.mpsitech.com/msdc");
		
		if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
	};
};

