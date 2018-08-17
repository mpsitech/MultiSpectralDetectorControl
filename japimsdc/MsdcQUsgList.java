/**
  * \file MsdcQUsgList.h
  * Java API code for record of table TblMsdcQUsgList
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

package apimsdc;

import org.w3c.dom.*;
import sbecore.*;

public class MsdcQUsgList {
	
	public MsdcQUsgList(
				int jnum
				, String sref
			) {
		this.jnum = jnum;
		this.sref = sref;
	};

	public int jnum;
	public String sref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "MsdcQUsgList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			
			return true;
		};

		return false;
	};
};

