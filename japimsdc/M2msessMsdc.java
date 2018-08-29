/**
  * \file M2msessMsdc.java
  * Java API code for job M2msessMsdc
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class M2msessMsdc {
	/**
	  * StatShr (full: StatShrM2msessMsdc)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFACQADXL = 1;
		public static final int SCRJREFACQLWIR = 2;
		public static final int SCRJREFACQVISL = 3;
		public static final int SCRJREFACQVISR = 4;
		public static final int SCRJREFACTALIGN = 5;
		public static final int SCRJREFACTLED = 6;
		public static final int SCRJREFACTSERVO = 7;
		public static final int SCRJREFPRCSTEREO = 8;

		public StatShr(
					String scrJrefAcqadxl
					, String scrJrefAcqlwir
					, String scrJrefAcqvisl
					, String scrJrefAcqvisr
					, String scrJrefActalign
					, String scrJrefActled
					, String scrJrefActservo
					, String scrJrefPrcstereo
				) {
			this.scrJrefAcqadxl = scrJrefAcqadxl;
			this.scrJrefAcqlwir = scrJrefAcqlwir;
			this.scrJrefAcqvisl = scrJrefAcqvisl;
			this.scrJrefAcqvisr = scrJrefAcqvisr;
			this.scrJrefActalign = scrJrefActalign;
			this.scrJrefActled = scrJrefActled;
			this.scrJrefActservo = scrJrefActservo;
			this.scrJrefPrcstereo = scrJrefPrcstereo;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFACQADXL, SCRJREFACQLWIR, SCRJREFACQVISL, SCRJREFACQVISR, SCRJREFACTALIGN, SCRJREFACTLED, SCRJREFACTSERVO, SCRJREFPRCSTEREO));
		};

		public String scrJrefAcqadxl;
		public String scrJrefAcqlwir;
		public String scrJrefAcqvisl;
		public String scrJrefAcqvisr;
		public String scrJrefActalign;
		public String scrJrefActled;
		public String scrJrefActservo;
		public String scrJrefPrcstereo;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrM2msessMsdc");

			String itemtag = "StatitemShrM2msessMsdc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefAcqadxl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAcqadxl", mask, SCRJREFACQADXL);
				scrJrefAcqlwir = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAcqlwir", mask, SCRJREFACQLWIR);
				scrJrefAcqvisl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAcqvisl", mask, SCRJREFACQVISL);
				scrJrefAcqvisr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAcqvisr", mask, SCRJREFACQVISR);
				scrJrefActalign = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefActalign", mask, SCRJREFACTALIGN);
				scrJrefActled = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefActled", mask, SCRJREFACTLED);
				scrJrefActservo = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefActservo", mask, SCRJREFACTSERVO);
				scrJrefPrcstereo = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefPrcstereo", mask, SCRJREFPRCSTEREO);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefAcqadxl.equals(comp.scrJrefAcqadxl)) items.add(SCRJREFACQADXL);
			if (scrJrefAcqlwir.equals(comp.scrJrefAcqlwir)) items.add(SCRJREFACQLWIR);
			if (scrJrefAcqvisl.equals(comp.scrJrefAcqvisl)) items.add(SCRJREFACQVISL);
			if (scrJrefAcqvisr.equals(comp.scrJrefAcqvisr)) items.add(SCRJREFACQVISR);
			if (scrJrefActalign.equals(comp.scrJrefActalign)) items.add(SCRJREFACTALIGN);
			if (scrJrefActled.equals(comp.scrJrefActled)) items.add(SCRJREFACTLED);
			if (scrJrefActservo.equals(comp.scrJrefActservo)) items.add(SCRJREFACTSERVO);
			if (scrJrefPrcstereo.equals(comp.scrJrefPrcstereo)) items.add(SCRJREFPRCSTEREO);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFACQADXL, SCRJREFACQLWIR, SCRJREFACQVISL, SCRJREFACQVISR, SCRJREFACTALIGN, SCRJREFACTLED, SCRJREFACTSERVO, SCRJREFPRCSTEREO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchEngData (full: DpchEngM2msessMsdcData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int STATSHR = 2;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGM2MSESSMSDCDATA);

			statshr = new StatShr("", "", "", "", "", "", "", "");
		};

		public StatShr statshr;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(STATSHR)) ss.add("statshr");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngM2msessMsdcData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
			} else {
				scrJref = "";
				statshr = new StatShr("", "", "", "", "", "", "", "");
			};
		};

	};

};

