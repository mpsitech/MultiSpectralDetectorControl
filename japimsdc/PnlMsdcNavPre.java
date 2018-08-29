/**
  * \file PnlMsdcNavPre.java
  * Java API code for job PnlMsdcNavPre
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcNavPre {
	/**
		* VecVDo (full: VecVMsdcNavPreDo)
		*/
	public static class VecVDo {

		public static final int BUTDATREMOVECLICK = 1;
		public static final int BUTPRDREMOVECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butdatremoveclick")) return BUTDATREMOVECLICK;
			if (s.equals("butprdremoveclick")) return BUTPRDREMOVECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTDATREMOVECLICK) return("ButDatRemoveClick");
			if (ix == BUTPRDREMOVECLICK) return("ButPrdRemoveClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfMsdcNavPre)
	  */
	public class ContInf extends Block {

		public static final int TXTDAT = 1;
		public static final int TXTPRD = 2;

		public ContInf(
					String TxtDat
					, String TxtPrd
				) {
			this.TxtDat = TxtDat;
			this.TxtPrd = TxtPrd;

			mask = new HashSet<Integer>(Arrays.asList(TXTDAT, TXTPRD));
		};

		public String TxtDat;
		public String TxtPrd;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcNavPre");

			String itemtag = "ContitemInfMsdcNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtDat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtDat", mask, TXTDAT);
				TxtPrd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrd", mask, TXTPRD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtDat.equals(comp.TxtDat)) items.add(TXTDAT);
			if (TxtPrd.equals(comp.TxtPrd)) items.add(TXTPRD);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTDAT, TXTPRD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrMsdcNavPre)
	  */
	public class StatShr extends Block {

		public static final int TXTDATAVAIL = 1;
		public static final int TXTPRDAVAIL = 2;

		public StatShr(
					boolean TxtDatAvail
					, boolean TxtPrdAvail
				) {
			this.TxtDatAvail = TxtDatAvail;
			this.TxtPrdAvail = TxtPrdAvail;

			mask = new HashSet<Integer>(Arrays.asList(TXTDATAVAIL, TXTPRDAVAIL));
		};

		public boolean TxtDatAvail;
		public boolean TxtPrdAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcNavPre");

			String itemtag = "StatitemShrMsdcNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtDatAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtDatAvail", mask, TXTDATAVAIL);
				TxtPrdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPrdAvail", mask, TXTPRDAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtDatAvail == comp.TxtDatAvail) items.add(TXTDATAVAIL);
			if (TxtPrdAvail == comp.TxtPrdAvail) items.add(TXTPRDAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTDATAVAIL, TXTPRDAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcNavPre)
	  */
	public class Tag extends Block {

		public static final int CPTDAT = 1;
		public static final int CPTPRD = 2;

		public Tag(
					String CptDat
					, String CptPrd
				) {
			this.CptDat = CptDat;
			this.CptPrd = CptPrd;

			mask = new HashSet<Integer>(Arrays.asList(CPTDAT, CPTPRD));
		};

		public String CptDat;
		public String CptPrd;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcNavPre");

			String itemtag = "TagitemMsdcNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptDat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDat", mask, CPTDAT);
				CptPrd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrd", mask, CPTPRD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptDat.equals(comp.CptDat)) items.add(CPTDAT);
			if (CptPrd.equals(comp.CptPrd)) items.add(CPTPRD);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTDAT, CPTPRD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcNavPreDo)
		*/
	public class DpchAppDo extends DpchAppMsdc {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int ALL = 3;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, Integer[] mask
				) {
			super(VecMsdcVDpch.DPCHAPPMSDCNAVPREDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO));
					break;
				};

			this.ixVDo = ixVDo;
		};

		public int ixVDo;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppMsdcNavPreDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcNavPreData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATSHR = 3;
		public static final int TAG = 4;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCNAVPREDATA);

			continf = new ContInf("", "");
			statshr = new StatShr(false, false);
			tag = new Tag("", "");
		};

		public ContInf continf;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(STATSHR)) ss.add("statshr");
			if (has(TAG)) ss.add("tag");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcNavPreData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("", "");
				statshr = new StatShr(false, false);
				tag = new Tag("", "");
			};
		};

	};

};

