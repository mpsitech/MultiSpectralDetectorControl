/**
  * \file PnlMsdcScfActu.java
  * Java API code for job PnlMsdcScfActu
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcScfActu {
	/**
		* VecVDo (full: VecVMsdcScfActuDo)
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
	  * ContIac (full: ContIacMsdcScfActu)
	  */
	public class ContIac extends Block {

		public static final int SLDSTM = 1;
		public static final int SLDSTX = 2;
		public static final int SLDSPM = 3;
		public static final int SLDSPX = 4;

		public ContIac(
					double SldStm
					, double SldStx
					, double SldSpm
					, double SldSpx
				) {
			this.SldStm = SldStm;
			this.SldStx = SldStx;
			this.SldSpm = SldSpm;
			this.SldSpx = SldSpx;

			mask = new HashSet<Integer>(Arrays.asList(SLDSTM, SLDSTX, SLDSPM, SLDSPX));
		};

		public double SldStm;
		public double SldStx;
		public double SldSpm;
		public double SldSpx;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacMsdcScfActu");

			String itemtag = "ContitemIacMsdcScfActu";

			if (Xmlio.checkXPath(doc, basexpath)) {
				SldStm = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldStm", mask, SLDSTM);
				SldStx = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldStx", mask, SLDSTX);
				SldSpm = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldSpm", mask, SLDSPM);
				SldSpx = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldSpx", mask, SLDSPX);

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
			if (difftag.isEmpty()) difftag = "ContIacMsdcScfActu";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacMsdcScfActu";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldStm", SldStm);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldStx", SldStx);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldSpm", SldSpm);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldSpx", SldSpx);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Xmlio.compareDouble(SldStm, comp.SldStm) < 1.0e-4) items.add(SLDSTM);
			if (Xmlio.compareDouble(SldStx, comp.SldStx) < 1.0e-4) items.add(SLDSTX);
			if (Xmlio.compareDouble(SldSpm, comp.SldSpm) < 1.0e-4) items.add(SLDSPM);
			if (Xmlio.compareDouble(SldSpx, comp.SldSpx) < 1.0e-4) items.add(SLDSPX);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SLDSTM, SLDSTX, SLDSPM, SLDSPX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfMsdcScfActu)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcScfActu");

			String itemtag = "ContitemInfMsdcScfActu";

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
	  * StatApp (full: StatAppMsdcScfActu)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcScfActu");

			String itemtag = "StatitemAppMsdcScfActu";

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
	  * StatShr (full: StatShrMsdcScfActu)
	  */
	public class StatShr extends Block {

		public static final int SLDSTMMIN = 1;
		public static final int SLDSTMMAX = 2;
		public static final int SLDSTMRAST = 3;
		public static final int SLDSTXMIN = 4;
		public static final int SLDSTXMAX = 5;
		public static final int SLDSTXRAST = 6;
		public static final int SLDSPMMIN = 7;
		public static final int SLDSPMMAX = 8;
		public static final int SLDSPMRAST = 9;
		public static final int SLDSPXMIN = 10;
		public static final int SLDSPXMAX = 11;
		public static final int SLDSPXRAST = 12;

		public StatShr(
					double SldStmMin
					, double SldStmMax
					, double SldStmRast
					, double SldStxMin
					, double SldStxMax
					, double SldStxRast
					, double SldSpmMin
					, double SldSpmMax
					, double SldSpmRast
					, double SldSpxMin
					, double SldSpxMax
					, double SldSpxRast
				) {
			this.SldStmMin = SldStmMin;
			this.SldStmMax = SldStmMax;
			this.SldStmRast = SldStmRast;
			this.SldStxMin = SldStxMin;
			this.SldStxMax = SldStxMax;
			this.SldStxRast = SldStxRast;
			this.SldSpmMin = SldSpmMin;
			this.SldSpmMax = SldSpmMax;
			this.SldSpmRast = SldSpmRast;
			this.SldSpxMin = SldSpxMin;
			this.SldSpxMax = SldSpxMax;
			this.SldSpxRast = SldSpxRast;

			mask = new HashSet<Integer>(Arrays.asList(SLDSTMMIN, SLDSTMMAX, SLDSTMRAST, SLDSTXMIN, SLDSTXMAX, SLDSTXRAST, SLDSPMMIN, SLDSPMMAX, SLDSPMRAST, SLDSPXMIN, SLDSPXMAX, SLDSPXRAST));
		};

		public double SldStmMin;
		public double SldStmMax;
		public double SldStmRast;
		public double SldStxMin;
		public double SldStxMax;
		public double SldStxRast;
		public double SldSpmMin;
		public double SldSpmMax;
		public double SldSpmRast;
		public double SldSpxMin;
		public double SldSpxMax;
		public double SldSpxRast;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcScfActu");

			String itemtag = "StatitemShrMsdcScfActu";

			if (Xmlio.checkXPath(doc, basexpath)) {
				SldStmMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldStmMin", mask, SLDSTMMIN);
				SldStmMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldStmMax", mask, SLDSTMMAX);
				SldStmRast = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldStmRast", mask, SLDSTMRAST);
				SldStxMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldStxMin", mask, SLDSTXMIN);
				SldStxMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldStxMax", mask, SLDSTXMAX);
				SldStxRast = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldStxRast", mask, SLDSTXRAST);
				SldSpmMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldSpmMin", mask, SLDSPMMIN);
				SldSpmMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldSpmMax", mask, SLDSPMMAX);
				SldSpmRast = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldSpmRast", mask, SLDSPMRAST);
				SldSpxMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldSpxMin", mask, SLDSPXMIN);
				SldSpxMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldSpxMax", mask, SLDSPXMAX);
				SldSpxRast = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldSpxRast", mask, SLDSPXRAST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Xmlio.compareDouble(SldStmMin, comp.SldStmMin) < 1.0e-4) items.add(SLDSTMMIN);
			if (Xmlio.compareDouble(SldStmMax, comp.SldStmMax) < 1.0e-4) items.add(SLDSTMMAX);
			if (Xmlio.compareDouble(SldStmRast, comp.SldStmRast) < 1.0e-4) items.add(SLDSTMRAST);
			if (Xmlio.compareDouble(SldStxMin, comp.SldStxMin) < 1.0e-4) items.add(SLDSTXMIN);
			if (Xmlio.compareDouble(SldStxMax, comp.SldStxMax) < 1.0e-4) items.add(SLDSTXMAX);
			if (Xmlio.compareDouble(SldStxRast, comp.SldStxRast) < 1.0e-4) items.add(SLDSTXRAST);
			if (Xmlio.compareDouble(SldSpmMin, comp.SldSpmMin) < 1.0e-4) items.add(SLDSPMMIN);
			if (Xmlio.compareDouble(SldSpmMax, comp.SldSpmMax) < 1.0e-4) items.add(SLDSPMMAX);
			if (Xmlio.compareDouble(SldSpmRast, comp.SldSpmRast) < 1.0e-4) items.add(SLDSPMRAST);
			if (Xmlio.compareDouble(SldSpxMin, comp.SldSpxMin) < 1.0e-4) items.add(SLDSPXMIN);
			if (Xmlio.compareDouble(SldSpxMax, comp.SldSpxMax) < 1.0e-4) items.add(SLDSPXMAX);
			if (Xmlio.compareDouble(SldSpxRast, comp.SldSpxRast) < 1.0e-4) items.add(SLDSPXRAST);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SLDSTMMIN, SLDSTMMAX, SLDSTMRAST, SLDSTXMIN, SLDSTXMAX, SLDSTXRAST, SLDSPMMIN, SLDSPMMAX, SLDSPMRAST, SLDSPXMIN, SLDSPXMAX, SLDSPXRAST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcScfActu)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int HDGSRV = 2;
		public static final int CPTSTM = 3;
		public static final int CPTSTX = 4;
		public static final int CPTSPM = 5;
		public static final int CPTSPX = 6;

		public Tag(
					String Cpt
					, String HdgSrv
					, String CptStm
					, String CptStx
					, String CptSpm
					, String CptSpx
				) {
			this.Cpt = Cpt;
			this.HdgSrv = HdgSrv;
			this.CptStm = CptStm;
			this.CptStx = CptStx;
			this.CptSpm = CptSpm;
			this.CptSpx = CptSpx;

			mask = new HashSet<Integer>(Arrays.asList(CPT, HDGSRV, CPTSTM, CPTSTX, CPTSPM, CPTSPX));
		};

		public String Cpt;
		public String HdgSrv;
		public String CptStm;
		public String CptStx;
		public String CptSpm;
		public String CptSpx;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcScfActu");

			String itemtag = "TagitemMsdcScfActu";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				HdgSrv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgSrv", mask, HDGSRV);
				CptStm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptStm", mask, CPTSTM);
				CptStx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptStx", mask, CPTSTX);
				CptSpm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSpm", mask, CPTSPM);
				CptSpx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSpx", mask, CPTSPX);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (HdgSrv.equals(comp.HdgSrv)) items.add(HDGSRV);
			if (CptStm.equals(comp.CptStm)) items.add(CPTSTM);
			if (CptStx.equals(comp.CptStx)) items.add(CPTSTX);
			if (CptSpm.equals(comp.CptSpm)) items.add(CPTSPM);
			if (CptSpx.equals(comp.CptSpx)) items.add(CPTSPX);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, HDGSRV, CPTSTM, CPTSTX, CPTSPM, CPTSPX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcScfActuData)
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
			super(VecMsdcVDpch.DPCHAPPMSDCSCFACTUDATA, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcScfActuData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcScfActuDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCSCFACTUDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcScfActuDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcScfActuData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCSCFACTUDATA);

			contiac = new ContIac(0.0, 0.0, 0.0, 0.0);
			continf = new ContInf(false);
			statapp = new StatApp(0);
			statshr = new StatShr(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			tag = new Tag("", "", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcScfActuData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0.0, 0.0, 0.0, 0.0);
				continf = new ContInf(false);
				statapp = new StatApp(0);
				statshr = new StatShr(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};

