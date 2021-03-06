/**
  * \file MsdcQPrsList.h
  * Java API code for record of table TblMsdcQPrsList
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import org.w3c.dom.*;
import sbecore.*;

public class MsdcQPrsList {
	
	public MsdcQPrsList(
				int jnum
				, String Title
				, String Firstname
				, String Lastname
				, String stubGrp
				, String stubOwn
				, String srefIxVSex
				, String titIxVSex
				, String telVal
				, String emlVal
			) {
		this.jnum = jnum;
		this.Title = Title;
		this.Firstname = Firstname;
		this.Lastname = Lastname;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.srefIxVSex = srefIxVSex;
		this.titIxVSex = titIxVSex;
		this.telVal = telVal;
		this.emlVal = emlVal;
	};

	public int jnum;
	public String Title;
	public String Firstname;
	public String Lastname;
	public String stubGrp;
	public String stubOwn;
	public String srefIxVSex;
	public String titIxVSex;
	public String telVal;
	public String emlVal;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "MsdcQPrsList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			Firstname = Xmlio.extractStringUclc(doc, basexpath, "Firstname", "fnm", null, 0);
			Lastname = Xmlio.extractStringUclc(doc, basexpath, "Lastname", "lnm", null, 0);
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			srefIxVSex = Xmlio.extractStringUclc(doc, basexpath, "srefIxVSex", "sex", null, 0);
			titIxVSex = Xmlio.extractStringUclc(doc, basexpath, "titIxVSex", "sex2", null, 0);
			telVal = Xmlio.extractStringUclc(doc, basexpath, "telVal", "tel", null, 0);
			emlVal = Xmlio.extractStringUclc(doc, basexpath, "emlVal", "eml", null, 0);
			
			return true;
		};

		return false;
	};
};

