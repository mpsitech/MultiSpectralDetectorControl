/**
  * \file PnlMsdcNavOpr.java
  * Java API code for job PnlMsdcNavOpr
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcNavOpr {
	/**
		* VecVDo (full: VecVMsdcNavOprDo)
		*/
	public static class VecVDo {

		public static final int BUTLIVNEWCRDCLICK = 1;
		public static final int BUTPRDVIEWCLICK = 2;
		public static final int BUTPRDNEWCRDCLICK = 3;
		public static final int BUTDATVIEWCLICK = 4;
		public static final int BUTDATNEWCRDCLICK = 5;
		public static final int BUTFILVIEWCLICK = 6;
		public static final int BUTFILNEWCRDCLICK = 7;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butlivnewcrdclick")) return BUTLIVNEWCRDCLICK;
			if (s.equals("butprdviewclick")) return BUTPRDVIEWCLICK;
			if (s.equals("butprdnewcrdclick")) return BUTPRDNEWCRDCLICK;
			if (s.equals("butdatviewclick")) return BUTDATVIEWCLICK;
			if (s.equals("butdatnewcrdclick")) return BUTDATNEWCRDCLICK;
			if (s.equals("butfilviewclick")) return BUTFILVIEWCLICK;
			if (s.equals("butfilnewcrdclick")) return BUTFILNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTLIVNEWCRDCLICK) return("ButLivNewcrdClick");
			if (ix == BUTPRDVIEWCLICK) return("ButPrdViewClick");
			if (ix == BUTPRDNEWCRDCLICK) return("ButPrdNewcrdClick");
			if (ix == BUTDATVIEWCLICK) return("ButDatViewClick");
			if (ix == BUTDATNEWCRDCLICK) return("ButDatNewcrdClick");
			if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
			if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacMsdcNavOpr)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTPRD = 1;
		public static final int NUMFLSTDAT = 2;
		public static final int NUMFLSTFIL = 3;

		public ContIac(
					int numFLstPrd
					, int numFLstDat
					, int numFLstFil
				) {
			this.numFLstPrd = numFLstPrd;
			this.numFLstDat = numFLstDat;
			this.numFLstFil = numFLstFil;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTPRD, NUMFLSTDAT, NUMFLSTFIL));
		};

		public int numFLstPrd;
		public int numFLstDat;
		public int numFLstFil;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacMsdcNavOpr");

			String itemtag = "ContitemIacMsdcNavOpr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstPrd = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPrd", mask, NUMFLSTPRD);
				numFLstDat = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstDat", mask, NUMFLSTDAT);
				numFLstFil = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstFil", mask, NUMFLSTFIL);

				return true;
			};

			return false;
		};

		public void writeXML(
					Document doc
					, Element sup
					, String difftag
					, boolean shorttags
				) {
			if (difftag.isEmpty()) difftag = "ContIacMsdcNavOpr";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacMsdcNavOpr";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPrd", numFLstPrd);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstDat", numFLstDat);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstFil", numFLstFil);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstPrd == comp.numFLstPrd) items.add(NUMFLSTPRD);
			if (numFLstDat == comp.numFLstDat) items.add(NUMFLSTDAT);
			if (numFLstFil == comp.numFLstFil) items.add(NUMFLSTFIL);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTPRD, NUMFLSTDAT, NUMFLSTFIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppMsdcNavOpr)
	  */
	public class StatApp extends Block {

		public static final int IXMSDCVEXPSTATE = 1;
		public static final int LSTPRDALT = 2;
		public static final int LSTDATALT = 3;
		public static final int LSTFILALT = 4;
		public static final int LSTPRDNUMFIRSTDISP = 5;
		public static final int LSTDATNUMFIRSTDISP = 6;
		public static final int LSTFILNUMFIRSTDISP = 7;

		public StatApp(
					int ixMsdcVExpstate
					, boolean LstPrdAlt
					, boolean LstDatAlt
					, boolean LstFilAlt
					, int LstPrdNumFirstdisp
					, int LstDatNumFirstdisp
					, int LstFilNumFirstdisp
				) {
			this.ixMsdcVExpstate = ixMsdcVExpstate;
			this.LstPrdAlt = LstPrdAlt;
			this.LstDatAlt = LstDatAlt;
			this.LstFilAlt = LstFilAlt;
			this.LstPrdNumFirstdisp = LstPrdNumFirstdisp;
			this.LstDatNumFirstdisp = LstDatNumFirstdisp;
			this.LstFilNumFirstdisp = LstFilNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE, LSTPRDALT, LSTDATALT, LSTFILALT, LSTPRDNUMFIRSTDISP, LSTDATNUMFIRSTDISP, LSTFILNUMFIRSTDISP));
		};

		public int ixMsdcVExpstate;
		public boolean LstPrdAlt;
		public boolean LstDatAlt;
		public boolean LstFilAlt;
		public int LstPrdNumFirstdisp;
		public int LstDatNumFirstdisp;
		public int LstFilNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxMsdcVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcNavOpr");

			String itemtag = "StatitemAppMsdcNavOpr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxMsdcVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", mask, IXMSDCVEXPSTATE);
				ixMsdcVExpstate = VecMsdcVExpstate.getIx(srefIxMsdcVExpstate);
				LstPrdAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrdAlt", mask, LSTPRDALT);
				LstDatAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDatAlt", mask, LSTDATALT);
				LstFilAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFilAlt", mask, LSTFILALT);
				LstPrdNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrdNumFirstdisp", mask, LSTPRDNUMFIRSTDISP);
				LstDatNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDatNumFirstdisp", mask, LSTDATNUMFIRSTDISP);
				LstFilNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFilNumFirstdisp", mask, LSTFILNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixMsdcVExpstate == comp.ixMsdcVExpstate) items.add(IXMSDCVEXPSTATE);
			if (LstPrdAlt == comp.LstPrdAlt) items.add(LSTPRDALT);
			if (LstDatAlt == comp.LstDatAlt) items.add(LSTDATALT);
			if (LstFilAlt == comp.LstFilAlt) items.add(LSTFILALT);
			if (LstPrdNumFirstdisp == comp.LstPrdNumFirstdisp) items.add(LSTPRDNUMFIRSTDISP);
			if (LstDatNumFirstdisp == comp.LstDatNumFirstdisp) items.add(LSTDATNUMFIRSTDISP);
			if (LstFilNumFirstdisp == comp.LstFilNumFirstdisp) items.add(LSTFILNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE, LSTPRDALT, LSTDATALT, LSTFILALT, LSTPRDNUMFIRSTDISP, LSTDATNUMFIRSTDISP, LSTFILNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrMsdcNavOpr)
	  */
	public class StatShr extends Block {

		public static final int BUTLIVNEWCRDAVAIL = 1;
		public static final int LSTPRDAVAIL = 2;
		public static final int BUTPRDVIEWACTIVE = 3;
		public static final int LSTDATAVAIL = 4;
		public static final int BUTDATVIEWACTIVE = 5;
		public static final int BUTDATNEWCRDACTIVE = 6;
		public static final int LSTFILAVAIL = 7;
		public static final int BUTFILVIEWACTIVE = 8;
		public static final int BUTFILNEWCRDACTIVE = 9;

		public StatShr(
					boolean ButLivNewcrdAvail
					, boolean LstPrdAvail
					, boolean ButPrdViewActive
					, boolean LstDatAvail
					, boolean ButDatViewActive
					, boolean ButDatNewcrdActive
					, boolean LstFilAvail
					, boolean ButFilViewActive
					, boolean ButFilNewcrdActive
				) {
			this.ButLivNewcrdAvail = ButLivNewcrdAvail;
			this.LstPrdAvail = LstPrdAvail;
			this.ButPrdViewActive = ButPrdViewActive;
			this.LstDatAvail = LstDatAvail;
			this.ButDatViewActive = ButDatViewActive;
			this.ButDatNewcrdActive = ButDatNewcrdActive;
			this.LstFilAvail = LstFilAvail;
			this.ButFilViewActive = ButFilViewActive;
			this.ButFilNewcrdActive = ButFilNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTLIVNEWCRDAVAIL, LSTPRDAVAIL, BUTPRDVIEWACTIVE, LSTDATAVAIL, BUTDATVIEWACTIVE, BUTDATNEWCRDACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE, BUTFILNEWCRDACTIVE));
		};

		public boolean ButLivNewcrdAvail;
		public boolean LstPrdAvail;
		public boolean ButPrdViewActive;
		public boolean LstDatAvail;
		public boolean ButDatViewActive;
		public boolean ButDatNewcrdActive;
		public boolean LstFilAvail;
		public boolean ButFilViewActive;
		public boolean ButFilNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcNavOpr");

			String itemtag = "StatitemShrMsdcNavOpr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButLivNewcrdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButLivNewcrdAvail", mask, BUTLIVNEWCRDAVAIL);
				LstPrdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrdAvail", mask, LSTPRDAVAIL);
				ButPrdViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrdViewActive", mask, BUTPRDVIEWACTIVE);
				LstDatAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDatAvail", mask, LSTDATAVAIL);
				ButDatViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDatViewActive", mask, BUTDATVIEWACTIVE);
				ButDatNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDatNewcrdActive", mask, BUTDATNEWCRDACTIVE);
				LstFilAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFilAvail", mask, LSTFILAVAIL);
				ButFilViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFilViewActive", mask, BUTFILVIEWACTIVE);
				ButFilNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFilNewcrdActive", mask, BUTFILNEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButLivNewcrdAvail == comp.ButLivNewcrdAvail) items.add(BUTLIVNEWCRDAVAIL);
			if (LstPrdAvail == comp.LstPrdAvail) items.add(LSTPRDAVAIL);
			if (ButPrdViewActive == comp.ButPrdViewActive) items.add(BUTPRDVIEWACTIVE);
			if (LstDatAvail == comp.LstDatAvail) items.add(LSTDATAVAIL);
			if (ButDatViewActive == comp.ButDatViewActive) items.add(BUTDATVIEWACTIVE);
			if (ButDatNewcrdActive == comp.ButDatNewcrdActive) items.add(BUTDATNEWCRDACTIVE);
			if (LstFilAvail == comp.LstFilAvail) items.add(LSTFILAVAIL);
			if (ButFilViewActive == comp.ButFilViewActive) items.add(BUTFILVIEWACTIVE);
			if (ButFilNewcrdActive == comp.ButFilNewcrdActive) items.add(BUTFILNEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTLIVNEWCRDAVAIL, LSTPRDAVAIL, BUTPRDVIEWACTIVE, LSTDATAVAIL, BUTDATVIEWACTIVE, BUTDATNEWCRDACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE, BUTFILNEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcNavOpr)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTLIV = 2;
		public static final int CPTPRD = 3;
		public static final int CPTDAT = 4;
		public static final int CPTFIL = 5;

		public Tag(
					String Cpt
					, String CptLiv
					, String CptPrd
					, String CptDat
					, String CptFil
				) {
			this.Cpt = Cpt;
			this.CptLiv = CptLiv;
			this.CptPrd = CptPrd;
			this.CptDat = CptDat;
			this.CptFil = CptFil;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTLIV, CPTPRD, CPTDAT, CPTFIL));
		};

		public String Cpt;
		public String CptLiv;
		public String CptPrd;
		public String CptDat;
		public String CptFil;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcNavOpr");

			String itemtag = "TagitemMsdcNavOpr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptLiv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLiv", mask, CPTLIV);
				CptPrd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrd", mask, CPTPRD);
				CptDat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDat", mask, CPTDAT);
				CptFil = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFil", mask, CPTFIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptLiv.equals(comp.CptLiv)) items.add(CPTLIV);
			if (CptPrd.equals(comp.CptPrd)) items.add(CPTPRD);
			if (CptDat.equals(comp.CptDat)) items.add(CPTDAT);
			if (CptFil.equals(comp.CptFil)) items.add(CPTFIL);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTLIV, CPTPRD, CPTDAT, CPTFIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcNavOprData)
		*/
	public class DpchAppData extends DpchAppMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int ALL = 3;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, Integer[] mask
				) {
			super(VecMsdcVDpch.DPCHAPPMSDCNAVOPRDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
		};

		public ContIac contiac;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppMsdcNavOprData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcNavOprDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCNAVOPRDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcNavOprDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcNavOprData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTDAT = 3;
		public static final int FEEDFLSTFIL = 4;
		public static final int FEEDFLSTPRD = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCNAVOPRDATA);

			contiac = new ContIac(0, 0, 0);
			feedFLstDat = new Feed("FeedFLstDat");
			feedFLstFil = new Feed("FeedFLstFil");
			feedFLstPrd = new Feed("FeedFLstPrd");
			statapp = new StatApp(0, false, false, false, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstDat;
		public Feed feedFLstFil;
		public Feed feedFLstPrd;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTDAT)) ss.add("feedFLstDat");
			if (has(FEEDFLSTFIL)) ss.add("feedFLstFil");
			if (has(FEEDFLSTPRD)) ss.add("feedFLstPrd");
			if (has(STATAPP)) ss.add("statapp");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcNavOprData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstDat.readXML(doc, basexpath, true)) add(FEEDFLSTDAT);
				if (feedFLstFil.readXML(doc, basexpath, true)) add(FEEDFLSTFIL);
				if (feedFLstPrd.readXML(doc, basexpath, true)) add(FEEDFLSTPRD);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0);
				feedFLstDat = new Feed("FeedFLstDat");
				feedFLstFil = new Feed("FeedFLstFil");
				feedFLstPrd = new Feed("FeedFLstPrd");
				statapp = new StatApp(0, false, false, false, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};

