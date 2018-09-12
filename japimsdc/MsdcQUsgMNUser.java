/**
  * \file MsdcQUsgMNUser.h
  * Java API code for record of table TblMsdcQUsgMNUser
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

package apimsdc;

import org.w3c.dom.*;
import sbecore.*;

public class MsdcQUsgMNUser {
	
	public MsdcQUsgMNUser(
				int jnum
				, String stubMref
				, String srefIxMsdcVUserlevel
				, String titIxMsdcVUserlevel
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.srefIxMsdcVUserlevel = srefIxMsdcVUserlevel;
		this.titIxMsdcVUserlevel = titIxMsdcVUserlevel;
	};

	public int jnum;
	public String stubMref;
	public String srefIxMsdcVUserlevel;
	public String titIxMsdcVUserlevel;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "MsdcQUsgMNUser");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			srefIxMsdcVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "srefIxMsdcVUserlevel", "ulv", null, 0);
			titIxMsdcVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "titIxMsdcVUserlevel", "ulv2", null, 0);
			
			return true;
		};

		return false;
	};
};

