/**
  * \file PnlMsdcLivVideo.java
  * Java API code for job PnlMsdcLivVideo
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcLivVideo {
	/**
		* VecVDo (full: VecVMsdcLivVideoDo)
		*/
	public static class VecVDo {

		public static final int BUTMASTERCLICK = 1;
		public static final int BUTPLAYCLICK = 2;
		public static final int BUTSTOPCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butmasterclick")) return BUTMASTERCLICK;
			if (s.equals("butplayclick")) return BUTPLAYCLICK;
			if (s.equals("butstopclick")) return BUTSTOPCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMASTERCLICK) return("ButMasterClick");
			if (ix == BUTPLAYCLICK) return("ButPlayClick");
			if (ix == BUTSTOPCLICK) return("ButStopClick");

			return "";
		};

	};

	/**
		* VecVSource (full: VecVMsdcLivVideoSource)
		*/
	public static class VecVSource {

		public static final int VOID = 1;
		public static final int VISL = 2;
		public static final int VISR = 3;
		public static final int LWIR = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("void")) return VOID;
			if (s.equals("visl")) return VISL;
			if (s.equals("visr")) return VISR;
			if (s.equals("lwir")) return LWIR;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == VOID) return("void");
			if (ix == VISL) return("visl");
			if (ix == VISR) return("visr");
			if (ix == LWIR) return("lwir");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacMsdcLivVideo)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPSRC = 1;
		public static final int NUMFPUPRES = 2;
		public static final int SLDEXT = 3;
		public static final int SLDFCS = 4;

		public ContIac(
					int numFPupSrc
					, int numFPupRes
					, double SldExt
					, double SldFcs
				) {
			this.numFPupSrc = numFPupSrc;
			this.numFPupRes = numFPupRes;
			this.SldExt = SldExt;
			this.SldFcs = SldFcs;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPSRC, NUMFPUPRES, SLDEXT, SLDFCS));
		};

		public int numFPupSrc;
		public int numFPupRes;
		public double SldExt;
		public double SldFcs;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacMsdcLivVideo");

			String itemtag = "ContitemIacMsdcLivVideo";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupSrc = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSrc", mask, NUMFPUPSRC);
				numFPupRes = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRes", mask, NUMFPUPRES);
				SldExt = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldExt", mask, SLDEXT);
				SldFcs = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldFcs", mask, SLDFCS);

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
			if (difftag.isEmpty()) difftag = "ContIacMsdcLivVideo";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacMsdcLivVideo";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSrc", numFPupSrc);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRes", numFPupRes);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldExt", SldExt);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFcs", SldFcs);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupSrc == comp.numFPupSrc) items.add(NUMFPUPSRC);
			if (numFPupRes == comp.numFPupRes) items.add(NUMFPUPRES);
			if (Xmlio.compareDouble(SldExt, comp.SldExt) < 1.0e-4) items.add(SLDEXT);
			if (Xmlio.compareDouble(SldFcs, comp.SldFcs) < 1.0e-4) items.add(SLDFCS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPSRC, NUMFPUPRES, SLDEXT, SLDFCS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfMsdcLivVideo)
	  */
	public class ContInf extends Block {

		public static final int BUTMASTERON = 1;

		public ContInf(
					boolean ButMasterOn
				) {
			this.ButMasterOn = ButMasterOn;

			mask = new HashSet<Integer>(Arrays.asList(BUTMASTERON));
		};

		public boolean ButMasterOn;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcLivVideo");

			String itemtag = "ContitemInfMsdcLivVideo";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButMasterOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButMasterOn", mask, BUTMASTERON);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButMasterOn == comp.ButMasterOn) items.add(BUTMASTERON);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTMASTERON));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppMsdcLivVideo)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcLivVideo");

			String itemtag = "StatitemAppMsdcLivVideo";

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
	  * StatShr (full: StatShrMsdcLivVideo)
	  */
	public class StatShr extends Block {

		public static final int PUPRESAVAIL = 1;
		public static final int BUTPLAYACTIVE = 2;
		public static final int BUTSTOPACTIVE = 3;
		public static final int SLDEXTAVAIL = 4;
		public static final int SLDEXTACTIVE = 5;
		public static final int SLDEXTMIN = 6;
		public static final int SLDEXTMAX = 7;
		public static final int SLDEXTRAST = 8;
		public static final int SLDFCSAVAIL = 9;
		public static final int SLDFCSACTIVE = 10;
		public static final int SLDFCSMIN = 11;
		public static final int SLDFCSMAX = 12;

		public StatShr(
					boolean PupResAvail
					, boolean ButPlayActive
					, boolean ButStopActive
					, boolean SldExtAvail
					, boolean SldExtActive
					, double SldExtMin
					, double SldExtMax
					, double SldExtRast
					, boolean SldFcsAvail
					, boolean SldFcsActive
					, double SldFcsMin
					, double SldFcsMax
				) {
			this.PupResAvail = PupResAvail;
			this.ButPlayActive = ButPlayActive;
			this.ButStopActive = ButStopActive;
			this.SldExtAvail = SldExtAvail;
			this.SldExtActive = SldExtActive;
			this.SldExtMin = SldExtMin;
			this.SldExtMax = SldExtMax;
			this.SldExtRast = SldExtRast;
			this.SldFcsAvail = SldFcsAvail;
			this.SldFcsActive = SldFcsActive;
			this.SldFcsMin = SldFcsMin;
			this.SldFcsMax = SldFcsMax;

			mask = new HashSet<Integer>(Arrays.asList(PUPRESAVAIL, BUTPLAYACTIVE, BUTSTOPACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSAVAIL, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX));
		};

		public boolean PupResAvail;
		public boolean ButPlayActive;
		public boolean ButStopActive;
		public boolean SldExtAvail;
		public boolean SldExtActive;
		public double SldExtMin;
		public double SldExtMax;
		public double SldExtRast;
		public boolean SldFcsAvail;
		public boolean SldFcsActive;
		public double SldFcsMin;
		public double SldFcsMax;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcLivVideo");

			String itemtag = "StatitemShrMsdcLivVideo";

			if (Xmlio.checkXPath(doc, basexpath)) {
				PupResAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupResAvail", mask, PUPRESAVAIL);
				ButPlayActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPlayActive", mask, BUTPLAYACTIVE);
				ButStopActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStopActive", mask, BUTSTOPACTIVE);
				SldExtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtAvail", mask, SLDEXTAVAIL);
				SldExtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtActive", mask, SLDEXTACTIVE);
				SldExtMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtMin", mask, SLDEXTMIN);
				SldExtMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtMax", mask, SLDEXTMAX);
				SldExtRast = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldExtRast", mask, SLDEXTRAST);
				SldFcsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsAvail", mask, SLDFCSAVAIL);
				SldFcsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsActive", mask, SLDFCSACTIVE);
				SldFcsMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsMin", mask, SLDFCSMIN);
				SldFcsMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFcsMax", mask, SLDFCSMAX);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (PupResAvail == comp.PupResAvail) items.add(PUPRESAVAIL);
			if (ButPlayActive == comp.ButPlayActive) items.add(BUTPLAYACTIVE);
			if (ButStopActive == comp.ButStopActive) items.add(BUTSTOPACTIVE);
			if (SldExtAvail == comp.SldExtAvail) items.add(SLDEXTAVAIL);
			if (SldExtActive == comp.SldExtActive) items.add(SLDEXTACTIVE);
			if (Xmlio.compareDouble(SldExtMin, comp.SldExtMin) < 1.0e-4) items.add(SLDEXTMIN);
			if (Xmlio.compareDouble(SldExtMax, comp.SldExtMax) < 1.0e-4) items.add(SLDEXTMAX);
			if (Xmlio.compareDouble(SldExtRast, comp.SldExtRast) < 1.0e-4) items.add(SLDEXTRAST);
			if (SldFcsAvail == comp.SldFcsAvail) items.add(SLDFCSAVAIL);
			if (SldFcsActive == comp.SldFcsActive) items.add(SLDFCSACTIVE);
			if (Xmlio.compareDouble(SldFcsMin, comp.SldFcsMin) < 1.0e-4) items.add(SLDFCSMIN);
			if (Xmlio.compareDouble(SldFcsMax, comp.SldFcsMax) < 1.0e-4) items.add(SLDFCSMAX);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(PUPRESAVAIL, BUTPLAYACTIVE, BUTSTOPACTIVE, SLDEXTAVAIL, SLDEXTACTIVE, SLDEXTMIN, SLDEXTMAX, SLDEXTRAST, SLDFCSAVAIL, SLDFCSACTIVE, SLDFCSMIN, SLDFCSMAX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcLivVideo)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRC = 2;
		public static final int CPTRES = 3;
		public static final int CPTEXT = 4;
		public static final int CPTFCS = 5;

		public Tag(
					String Cpt
					, String CptSrc
					, String CptRes
					, String CptExt
					, String CptFcs
				) {
			this.Cpt = Cpt;
			this.CptSrc = CptSrc;
			this.CptRes = CptRes;
			this.CptExt = CptExt;
			this.CptFcs = CptFcs;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRC, CPTRES, CPTEXT, CPTFCS));
		};

		public String Cpt;
		public String CptSrc;
		public String CptRes;
		public String CptExt;
		public String CptFcs;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcLivVideo");

			String itemtag = "TagitemMsdcLivVideo";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrc", mask, CPTSRC);
				CptRes = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRes", mask, CPTRES);
				CptExt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptExt", mask, CPTEXT);
				CptFcs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFcs", mask, CPTFCS);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptSrc.equals(comp.CptSrc)) items.add(CPTSRC);
			if (CptRes.equals(comp.CptRes)) items.add(CPTRES);
			if (CptExt.equals(comp.CptExt)) items.add(CPTEXT);
			if (CptFcs.equals(comp.CptFcs)) items.add(CPTFCS);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRC, CPTRES, CPTEXT, CPTFCS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcLivVideoData)
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
			super(VecMsdcVDpch.DPCHAPPMSDCLIVVIDEODATA, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcLivVideoData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcLivVideoDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCLIVVIDEODO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcLivVideoDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcLivVideoData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPRES = 4;
		public static final int FEEDFPUPSRC = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCLIVVIDEODATA);

			contiac = new ContIac(0, 0, 0.0, 0.0);
			continf = new ContInf(false);
			feedFPupRes = new Feed("FeedFPupRes");
			feedFPupSrc = new Feed("FeedFPupSrc");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, 0.0, 0.0, 0.0, false, false, 0.0, 0.0);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupRes;
		public Feed feedFPupSrc;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPRES)) ss.add("feedFPupRes");
			if (has(FEEDFPUPSRC)) ss.add("feedFPupSrc");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcLivVideoData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupRes.readXML(doc, basexpath, true)) add(FEEDFPUPRES);
				if (feedFPupSrc.readXML(doc, basexpath, true)) add(FEEDFPUPSRC);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0.0, 0.0);
				continf = new ContInf(false);
				feedFPupRes = new Feed("FeedFPupRes");
				feedFPupSrc = new Feed("FeedFPupSrc");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, 0.0, 0.0, 0.0, false, false, 0.0, 0.0);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

	/**
		* DpchEngLive (full: DpchEngMsdcLivVideoLive)
		*/
	public class DpchEngLive extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int RGB = 3;
		public static final int RED = 4;
		public static final int GREEN = 5;
		public static final int BLUE = 6;
		public static final int GRAY = 7;

		public DpchEngLive() {
			super(VecMsdcVDpch.DPCHENGMSDCLIVVIDEOLIVE);

			continf = new ContInf(false);
		};

		public ContInf continf;
		public ArrayList<Integer> rgb;
		public ArrayList<Integer> red;
		public ArrayList<Integer> green;
		public ArrayList<Integer> blue;
		public ArrayList<Integer> gray;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(RGB)) ss.add("rgb");
			if (has(RED)) ss.add("red");
			if (has(GREEN)) ss.add("green");
			if (has(BLUE)) ss.add("blue");
			if (has(GRAY)) ss.add("gray");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcLivVideoLive");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				rgb = Xmlio.extractUtinyintvecUclc(doc, basexpath, "rgb", "", mask, RGB);
				red = Xmlio.extractUtinyintvecUclc(doc, basexpath, "red", "", mask, RED);
				green = Xmlio.extractUtinyintvecUclc(doc, basexpath, "green", "", mask, GREEN);
				blue = Xmlio.extractUtinyintvecUclc(doc, basexpath, "blue", "", mask, BLUE);
				gray = Xmlio.extractUsmallintvecUclc(doc, basexpath, "gray", "", mask, GRAY);
			} else {
				scrJref = "";
				continf = new ContInf(false);
				rgb = new ArrayList<Integer>();
				red = new ArrayList<Integer>();
				green = new ArrayList<Integer>();
				blue = new ArrayList<Integer>();
				gray = new ArrayList<Integer>();
			};
		};

	};

};

