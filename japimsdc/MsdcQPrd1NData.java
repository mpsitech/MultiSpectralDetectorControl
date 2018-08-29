/**
  * \file MsdcQPrd1NData.h
  * Java API code for record of table TblMsdcQPrd1NData
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

import org.w3c.dom.*;
import sbecore.*;

public class MsdcQPrd1NData {
	
	public MsdcQPrd1NData(
				int jnum
				, String stubRef
			) {
		this.jnum = jnum;
		this.stubRef = stubRef;
	};

	public int jnum;
	public String stubRef;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "MsdcQPrd1NData");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubRef = Xmlio.extractStringUclc(doc, basexpath, "stubRef", "ref", null, 0);
			
			return true;
		};

		return false;
	};
};

