/**
  * \file PnlMsdcUsgMNUser.java
  * Java API code for job PnlMsdcUsgMNUser
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcUsgMNUser {
	/**
		* VecVDo (full: VecVMsdcUsgMNUserDo)
		*/
	public static class VecVDo {

		public static final int BUTVIEWCLICK = 1;
		public static final int BUTADDCLICK = 2;
		public static final int BUTSUBCLICK = 3;
		public static final int BUTREFRESHCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butviewclick")) return BUTVIEWCLICK;
			if (s.equals("butaddclick")) return BUTADDCLICK;
			if (s.equals("butsubclick")) return BUTSUBCLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTVIEWCLICK) return("ButViewClick");
			if (ix == BUTADDCLICK) return("ButAddClick");
			if (ix == BUTSUBCLICK) return("ButSubClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfMsdcUsgMNUser)
	  */
	public class ContInf extends Block {

		public static final int NUMFCSIQST = 1;

		public ContInf(
					int numFCsiQst
				) {
			this.numFCsiQst = numFCsiQst;

			mask = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
		};

		public int numFCsiQst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcUsgMNUser");

			String itemtag = "ContitemInfMsdcUsgMNUser";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFCsiQst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFCsiQst", mask, NUMFCSIQST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFCsiQst == comp.numFCsiQst) items.add(NUMFCSIQST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppMsdcUsgMNUser)
	  */
	public class StatApp extends Block {

		public static final int IXMSDCVEXPSTATE = 1;

		public StatApp(
					int ixMsdcVExpstate
				) {
			this.ixMsdcVExpstate = ixMsdcVExpstate;

			mask = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE));
		};

		public int ixMsdcVExpstate;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxMsdcVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcUsgMNUser");

			String itemtag = "StatitemAppMsdcUsgMNUser";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxMsdcVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", mask, IXMSDCVEXPSTATE);
				ixMsdcVExpstate = VecMsdcVExpstate.getIx(srefIxMsdcVExpstate);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixMsdcVExpstate == comp.ixMsdcVExpstate) items.add(IXMSDCVEXPSTATE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrMsdcUsgMNUser)
	  */
	public class StatShr extends Block {

		public static final int BUTVIEWAVAIL = 1;
		public static final int BUTVIEWACTIVE = 2;
		public static final int BUTADDAVAIL = 3;
		public static final int BUTSUBAVAIL = 4;
		public static final int BUTSUBACTIVE = 5;

		public StatShr(
					boolean ButViewAvail
					, boolean ButViewActive
					, boolean ButAddAvail
					, boolean ButSubAvail
					, boolean ButSubActive
				) {
			this.ButViewAvail = ButViewAvail;
			this.ButViewActive = ButViewActive;
			this.ButAddAvail = ButAddAvail;
			this.ButSubAvail = ButSubAvail;
			this.ButSubActive = ButSubActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE));
		};

		public boolean ButViewAvail;
		public boolean ButViewActive;
		public boolean ButAddAvail;
		public boolean ButSubAvail;
		public boolean ButSubActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcUsgMNUser");

			String itemtag = "StatitemShrMsdcUsgMNUser";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButViewAvail", mask, BUTVIEWAVAIL);
				ButViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButViewActive", mask, BUTVIEWACTIVE);
				ButAddAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButAddAvail", mask, BUTADDAVAIL);
				ButSubAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSubAvail", mask, BUTSUBAVAIL);
				ButSubActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSubActive", mask, BUTSUBACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButViewAvail == comp.ButViewAvail) items.add(BUTVIEWAVAIL);
			if (ButViewActive == comp.ButViewActive) items.add(BUTVIEWACTIVE);
			if (ButAddAvail == comp.ButAddAvail) items.add(BUTADDAVAIL);
			if (ButSubAvail == comp.ButSubAvail) items.add(BUTSUBAVAIL);
			if (ButSubActive == comp.ButSubActive) items.add(BUTSUBACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacMsdcUsgMNUser)
	  */
	public class StgIac extends Block {

		public static final int TCOMREFWIDTH = 1;
		public static final int TCOULVWIDTH = 2;

		public StgIac(
					int TcoMrefWidth
					, int TcoUlvWidth
				) {
			this.TcoMrefWidth = TcoMrefWidth;
			this.TcoUlvWidth = TcoUlvWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOMREFWIDTH, TCOULVWIDTH));
		};

		public int TcoMrefWidth;
		public int TcoUlvWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacMsdcUsgMNUser");

			String itemtag = "StgitemIacMsdcUsgMNUser";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoMrefWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", mask, TCOMREFWIDTH);
				TcoUlvWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoUlvWidth", mask, TCOULVWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacMsdcUsgMNUser";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacMsdcUsgMNUser";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoUlvWidth", TcoUlvWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoMrefWidth == comp.TcoMrefWidth) items.add(TCOMREFWIDTH);
			if (TcoUlvWidth == comp.TcoUlvWidth) items.add(TCOULVWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOMREFWIDTH, TCOULVWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcUsgMNUser)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TRS = 2;
		public static final int TXTSHOWING1 = 3;
		public static final int TXTSHOWING2 = 4;
		public static final int TCOMREF = 5;
		public static final int TCOULV = 6;

		public Tag(
					String Cpt
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoMref
					, String TcoUlv
				) {
			this.Cpt = Cpt;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoMref = TcoMref;
			this.TcoUlv = TcoUlv;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF, TCOULV));
		};

		public String Cpt;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoMref;
		public String TcoUlv;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcUsgMNUser");

			String itemtag = "TagitemMsdcUsgMNUser";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoMref = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoMref", mask, TCOMREF);
				TcoUlv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoUlv", mask, TCOULV);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (Trs.equals(comp.Trs)) items.add(TRS);
			if (TxtShowing1.equals(comp.TxtShowing1)) items.add(TXTSHOWING1);
			if (TxtShowing2.equals(comp.TxtShowing2)) items.add(TXTSHOWING2);
			if (TcoMref.equals(comp.TcoMref)) items.add(TCOMREF);
			if (TcoUlv.equals(comp.TcoUlv)) items.add(TCOULV);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF, TCOULV));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcUsgMNUserData)
		*/
	public class DpchAppData extends DpchAppMsdc {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryMsdcUsgMNUser.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecMsdcVDpch.DPCHAPPMSDCUSGMNUSERDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, STGIAC, STGIACQRY));
					break;
				};

			if (has(STGIAC)) this.stgiac = stgiac;
			if (has(STGIACQRY)) this.stgiacqry = stgiacqry;
		};

		public StgIac stgiac;
		public QryMsdcUsgMNUser.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppMsdcUsgMNUserData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcUsgMNUserDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCUSGMNUSERDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcUsgMNUserDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcUsgMNUserData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFCSIQST = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int STGIAC = 6;
		public static final int TAG = 7;
		public static final int RST = 8;
		public static final int STATAPPQRY = 9;
		public static final int STATSHRQRY = 10;
		public static final int STGIACQRY = 11;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCUSGMNUSERDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false);
			stgiac = new StgIac(0, 0);
			tag = new Tag("", "", "", "", "", "");
			rst = new ListMsdcQUsgMNUser();
			statappqry = (new QryMsdcUsgMNUser()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryMsdcUsgMNUser()).new StatShr(0, 0, 0);
			stgiacqry = (new QryMsdcUsgMNUser()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListMsdcQUsgMNUser rst;
		public QryMsdcUsgMNUser.StatApp statappqry;
		public QryMsdcUsgMNUser.StatShr statshrqry;
		public QryMsdcUsgMNUser.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFCSIQST)) ss.add("feedFCsiQst");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(TAG)) ss.add("tag");
			if (has(RST)) ss.add("rst");
			if (has(STATAPPQRY)) ss.add("statappqry");
			if (has(STATSHRQRY)) ss.add("statshrqry");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcUsgMNUserData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFCsiQst.readXML(doc, basexpath, true)) add(FEEDFCSIQST);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stgiac.readXML(doc, basexpath, true)) add(STGIAC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (rst.readXML(doc, basexpath, true)) add(RST);
				if (statappqry.readXML(doc, basexpath, true)) add(STATAPPQRY);
				if (statshrqry.readXML(doc, basexpath, true)) add(STATSHRQRY);
				if (stgiacqry.readXML(doc, basexpath, true)) add(STGIACQRY);
			} else {
				scrJref = "";
				continf = new ContInf(0);
				feedFCsiQst = new Feed("FeedFCsiQst");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false);
				stgiac = new StgIac(0, 0);
				tag = new Tag("", "", "", "", "", "");
				statappqry = (new QryMsdcUsgMNUser()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryMsdcUsgMNUser()).new StatShr(0, 0, 0);
				stgiacqry = (new QryMsdcUsgMNUser()).new StgIac(0, 0, 0);
			};
		};

	};

};

