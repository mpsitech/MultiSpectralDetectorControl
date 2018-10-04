/**
  * \file MsdcQUsrList.h
  * Java API code for record of table TblMsdcQUsrList
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

package apimsdc;

import org.w3c.dom.*;
import sbecore.*;

public class MsdcQUsrList {
	
	public MsdcQUsrList(
				int jnum
				, String stubRefMsdcMPerson
				, String sref
				, String stubRefMsdcMUsergroup
				, String srefIxVState
				, String titIxVState
				, String srefIxMsdcVLocale
				, String titIxMsdcVLocale
				, String srefIxMsdcVUserlevel
				, String titIxMsdcVUserlevel
			) {
		this.jnum = jnum;
		this.stubRefMsdcMPerson = stubRefMsdcMPerson;
		this.sref = sref;
		this.stubRefMsdcMUsergroup = stubRefMsdcMUsergroup;
		this.srefIxVState = srefIxVState;
		this.titIxVState = titIxVState;
		this.srefIxMsdcVLocale = srefIxMsdcVLocale;
		this.titIxMsdcVLocale = titIxMsdcVLocale;
		this.srefIxMsdcVUserlevel = srefIxMsdcVUserlevel;
		this.titIxMsdcVUserlevel = titIxMsdcVUserlevel;
	};

	public int jnum;
	public String stubRefMsdcMPerson;
	public String sref;
	public String stubRefMsdcMUsergroup;
	public String srefIxVState;
	public String titIxVState;
	public String srefIxMsdcVLocale;
	public String titIxMsdcVLocale;
	public String srefIxMsdcVUserlevel;
	public String titIxMsdcVUserlevel;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "MsdcQUsrList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubRefMsdcMPerson = Xmlio.extractStringUclc(doc, basexpath, "stubRefMsdcMPerson", "prs", null, 0);
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefMsdcMUsergroup = Xmlio.extractStringUclc(doc, basexpath, "stubRefMsdcMUsergroup", "usg", null, 0);
			srefIxVState = Xmlio.extractStringUclc(doc, basexpath, "srefIxVState", "ste", null, 0);
			titIxVState = Xmlio.extractStringUclc(doc, basexpath, "titIxVState", "ste2", null, 0);
			srefIxMsdcVLocale = Xmlio.extractStringUclc(doc, basexpath, "srefIxMsdcVLocale", "lcl", null, 0);
			titIxMsdcVLocale = Xmlio.extractStringUclc(doc, basexpath, "titIxMsdcVLocale", "lcl2", null, 0);
			srefIxMsdcVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "srefIxMsdcVUserlevel", "ulv", null, 0);
			titIxMsdcVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "titIxMsdcVUserlevel", "ulv2", null, 0);
			
			return true;
		};

		return false;
	};
};

