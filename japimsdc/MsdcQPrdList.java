/**
  * \file MsdcQPrdList.h
  * Java API code for record of table TblMsdcQPrdList
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

package apimsdc;

import org.w3c.dom.*;
import sbecore.*;

public class MsdcQPrdList {
	
	public MsdcQPrdList(
				int jnum
				, String ftmStart
				, String ftmStop
			) {
		this.jnum = jnum;
		this.ftmStart = ftmStart;
		this.ftmStop = ftmStop;
	};

	public int jnum;
	public String ftmStart;
	public String ftmStop;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "MsdcQPrdList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			ftmStart = Xmlio.extractStringUclc(doc, basexpath, "ftmStart", "sta", null, 0);
			ftmStop = Xmlio.extractStringUclc(doc, basexpath, "ftmStop", "sto", null, 0);
			
			return true;
		};

		return false;
	};
};

