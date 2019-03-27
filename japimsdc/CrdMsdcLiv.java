/**
  * \file CrdMsdcLiv.java
  * Java API code for job CrdMsdcLiv
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdMsdcLiv {
	/**
		* VecVDo (full: VecVMsdcLivDo)
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
		* VecVSge (full: VecVMsdcLivSge)
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
	  * ContInf (full: ContInfMsdcLiv)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcLiv");

			String itemtag = "ContitemInfMsdcLiv";

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
	  * StatApp (full: StatAppMsdcLiv)
	  */
	public class StatApp extends Block {

		public static final int IXMSDCVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONEVIDEO = 5;
		public static final int INITDONEALIGN = 6;
		public static final int INITDONESCILL = 7;
		public static final int INITDONETRACK = 8;
		public static final int INITDONEHEADBAR = 9;

		public StatApp(
					int ixMsdcVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneVideo
					, boolean initdoneAlign
					, boolean initdoneScill
					, boolean initdoneTrack
					, boolean initdoneHeadbar
				) {
			this.ixMsdcVReqitmode = ixMsdcVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneVideo = initdoneVideo;
			this.initdoneAlign = initdoneAlign;
			this.initdoneScill = initdoneScill;
			this.initdoneTrack = initdoneTrack;
			this.initdoneHeadbar = initdoneHeadbar;

			mask = new HashSet<Integer>(Arrays.asList(IXMSDCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEVIDEO, INITDONEALIGN, INITDONESCILL, INITDONETRACK, INITDONEHEADBAR));
		};

		public int ixMsdcVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneVideo;
		public boolean initdoneAlign;
		public boolean initdoneScill;
		public boolean initdoneTrack;
		public boolean initdoneHeadbar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxMsdcVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcLiv");

			String itemtag = "StatitemAppMsdcLiv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxMsdcVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVReqitmode", mask, IXMSDCVREQITMODE);
				ixMsdcVReqitmode = VecMsdcVReqitmode.getIx(srefIxMsdcVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneVideo = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneVideo", mask, INITDONEVIDEO);
				initdoneAlign = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAlign", mask, INITDONEALIGN);
				initdoneScill = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneScill", mask, INITDONESCILL);
				initdoneTrack = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTrack", mask, INITDONETRACK);
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
			if (initdoneVideo == comp.initdoneVideo) items.add(INITDONEVIDEO);
			if (initdoneAlign == comp.initdoneAlign) items.add(INITDONEALIGN);
			if (initdoneScill == comp.initdoneScill) items.add(INITDONESCILL);
			if (initdoneTrack == comp.initdoneTrack) items.add(INITDONETRACK);
			if (initdoneHeadbar == comp.initdoneHeadbar) items.add(INITDONEHEADBAR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXMSDCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEVIDEO, INITDONEALIGN, INITDONESCILL, INITDONETRACK, INITDONEHEADBAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrMsdcLiv)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFVIDEO = 1;
		public static final int SCRJREFALIGN = 2;
		public static final int SCRJREFSCILL = 3;
		public static final int SCRJREFTRACK = 4;
		public static final int SCRJREFHEADBAR = 5;

		public StatShr(
					String scrJrefVideo
					, String scrJrefAlign
					, String scrJrefScill
					, String scrJrefTrack
					, String scrJrefHeadbar
				) {
			this.scrJrefVideo = scrJrefVideo;
			this.scrJrefAlign = scrJrefAlign;
			this.scrJrefScill = scrJrefScill;
			this.scrJrefTrack = scrJrefTrack;
			this.scrJrefHeadbar = scrJrefHeadbar;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFVIDEO, SCRJREFALIGN, SCRJREFSCILL, SCRJREFTRACK, SCRJREFHEADBAR));
		};

		public String scrJrefVideo;
		public String scrJrefAlign;
		public String scrJrefScill;
		public String scrJrefTrack;
		public String scrJrefHeadbar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcLiv");

			String itemtag = "StatitemShrMsdcLiv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefVideo = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefVideo", mask, SCRJREFVIDEO);
				scrJrefAlign = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAlign", mask, SCRJREFALIGN);
				scrJrefScill = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefScill", mask, SCRJREFSCILL);
				scrJrefTrack = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTrack", mask, SCRJREFTRACK);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefVideo.equals(comp.scrJrefVideo)) items.add(SCRJREFVIDEO);
			if (scrJrefAlign.equals(comp.scrJrefAlign)) items.add(SCRJREFALIGN);
			if (scrJrefScill.equals(comp.scrJrefScill)) items.add(SCRJREFSCILL);
			if (scrJrefTrack.equals(comp.scrJrefTrack)) items.add(SCRJREFTRACK);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFVIDEO, SCRJREFALIGN, SCRJREFSCILL, SCRJREFTRACK, SCRJREFHEADBAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcLiv)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcLiv");

			String itemtag = "TagitemMsdcLiv";

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
		* DpchAppDo (full: DpchAppMsdcLivDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCLIVDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcLivDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcLivData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCLIVDATA);

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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcLivData");

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

