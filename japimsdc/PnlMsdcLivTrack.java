/**
  * \file PnlMsdcLivTrack.java
  * Java API code for job PnlMsdcLivTrack
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcLivTrack {
	/**
		* VecVDo (full: VecVMsdcLivTrackDo)
		*/
	public static class VecVDo {

		public static final int BUTREGULARIZECLICK = 1;
		public static final int BUTMINIMIZECLICK = 2;
		public static final int BUTMASTERCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butmasterclick")) return BUTMASTERCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTMASTERCLICK) return("ButMasterClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacMsdcLivTrack)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPAMF = 1;
		public static final int UPDAPR = 2;
		public static final int CHKVID = 3;
		public static final int CHKWID = 4;

		public ContIac(
					int numFPupAmf
					, int UpdApr
					, boolean ChkVid
					, boolean ChkWid
				) {
			this.numFPupAmf = numFPupAmf;
			this.UpdApr = UpdApr;
			this.ChkVid = ChkVid;
			this.ChkWid = ChkWid;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPAMF, UPDAPR, CHKVID, CHKWID));
		};

		public int numFPupAmf;
		public int UpdApr;
		public boolean ChkVid;
		public boolean ChkWid;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacMsdcLivTrack");

			String itemtag = "ContitemIacMsdcLivTrack";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupAmf = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupAmf", mask, NUMFPUPAMF);
				UpdApr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "UpdApr", mask, UPDAPR);
				ChkVid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkVid", mask, CHKVID);
				ChkWid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkWid", mask, CHKWID);

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
			if (difftag.isEmpty()) difftag = "ContIacMsdcLivTrack";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacMsdcLivTrack";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupAmf", numFPupAmf);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "UpdApr", UpdApr);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkVid", ChkVid);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkWid", ChkWid);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupAmf == comp.numFPupAmf) items.add(NUMFPUPAMF);
			if (UpdApr == comp.UpdApr) items.add(UPDAPR);
			if (ChkVid == comp.ChkVid) items.add(CHKVID);
			if (ChkWid == comp.ChkWid) items.add(CHKWID);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPAMF, UPDAPR, CHKVID, CHKWID));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfMsdcLivTrack)
	  */
	public class ContInf extends Block {

		public static final int BUTMASTERON = 1;
		public static final int TXTVPX = 2;
		public static final int TXTVPY = 3;
		public static final int TXTWPX = 4;
		public static final int TXTWPY = 5;
		public static final int TXTDIS = 6;

		public ContInf(
					boolean ButMasterOn
					, String TxtVpx
					, String TxtVpy
					, String TxtWpx
					, String TxtWpy
					, String TxtDis
				) {
			this.ButMasterOn = ButMasterOn;
			this.TxtVpx = TxtVpx;
			this.TxtVpy = TxtVpy;
			this.TxtWpx = TxtWpx;
			this.TxtWpy = TxtWpy;
			this.TxtDis = TxtDis;

			mask = new HashSet<Integer>(Arrays.asList(BUTMASTERON, TXTVPX, TXTVPY, TXTWPX, TXTWPY, TXTDIS));
		};

		public boolean ButMasterOn;
		public String TxtVpx;
		public String TxtVpy;
		public String TxtWpx;
		public String TxtWpy;
		public String TxtDis;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcLivTrack");

			String itemtag = "ContitemInfMsdcLivTrack";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButMasterOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButMasterOn", mask, BUTMASTERON);
				TxtVpx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVpx", mask, TXTVPX);
				TxtVpy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVpy", mask, TXTVPY);
				TxtWpx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtWpx", mask, TXTWPX);
				TxtWpy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtWpy", mask, TXTWPY);
				TxtDis = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtDis", mask, TXTDIS);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButMasterOn == comp.ButMasterOn) items.add(BUTMASTERON);
			if (TxtVpx.equals(comp.TxtVpx)) items.add(TXTVPX);
			if (TxtVpy.equals(comp.TxtVpy)) items.add(TXTVPY);
			if (TxtWpx.equals(comp.TxtWpx)) items.add(TXTWPX);
			if (TxtWpy.equals(comp.TxtWpy)) items.add(TXTWPY);
			if (TxtDis.equals(comp.TxtDis)) items.add(TXTDIS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTMASTERON, TXTVPX, TXTVPY, TXTWPX, TXTWPY, TXTDIS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrMsdcLivTrack)
	  */
	public class StatShr extends Block {

		public static final int IXMSDCVEXPSTATE = 1;
		public static final int PUPAMFACTIVE = 2;
		public static final int UPDAPRACTIVE = 3;
		public static final int UPDAPRMIN = 4;
		public static final int UPDAPRMAX = 5;
		public static final int CHKVIDACTIVE = 6;
		public static final int CHKWIDACTIVE = 7;

		public StatShr(
					int ixMsdcVExpstate
					, boolean PupAmfActive
					, boolean UpdAprActive
					, int UpdAprMin
					, int UpdAprMax
					, boolean ChkVidActive
					, boolean ChkWidActive
				) {
			this.ixMsdcVExpstate = ixMsdcVExpstate;
			this.PupAmfActive = PupAmfActive;
			this.UpdAprActive = UpdAprActive;
			this.UpdAprMin = UpdAprMin;
			this.UpdAprMax = UpdAprMax;
			this.ChkVidActive = ChkVidActive;
			this.ChkWidActive = ChkWidActive;

			mask = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE, PUPAMFACTIVE, UPDAPRACTIVE, UPDAPRMIN, UPDAPRMAX, CHKVIDACTIVE, CHKWIDACTIVE));
		};

		public int ixMsdcVExpstate;
		public boolean PupAmfActive;
		public boolean UpdAprActive;
		public int UpdAprMin;
		public int UpdAprMax;
		public boolean ChkVidActive;
		public boolean ChkWidActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxMsdcVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcLivTrack");

			String itemtag = "StatitemShrMsdcLivTrack";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxMsdcVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", mask, IXMSDCVEXPSTATE);
				ixMsdcVExpstate = VecMsdcVExpstate.getIx(srefIxMsdcVExpstate);
				PupAmfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupAmfActive", mask, PUPAMFACTIVE);
				UpdAprActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdAprActive", mask, UPDAPRACTIVE);
				UpdAprMin = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdAprMin", mask, UPDAPRMIN);
				UpdAprMax = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdAprMax", mask, UPDAPRMAX);
				ChkVidActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkVidActive", mask, CHKVIDACTIVE);
				ChkWidActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkWidActive", mask, CHKWIDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixMsdcVExpstate == comp.ixMsdcVExpstate) items.add(IXMSDCVEXPSTATE);
			if (PupAmfActive == comp.PupAmfActive) items.add(PUPAMFACTIVE);
			if (UpdAprActive == comp.UpdAprActive) items.add(UPDAPRACTIVE);
			if (UpdAprMin == comp.UpdAprMin) items.add(UPDAPRMIN);
			if (UpdAprMax == comp.UpdAprMax) items.add(UPDAPRMAX);
			if (ChkVidActive == comp.ChkVidActive) items.add(CHKVIDACTIVE);
			if (ChkWidActive == comp.ChkWidActive) items.add(CHKWIDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE, PUPAMFACTIVE, UPDAPRACTIVE, UPDAPRMIN, UPDAPRMAX, CHKVIDACTIVE, CHKWIDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcLivTrack)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int HDGALS = 2;
		public static final int CPTAMF = 3;
		public static final int CPTAPR = 4;
		public static final int HDGVSL = 5;
		public static final int CPTVID = 6;
		public static final int CPTVPX = 7;
		public static final int CPTVPY = 8;
		public static final int HDGWSR = 9;
		public static final int CPTWID = 10;
		public static final int CPTWPX = 11;
		public static final int CPTWPY = 12;
		public static final int CPTDIS = 13;

		public Tag(
					String Cpt
					, String HdgAls
					, String CptAmf
					, String CptApr
					, String HdgVsl
					, String CptVid
					, String CptVpx
					, String CptVpy
					, String HdgWsr
					, String CptWid
					, String CptWpx
					, String CptWpy
					, String CptDis
				) {
			this.Cpt = Cpt;
			this.HdgAls = HdgAls;
			this.CptAmf = CptAmf;
			this.CptApr = CptApr;
			this.HdgVsl = HdgVsl;
			this.CptVid = CptVid;
			this.CptVpx = CptVpx;
			this.CptVpy = CptVpy;
			this.HdgWsr = HdgWsr;
			this.CptWid = CptWid;
			this.CptWpx = CptWpx;
			this.CptWpy = CptWpy;
			this.CptDis = CptDis;

			mask = new HashSet<Integer>(Arrays.asList(CPT, HDGALS, CPTAMF, CPTAPR, HDGVSL, CPTVID, CPTVPX, CPTVPY, HDGWSR, CPTWID, CPTWPX, CPTWPY, CPTDIS));
		};

		public String Cpt;
		public String HdgAls;
		public String CptAmf;
		public String CptApr;
		public String HdgVsl;
		public String CptVid;
		public String CptVpx;
		public String CptVpy;
		public String HdgWsr;
		public String CptWid;
		public String CptWpx;
		public String CptWpy;
		public String CptDis;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcLivTrack");

			String itemtag = "TagitemMsdcLivTrack";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				HdgAls = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgAls", mask, HDGALS);
				CptAmf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAmf", mask, CPTAMF);
				CptApr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptApr", mask, CPTAPR);
				HdgVsl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgVsl", mask, HDGVSL);
				CptVid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVid", mask, CPTVID);
				CptVpx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVpx", mask, CPTVPX);
				CptVpy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVpy", mask, CPTVPY);
				HdgWsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgWsr", mask, HDGWSR);
				CptWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptWid", mask, CPTWID);
				CptWpx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptWpx", mask, CPTWPX);
				CptWpy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptWpy", mask, CPTWPY);
				CptDis = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDis", mask, CPTDIS);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (HdgAls.equals(comp.HdgAls)) items.add(HDGALS);
			if (CptAmf.equals(comp.CptAmf)) items.add(CPTAMF);
			if (CptApr.equals(comp.CptApr)) items.add(CPTAPR);
			if (HdgVsl.equals(comp.HdgVsl)) items.add(HDGVSL);
			if (CptVid.equals(comp.CptVid)) items.add(CPTVID);
			if (CptVpx.equals(comp.CptVpx)) items.add(CPTVPX);
			if (CptVpy.equals(comp.CptVpy)) items.add(CPTVPY);
			if (HdgWsr.equals(comp.HdgWsr)) items.add(HDGWSR);
			if (CptWid.equals(comp.CptWid)) items.add(CPTWID);
			if (CptWpx.equals(comp.CptWpx)) items.add(CPTWPX);
			if (CptWpy.equals(comp.CptWpy)) items.add(CPTWPY);
			if (CptDis.equals(comp.CptDis)) items.add(CPTDIS);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, HDGALS, CPTAMF, CPTAPR, HDGVSL, CPTVID, CPTVPX, CPTVPY, HDGWSR, CPTWID, CPTWPX, CPTWPY, CPTDIS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcLivTrackData)
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
			super(VecMsdcVDpch.DPCHAPPMSDCLIVTRACKDATA, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcLivTrackData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcLivTrackDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCLIVTRACKDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcLivTrackDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcLivTrackData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPAMF = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCLIVTRACKDATA);

			contiac = new ContIac(0, 0, false, false);
			continf = new ContInf(false, "", "", "", "", "");
			feedFPupAmf = new Feed("FeedFPupAmf");
			statshr = new StatShr(0, false, false, 0, 0, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupAmf;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPAMF)) ss.add("feedFPupAmf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcLivTrackData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupAmf.readXML(doc, basexpath, true)) add(FEEDFPUPAMF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, false, false);
				continf = new ContInf(false, "", "", "", "", "");
				feedFPupAmf = new Feed("FeedFPupAmf");
				statshr = new StatShr(0, false, false, 0, 0, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

