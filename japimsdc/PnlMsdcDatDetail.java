/**
  * \file PnlMsdcDatDetail.java
  * Java API code for job PnlMsdcDatDetail
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcDatDetail {
	/**
		* VecVDo (full: VecVMsdcDatDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTAFTEDITCLICK = 2;
		public static final int BUTPRDVIEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butafteditclick")) return BUTAFTEDITCLICK;
			if (s.equals("butprdviewclick")) return BUTPRDVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTAFTEDITCLICK) return("ButAftEditClick");
			if (ix == BUTPRDVIEWCLICK) return("ButPrdViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacMsdcDatDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPAFT = 1;
		public static final int TXFAFT = 2;
		public static final int TXFSTA = 3;
		public static final int TXFSTO = 4;
		public static final int TXFCMT = 5;

		public ContIac(
					int numFPupAft
					, String TxfAft
					, String TxfSta
					, String TxfSto
					, String TxfCmt
				) {
			this.numFPupAft = numFPupAft;
			this.TxfAft = TxfAft;
			this.TxfSta = TxfSta;
			this.TxfSto = TxfSto;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPAFT, TXFAFT, TXFSTA, TXFSTO, TXFCMT));
		};

		public int numFPupAft;
		public String TxfAft;
		public String TxfSta;
		public String TxfSto;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacMsdcDatDetail");

			String itemtag = "ContitemIacMsdcDatDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupAft = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupAft", mask, NUMFPUPAFT);
				TxfAft = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAft", mask, TXFAFT);
				TxfSta = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSta", mask, TXFSTA);
				TxfSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSto", mask, TXFSTO);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);

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
			if (difftag.isEmpty()) difftag = "ContIacMsdcDatDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacMsdcDatDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupAft", numFPupAft);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAft", TxfAft);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSta", TxfSta);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSto", TxfSto);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupAft == comp.numFPupAft) items.add(NUMFPUPAFT);
			if (TxfAft.equals(comp.TxfAft)) items.add(TXFAFT);
			if (TxfSta.equals(comp.TxfSta)) items.add(TXFSTA);
			if (TxfSto.equals(comp.TxfSto)) items.add(TXFSTO);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPAFT, TXFAFT, TXFSTA, TXFSTO, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfMsdcDatDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTPRD = 1;

		public ContInf(
					String TxtPrd
				) {
			this.TxtPrd = TxtPrd;

			mask = new HashSet<Integer>(Arrays.asList(TXTPRD));
		};

		public String TxtPrd;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcDatDetail");

			String itemtag = "ContitemInfMsdcDatDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrd", mask, TXTPRD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrd.equals(comp.TxtPrd)) items.add(TXTPRD);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTPRD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppMsdcDatDetail)
	  */
	public class StatApp extends Block {

		public static final int IXMSDCVEXPSTATE = 1;
		public static final int PUPAFTALT = 2;

		public StatApp(
					int ixMsdcVExpstate
					, boolean PupAftAlt
				) {
			this.ixMsdcVExpstate = ixMsdcVExpstate;
			this.PupAftAlt = PupAftAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE, PUPAFTALT));
		};

		public int ixMsdcVExpstate;
		public boolean PupAftAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxMsdcVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcDatDetail");

			String itemtag = "StatitemAppMsdcDatDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxMsdcVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", mask, IXMSDCVEXPSTATE);
				ixMsdcVExpstate = VecMsdcVExpstate.getIx(srefIxMsdcVExpstate);
				PupAftAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupAftAlt", mask, PUPAFTALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixMsdcVExpstate == comp.ixMsdcVExpstate) items.add(IXMSDCVEXPSTATE);
			if (PupAftAlt == comp.PupAftAlt) items.add(PUPAFTALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE, PUPAFTALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrMsdcDatDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFAFTVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int PUPAFTACTIVE = 4;
		public static final int BUTAFTEDITAVAIL = 5;
		public static final int TXTPRDACTIVE = 6;
		public static final int BUTPRDVIEWAVAIL = 7;
		public static final int BUTPRDVIEWACTIVE = 8;
		public static final int TXFSTAACTIVE = 9;
		public static final int TXFSTOACTIVE = 10;
		public static final int TXFCMTACTIVE = 11;

		public StatShr(
					boolean TxfAftValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean PupAftActive
					, boolean ButAftEditAvail
					, boolean TxtPrdActive
					, boolean ButPrdViewAvail
					, boolean ButPrdViewActive
					, boolean TxfStaActive
					, boolean TxfStoActive
					, boolean TxfCmtActive
				) {
			this.TxfAftValid = TxfAftValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.PupAftActive = PupAftActive;
			this.ButAftEditAvail = ButAftEditAvail;
			this.TxtPrdActive = TxtPrdActive;
			this.ButPrdViewAvail = ButPrdViewAvail;
			this.ButPrdViewActive = ButPrdViewActive;
			this.TxfStaActive = TxfStaActive;
			this.TxfStoActive = TxfStoActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFAFTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, PUPAFTACTIVE, BUTAFTEDITAVAIL, TXTPRDACTIVE, BUTPRDVIEWAVAIL, BUTPRDVIEWACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFCMTACTIVE));
		};

		public boolean TxfAftValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean PupAftActive;
		public boolean ButAftEditAvail;
		public boolean TxtPrdActive;
		public boolean ButPrdViewAvail;
		public boolean ButPrdViewActive;
		public boolean TxfStaActive;
		public boolean TxfStoActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcDatDetail");

			String itemtag = "StatitemShrMsdcDatDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfAftValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfAftValid", mask, TXFAFTVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				PupAftActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupAftActive", mask, PUPAFTACTIVE);
				ButAftEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButAftEditAvail", mask, BUTAFTEDITAVAIL);
				TxtPrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPrdActive", mask, TXTPRDACTIVE);
				ButPrdViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrdViewAvail", mask, BUTPRDVIEWAVAIL);
				ButPrdViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrdViewActive", mask, BUTPRDVIEWACTIVE);
				TxfStaActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfStaActive", mask, TXFSTAACTIVE);
				TxfStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfStoActive", mask, TXFSTOACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfAftValid == comp.TxfAftValid) items.add(TXFAFTVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (PupAftActive == comp.PupAftActive) items.add(PUPAFTACTIVE);
			if (ButAftEditAvail == comp.ButAftEditAvail) items.add(BUTAFTEDITAVAIL);
			if (TxtPrdActive == comp.TxtPrdActive) items.add(TXTPRDACTIVE);
			if (ButPrdViewAvail == comp.ButPrdViewAvail) items.add(BUTPRDVIEWAVAIL);
			if (ButPrdViewActive == comp.ButPrdViewActive) items.add(BUTPRDVIEWACTIVE);
			if (TxfStaActive == comp.TxfStaActive) items.add(TXFSTAACTIVE);
			if (TxfStoActive == comp.TxfStoActive) items.add(TXFSTOACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFAFTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, PUPAFTACTIVE, BUTAFTEDITAVAIL, TXTPRDACTIVE, BUTPRDVIEWAVAIL, BUTPRDVIEWACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcDatDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTAFT = 2;
		public static final int CPTPRD = 3;
		public static final int CPTSTA = 4;
		public static final int CPTSTO = 5;
		public static final int CPTCMT = 6;

		public Tag(
					String Cpt
					, String CptAft
					, String CptPrd
					, String CptSta
					, String CptSto
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptAft = CptAft;
			this.CptPrd = CptPrd;
			this.CptSta = CptSta;
			this.CptSto = CptSto;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTAFT, CPTPRD, CPTSTA, CPTSTO, CPTCMT));
		};

		public String Cpt;
		public String CptAft;
		public String CptPrd;
		public String CptSta;
		public String CptSto;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcDatDetail");

			String itemtag = "TagitemMsdcDatDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptAft = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAft", mask, CPTAFT);
				CptPrd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrd", mask, CPTPRD);
				CptSta = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSta", mask, CPTSTA);
				CptSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSto", mask, CPTSTO);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptAft.equals(comp.CptAft)) items.add(CPTAFT);
			if (CptPrd.equals(comp.CptPrd)) items.add(CPTPRD);
			if (CptSta.equals(comp.CptSta)) items.add(CPTSTA);
			if (CptSto.equals(comp.CptSto)) items.add(CPTSTO);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTAFT, CPTPRD, CPTSTA, CPTSTO, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcDatDetailData)
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
			super(VecMsdcVDpch.DPCHAPPMSDCDATDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcDatDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcDatDetailDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCDATDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcDatDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcDatDetailData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPAFT = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCDATDETAILDATA);

			contiac = new ContIac(0, "", "", "", "");
			continf = new ContInf("");
			feedFPupAft = new Feed("FeedFPupAft");
			statapp = new StatApp(0, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupAft;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPAFT)) ss.add("feedFPupAft");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcDatDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupAft.readXML(doc, basexpath, true)) add(FEEDFPUPAFT);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", "", "", "");
				continf = new ContInf("");
				feedFPupAft = new Feed("FeedFPupAft");
				statapp = new StatApp(0, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};

