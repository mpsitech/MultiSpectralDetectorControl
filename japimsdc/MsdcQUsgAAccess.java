/**
  * \file MsdcQUsgAAccess.h
  * Java API code for record of table TblMsdcQUsgAAccess
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

package apimsdc;

import org.w3c.dom.*;
import sbecore.*;

public class MsdcQUsgAAccess {
	
	public MsdcQUsgAAccess(
				int jnum
				, String srefX1IxMsdcVFeatgroup
				, String titX1IxMsdcVFeatgroup
				, String x2FeaSrefUix
				, String srefsIxMsdcWAccess
				, String titsIxMsdcWAccess
			) {
		this.jnum = jnum;
		this.srefX1IxMsdcVFeatgroup = srefX1IxMsdcVFeatgroup;
		this.titX1IxMsdcVFeatgroup = titX1IxMsdcVFeatgroup;
		this.x2FeaSrefUix = x2FeaSrefUix;
		this.srefsIxMsdcWAccess = srefsIxMsdcWAccess;
		this.titsIxMsdcWAccess = titsIxMsdcWAccess;
	};

	public int jnum;
	public String srefX1IxMsdcVFeatgroup;
	public String titX1IxMsdcVFeatgroup;
	public String x2FeaSrefUix;
	public String srefsIxMsdcWAccess;
	public String titsIxMsdcWAccess;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "MsdcQUsgAAccess");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefX1IxMsdcVFeatgroup = Xmlio.extractStringUclc(doc, basexpath, "srefX1IxMsdcVFeatgroup", "feg", null, 0);
			titX1IxMsdcVFeatgroup = Xmlio.extractStringUclc(doc, basexpath, "titX1IxMsdcVFeatgroup", "feg2", null, 0);
			x2FeaSrefUix = Xmlio.extractStringUclc(doc, basexpath, "x2FeaSrefUix", "fea", null, 0);
			srefsIxMsdcWAccess = Xmlio.extractStringUclc(doc, basexpath, "srefsIxMsdcWAccess", "acc", null, 0);
			titsIxMsdcWAccess = Xmlio.extractStringUclc(doc, basexpath, "titsIxMsdcWAccess", "acc2", null, 0);
			
			return true;
		};

		return false;
	};
};

