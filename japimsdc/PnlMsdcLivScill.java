/**
  * \file PnlMsdcLivScill.java
  * Java API code for job PnlMsdcLivScill
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcLivScill {
	/**
		* VecVDo (full: VecVMsdcLivScillDo)
		*/
	public static class VecVDo {

		public static final int BUTMASTERCLICK = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butmasterclick")) return BUTMASTERCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMASTERCLICK) return("ButMasterClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacMsdcLivScill)
	  */
	public class ContIac extends Block {

		public static final int SLDFLD = 1;
		public static final int SLDSPT = 2;

		public ContIac(
					double SldFld
					, double SldSpt
				) {
			this.SldFld = SldFld;
			this.SldSpt = SldSpt;

			mask = new HashSet<Integer>(Arrays.asList(SLDFLD, SLDSPT));
		};

		public double SldFld;
		public double SldSpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacMsdcLivScill");

			String itemtag = "ContitemIacMsdcLivScill";

			if (Xmlio.checkXPath(doc, basexpath)) {
				SldFld = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldFld", mask, SLDFLD);
				SldSpt = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldSpt", mask, SLDSPT);

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
			if (difftag.isEmpty()) difftag = "ContIacMsdcLivScill";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacMsdcLivScill";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFld", SldFld);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldSpt", SldSpt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Xmlio.compareDouble(SldFld, comp.SldFld) < 1.0e-4) items.add(SLDFLD);
			if (Xmlio.compareDouble(SldSpt, comp.SldSpt) < 1.0e-4) items.add(SLDSPT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SLDFLD, SLDSPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfMsdcLivScill)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcLivScill");

			String itemtag = "ContitemInfMsdcLivScill";

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
	  * StatApp (full: StatAppMsdcLivScill)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcLivScill");

			String itemtag = "StatitemAppMsdcLivScill";

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
	  * StatShr (full: StatShrMsdcLivScill)
	  */
	public class StatShr extends Block {

		public static final int SLDFLDACTIVE = 1;
		public static final int SLDFLDMIN = 2;
		public static final int SLDFLDMAX = 3;
		public static final int SLDSPTACTIVE = 4;
		public static final int SLDSPTMIN = 5;
		public static final int SLDSPTMAX = 6;

		public StatShr(
					boolean SldFldActive
					, double SldFldMin
					, double SldFldMax
					, boolean SldSptActive
					, double SldSptMin
					, double SldSptMax
				) {
			this.SldFldActive = SldFldActive;
			this.SldFldMin = SldFldMin;
			this.SldFldMax = SldFldMax;
			this.SldSptActive = SldSptActive;
			this.SldSptMin = SldSptMin;
			this.SldSptMax = SldSptMax;

			mask = new HashSet<Integer>(Arrays.asList(SLDFLDACTIVE, SLDFLDMIN, SLDFLDMAX, SLDSPTACTIVE, SLDSPTMIN, SLDSPTMAX));
		};

		public boolean SldFldActive;
		public double SldFldMin;
		public double SldFldMax;
		public boolean SldSptActive;
		public double SldSptMin;
		public double SldSptMax;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcLivScill");

			String itemtag = "StatitemShrMsdcLivScill";

			if (Xmlio.checkXPath(doc, basexpath)) {
				SldFldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFldActive", mask, SLDFLDACTIVE);
				SldFldMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFldMin", mask, SLDFLDMIN);
				SldFldMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFldMax", mask, SLDFLDMAX);
				SldSptActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldSptActive", mask, SLDSPTACTIVE);
				SldSptMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldSptMin", mask, SLDSPTMIN);
				SldSptMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldSptMax", mask, SLDSPTMAX);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (SldFldActive == comp.SldFldActive) items.add(SLDFLDACTIVE);
			if (Xmlio.compareDouble(SldFldMin, comp.SldFldMin) < 1.0e-4) items.add(SLDFLDMIN);
			if (Xmlio.compareDouble(SldFldMax, comp.SldFldMax) < 1.0e-4) items.add(SLDFLDMAX);
			if (SldSptActive == comp.SldSptActive) items.add(SLDSPTACTIVE);
			if (Xmlio.compareDouble(SldSptMin, comp.SldSptMin) < 1.0e-4) items.add(SLDSPTMIN);
			if (Xmlio.compareDouble(SldSptMax, comp.SldSptMax) < 1.0e-4) items.add(SLDSPTMAX);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SLDFLDACTIVE, SLDFLDMIN, SLDFLDMAX, SLDSPTACTIVE, SLDSPTMIN, SLDSPTMAX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcLivScill)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTFLD = 2;
		public static final int CPTSPT = 3;

		public Tag(
					String Cpt
					, String CptFld
					, String CptSpt
				) {
			this.Cpt = Cpt;
			this.CptFld = CptFld;
			this.CptSpt = CptSpt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTFLD, CPTSPT));
		};

		public String Cpt;
		public String CptFld;
		public String CptSpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcLivScill");

			String itemtag = "TagitemMsdcLivScill";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptFld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFld", mask, CPTFLD);
				CptSpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSpt", mask, CPTSPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptFld.equals(comp.CptFld)) items.add(CPTFLD);
			if (CptSpt.equals(comp.CptSpt)) items.add(CPTSPT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTFLD, CPTSPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcLivScillData)
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
			super(VecMsdcVDpch.DPCHAPPMSDCLIVSCILLDATA, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcLivScillData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcLivScillDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCLIVSCILLDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcLivScillDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcLivScillData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCLIVSCILLDATA);

			contiac = new ContIac(0.0, 0.0);
			continf = new ContInf(false);
			statapp = new StatApp(0);
			statshr = new StatShr(false, 0.0, 0.0, false, 0.0, 0.0);
			tag = new Tag("", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcLivScillData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0.0, 0.0);
				continf = new ContInf(false);
				statapp = new StatApp(0);
				statshr = new StatShr(false, 0.0, 0.0, false, 0.0, 0.0);
				tag = new Tag("", "", "");
			};
		};

	};

};

