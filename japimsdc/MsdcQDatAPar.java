/**
  * \file MsdcQDatAPar.h
  * Java API code for record of table TblMsdcQDatAPar
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

package apimsdc;

import org.w3c.dom.*;
import sbecore.*;

public class MsdcQDatAPar {
	
	public MsdcQDatAPar(
				int jnum
				, String ftmX1Start
				, String x2SrefKKey
				, String titX2SrefKKey
				, String stubRefMsdcMFile
				, String Val
				, String Bindata
			) {
		this.jnum = jnum;
		this.ftmX1Start = ftmX1Start;
		this.x2SrefKKey = x2SrefKKey;
		this.titX2SrefKKey = titX2SrefKKey;
		this.stubRefMsdcMFile = stubRefMsdcMFile;
		this.Val = Val;
		this.Bindata = Bindata;
	};

	public int jnum;
	public String ftmX1Start;
	public String x2SrefKKey;
	public String titX2SrefKKey;
	public String stubRefMsdcMFile;
	public String Val;
	public String Bindata;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "MsdcQDatAPar");

		if (Xmlio.checkXPath(doc, basexpath)) {
			ftmX1Start = Xmlio.extractStringUclc(doc, basexpath, "ftmX1Start", "sta", null, 0);
			x2SrefKKey = Xmlio.extractStringUclc(doc, basexpath, "x2SrefKKey", "key", null, 0);
			titX2SrefKKey = Xmlio.extractStringUclc(doc, basexpath, "titX2SrefKKey", "key2", null, 0);
			stubRefMsdcMFile = Xmlio.extractStringUclc(doc, basexpath, "stubRefMsdcMFile", "fil", null, 0);
			Val = Xmlio.extractStringUclc(doc, basexpath, "Val", "val", null, 0);
			Bindata = Xmlio.extractStringUclc(doc, basexpath, "Bindata", "bin", null, 0);
			
			return true;
		};

		return false;
	};
};

