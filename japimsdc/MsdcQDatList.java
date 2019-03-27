/**
  * \file MsdcQDatList.h
  * Java API code for record of table TblMsdcQDatList
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import org.w3c.dom.*;
import sbecore.*;

public class MsdcQDatList {
	
	public MsdcQDatList(
				int jnum
				, String srefMsdcKAcqfeat
				, String titSrefMsdcKAcqfeat
				, String stubRefMsdcMPeriod
				, String ftmStart
				, String ftmStop
			) {
		this.jnum = jnum;
		this.srefMsdcKAcqfeat = srefMsdcKAcqfeat;
		this.titSrefMsdcKAcqfeat = titSrefMsdcKAcqfeat;
		this.stubRefMsdcMPeriod = stubRefMsdcMPeriod;
		this.ftmStart = ftmStart;
		this.ftmStop = ftmStop;
	};

	public int jnum;
	public String srefMsdcKAcqfeat;
	public String titSrefMsdcKAcqfeat;
	public String stubRefMsdcMPeriod;
	public String ftmStart;
	public String ftmStop;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "MsdcQDatList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefMsdcKAcqfeat = Xmlio.extractStringUclc(doc, basexpath, "srefMsdcKAcqfeat", "aft", null, 0);
			titSrefMsdcKAcqfeat = Xmlio.extractStringUclc(doc, basexpath, "titSrefMsdcKAcqfeat", "aft2", null, 0);
			stubRefMsdcMPeriod = Xmlio.extractStringUclc(doc, basexpath, "stubRefMsdcMPeriod", "prd", null, 0);
			ftmStart = Xmlio.extractStringUclc(doc, basexpath, "ftmStart", "sta", null, 0);
			ftmStop = Xmlio.extractStringUclc(doc, basexpath, "ftmStop", "sto", null, 0);
			
			return true;
		};

		return false;
	};
};

