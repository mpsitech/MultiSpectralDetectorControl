/**
  * \file StgMsdcapi.java
  * Msdc Java API package settings block
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class StgMsdcapi extends Block {

	public static final int ENGIP = 1;
	public static final int ENGPORT = 2;
	public static final int USERNAME = 3;
	public static final int PASSWORD = 3;

	public StgMsdcapi(
				String engip
				, int engport
				, String username
				, String password
			) {
		this.engip = engip;
		this.engport = engport;
		this.username = username;
		this.password = password;
		
		this.mask = new HashSet<Integer>(Arrays.asList(ENGIP, ENGPORT, USERNAME, PASSWORD));
	};
	
	public String engip;
	public int engport;
	public String username;
	public String password;
	
	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(ENGIP)) return false;
		if (!items.contains(ENGPORT)) return false;
		if (!items.contains(USERNAME)) return false;
		if (!items.contains(PASSWORD)) return false;

		return true;
	};

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		clear();

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgMsdcapi");

		String itemtag = "StgitemMsdcapi";
		
		if (Xmlio.checkXPath(doc, basexpath)) {
			engip = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "engip", mask, ENGIP);
			engport = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "engport", mask, ENGPORT);
			username = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "username", mask, USERNAME);
			password = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "password", mask, PASSWORD);
			
			return true;
		};
		
		return false;
	};
	
	public void writeXML(
				Document doc
				, Element sup
				, String difftag
				, boolean shorttags
			) {
		if (difftag.isEmpty()) difftag = "StgMsdcapi";
		
		String itemtag;
		
		if (shorttags) itemtag = "Si";
		else itemtag = "StgitemMsdcapi";

		Element el = doc.createElement(difftag);

		if (sup == null) doc.appendChild(el);
		else sup.appendChild(el);
		
		Xmlio.writeStringAttr(doc, el, itemtag, "sref", "engip", engip);
		Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "engport", engport);
		Xmlio.writeStringAttr(doc, el, itemtag, "sref", "username", username);
		Xmlio.writeStringAttr(doc, el, itemtag, "sref", "password", password);
	};
};

