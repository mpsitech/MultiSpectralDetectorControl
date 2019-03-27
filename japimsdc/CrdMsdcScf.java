/**
  * \file CrdMsdcScf.java
  * Java API code for job CrdMsdcScf
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdMsdcScf {
	/**
		* VecVDo (full: VecVMsdcScfDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVMsdcScfSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRMSDCABT = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrmsdcabt")) return ALRMSDCABT;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRMSDCABT) return("alrmsdcabt");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfMsdcScf)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;

		public ContInf(
					int numFSge
					, String MrlAppHlp
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP));
		};

		public int numFSge;
		public String MrlAppHlp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcScf");

			String itemtag = "ContitemInfMsdcScf";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (MrlAppHlp.equals(comp.MrlAppHlp)) items.add(MRLAPPHLP);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppMsdcScf)
	  */
	public class StatApp extends Block {

		public static final int IXMSDCVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONESOURCE = 5;
		public static final int INITDONEACQUIS = 6;
		public static final int INITDONEACTU = 7;
		public static final int INITDONEPRCCTL = 8;
		public static final int INITDONEHEADBAR = 9;

		public StatApp(
					int ixMsdcVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneSource
					, boolean initdoneAcquis
					, boolean initdoneActu
					, boolean initdonePrcctl
					, boolean initdoneHeadbar
				) {
			this.ixMsdcVReqitmode = ixMsdcVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneSource = initdoneSource;
			this.initdoneAcquis = initdoneAcquis;
			this.initdoneActu = initdoneActu;
			this.initdonePrcctl = initdonePrcctl;
			this.initdoneHeadbar = initdoneHeadbar;

			mask = new HashSet<Integer>(Arrays.asList(IXMSDCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONESOURCE, INITDONEACQUIS, INITDONEACTU, INITDONEPRCCTL, INITDONEHEADBAR));
		};

		public int ixMsdcVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneSource;
		public boolean initdoneAcquis;
		public boolean initdoneActu;
		public boolean initdonePrcctl;
		public boolean initdoneHeadbar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxMsdcVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcScf");

			String itemtag = "StatitemAppMsdcScf";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxMsdcVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVReqitmode", mask, IXMSDCVREQITMODE);
				ixMsdcVReqitmode = VecMsdcVReqitmode.getIx(srefIxMsdcVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneSource = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSource", mask, INITDONESOURCE);
				initdoneAcquis = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAcquis", mask, INITDONEACQUIS);
				initdoneActu = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneActu", mask, INITDONEACTU);
				initdonePrcctl = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdonePrcctl", mask, INITDONEPRCCTL);
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixMsdcVReqitmode == comp.ixMsdcVReqitmode) items.add(IXMSDCVREQITMODE);
			if (latency == comp.latency) items.add(LATENCY);
			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);
			if (widthMenu == comp.widthMenu) items.add(WIDTHMENU);
			if (initdoneSource == comp.initdoneSource) items.add(INITDONESOURCE);
			if (initdoneAcquis == comp.initdoneAcquis) items.add(INITDONEACQUIS);
			if (initdoneActu == comp.initdoneActu) items.add(INITDONEACTU);
			if (initdonePrcctl == comp.initdonePrcctl) items.add(INITDONEPRCCTL);
			if (initdoneHeadbar == comp.initdoneHeadbar) items.add(INITDONEHEADBAR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXMSDCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONESOURCE, INITDONEACQUIS, INITDONEACTU, INITDONEPRCCTL, INITDONEHEADBAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrMsdcScf)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFSOURCE = 1;
		public static final int SCRJREFACQUIS = 2;
		public static final int SCRJREFACTU = 3;
		public static final int SCRJREFPRCCTL = 4;
		public static final int SCRJREFHEADBAR = 5;

		public StatShr(
					String scrJrefSource
					, String scrJrefAcquis
					, String scrJrefActu
					, String scrJrefPrcctl
					, String scrJrefHeadbar
				) {
			this.scrJrefSource = scrJrefSource;
			this.scrJrefAcquis = scrJrefAcquis;
			this.scrJrefActu = scrJrefActu;
			this.scrJrefPrcctl = scrJrefPrcctl;
			this.scrJrefHeadbar = scrJrefHeadbar;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFSOURCE, SCRJREFACQUIS, SCRJREFACTU, SCRJREFPRCCTL, SCRJREFHEADBAR));
		};

		public String scrJrefSource;
		public String scrJrefAcquis;
		public String scrJrefActu;
		public String scrJrefPrcctl;
		public String scrJrefHeadbar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcScf");

			String itemtag = "StatitemShrMsdcScf";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefSource = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSource", mask, SCRJREFSOURCE);
				scrJrefAcquis = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAcquis", mask, SCRJREFACQUIS);
				scrJrefActu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefActu", mask, SCRJREFACTU);
				scrJrefPrcctl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefPrcctl", mask, SCRJREFPRCCTL);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefSource.equals(comp.scrJrefSource)) items.add(SCRJREFSOURCE);
			if (scrJrefAcquis.equals(comp.scrJrefAcquis)) items.add(SCRJREFACQUIS);
			if (scrJrefActu.equals(comp.scrJrefActu)) items.add(SCRJREFACTU);
			if (scrJrefPrcctl.equals(comp.scrJrefPrcctl)) items.add(SCRJREFPRCCTL);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFSOURCE, SCRJREFACQUIS, SCRJREFACTU, SCRJREFPRCCTL, SCRJREFHEADBAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcScf)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP));
		};

		public String MitAppAbt;
		public String MrlAppHlp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcScf");

			String itemtag = "TagitemMsdcScf";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (MitAppAbt.equals(comp.MitAppAbt)) items.add(MITAPPABT);
			if (MrlAppHlp.equals(comp.MrlAppHlp)) items.add(MRLAPPHLP);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcScfDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCSCFDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcScfDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcScfData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCSCFDATA);

			continf = new ContInf(0, "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false, false, false);
			statshr = new StatShr("", "", "", "", "");
			tag = new Tag("", "");
		};

		public ContInf continf;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFSGE)) ss.add("feedFSge");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcScfData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(0, 0, "", 0, false, false, false, false, false);
				statshr = new StatShr("", "", "", "", "");
				tag = new Tag("", "");
			};
		};

	};

};

