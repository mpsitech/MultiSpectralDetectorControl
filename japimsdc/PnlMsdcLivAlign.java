/**
  * \file PnlMsdcLivAlign.java
  * Java API code for job PnlMsdcLivAlign
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcLivAlign {
	/**
		* VecVDo (full: VecVMsdcLivAlignDo)
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
	  * ContIac (full: ContIacMsdcLivAlign)
	  */
	public class ContIac extends Block {

		public static final int SLDTHE = 1;
		public static final int SLDPHI = 2;

		public ContIac(
					double SldThe
					, double SldPhi
				) {
			this.SldThe = SldThe;
			this.SldPhi = SldPhi;

			mask = new HashSet<Integer>(Arrays.asList(SLDTHE, SLDPHI));
		};

		public double SldThe;
		public double SldPhi;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacMsdcLivAlign");

			String itemtag = "ContitemIacMsdcLivAlign";

			if (Xmlio.checkXPath(doc, basexpath)) {
				SldThe = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldThe", mask, SLDTHE);
				SldPhi = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldPhi", mask, SLDPHI);

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
			if (difftag.isEmpty()) difftag = "ContIacMsdcLivAlign";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacMsdcLivAlign";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldThe", SldThe);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldPhi", SldPhi);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Xmlio.compareDouble(SldThe, comp.SldThe) < 1.0e-4) items.add(SLDTHE);
			if (Xmlio.compareDouble(SldPhi, comp.SldPhi) < 1.0e-4) items.add(SLDPHI);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SLDTHE, SLDPHI));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfMsdcLivAlign)
	  */
	public class ContInf extends Block {

		public static final int BUTMASTERON = 1;
		public static final int TXTAPH = 2;
		public static final int TXTBTA = 3;

		public ContInf(
					boolean ButMasterOn
					, String TxtAph
					, String TxtBta
				) {
			this.ButMasterOn = ButMasterOn;
			this.TxtAph = TxtAph;
			this.TxtBta = TxtBta;

			mask = new HashSet<Integer>(Arrays.asList(BUTMASTERON, TXTAPH, TXTBTA));
		};

		public boolean ButMasterOn;
		public String TxtAph;
		public String TxtBta;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcLivAlign");

			String itemtag = "ContitemInfMsdcLivAlign";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButMasterOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButMasterOn", mask, BUTMASTERON);
				TxtAph = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtAph", mask, TXTAPH);
				TxtBta = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtBta", mask, TXTBTA);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButMasterOn == comp.ButMasterOn) items.add(BUTMASTERON);
			if (TxtAph.equals(comp.TxtAph)) items.add(TXTAPH);
			if (TxtBta.equals(comp.TxtBta)) items.add(TXTBTA);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTMASTERON, TXTAPH, TXTBTA));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrMsdcLivAlign)
	  */
	public class StatShr extends Block {

		public static final int IXMSDCVEXPSTATE = 1;
		public static final int SLDTHEACTIVE = 2;
		public static final int SLDTHEMIN = 3;
		public static final int SLDTHEMAX = 4;
		public static final int SLDPHIACTIVE = 5;
		public static final int SLDPHIMIN = 6;
		public static final int SLDPHIMAX = 7;

		public StatShr(
					int ixMsdcVExpstate
					, boolean SldTheActive
					, double SldTheMin
					, double SldTheMax
					, boolean SldPhiActive
					, double SldPhiMin
					, double SldPhiMax
				) {
			this.ixMsdcVExpstate = ixMsdcVExpstate;
			this.SldTheActive = SldTheActive;
			this.SldTheMin = SldTheMin;
			this.SldTheMax = SldTheMax;
			this.SldPhiActive = SldPhiActive;
			this.SldPhiMin = SldPhiMin;
			this.SldPhiMax = SldPhiMax;

			mask = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE, SLDTHEACTIVE, SLDTHEMIN, SLDTHEMAX, SLDPHIACTIVE, SLDPHIMIN, SLDPHIMAX));
		};

		public int ixMsdcVExpstate;
		public boolean SldTheActive;
		public double SldTheMin;
		public double SldTheMax;
		public boolean SldPhiActive;
		public double SldPhiMin;
		public double SldPhiMax;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxMsdcVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcLivAlign");

			String itemtag = "StatitemShrMsdcLivAlign";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxMsdcVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", mask, IXMSDCVEXPSTATE);
				ixMsdcVExpstate = VecMsdcVExpstate.getIx(srefIxMsdcVExpstate);
				SldTheActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTheActive", mask, SLDTHEACTIVE);
				SldTheMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTheMin", mask, SLDTHEMIN);
				SldTheMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTheMax", mask, SLDTHEMAX);
				SldPhiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldPhiActive", mask, SLDPHIACTIVE);
				SldPhiMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldPhiMin", mask, SLDPHIMIN);
				SldPhiMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldPhiMax", mask, SLDPHIMAX);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixMsdcVExpstate == comp.ixMsdcVExpstate) items.add(IXMSDCVEXPSTATE);
			if (SldTheActive == comp.SldTheActive) items.add(SLDTHEACTIVE);
			if (Xmlio.compareDouble(SldTheMin, comp.SldTheMin) < 1.0e-4) items.add(SLDTHEMIN);
			if (Xmlio.compareDouble(SldTheMax, comp.SldTheMax) < 1.0e-4) items.add(SLDTHEMAX);
			if (SldPhiActive == comp.SldPhiActive) items.add(SLDPHIACTIVE);
			if (Xmlio.compareDouble(SldPhiMin, comp.SldPhiMin) < 1.0e-4) items.add(SLDPHIMIN);
			if (Xmlio.compareDouble(SldPhiMax, comp.SldPhiMax) < 1.0e-4) items.add(SLDPHIMAX);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE, SLDTHEACTIVE, SLDTHEMIN, SLDTHEMAX, SLDPHIACTIVE, SLDPHIMIN, SLDPHIMAX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcLivAlign)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTAPH = 2;
		public static final int CPTBTA = 3;
		public static final int CPTTHE = 4;
		public static final int CPTPHI = 5;

		public Tag(
					String Cpt
					, String CptAph
					, String CptBta
					, String CptThe
					, String CptPhi
				) {
			this.Cpt = Cpt;
			this.CptAph = CptAph;
			this.CptBta = CptBta;
			this.CptThe = CptThe;
			this.CptPhi = CptPhi;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTAPH, CPTBTA, CPTTHE, CPTPHI));
		};

		public String Cpt;
		public String CptAph;
		public String CptBta;
		public String CptThe;
		public String CptPhi;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcLivAlign");

			String itemtag = "TagitemMsdcLivAlign";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptAph = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAph", mask, CPTAPH);
				CptBta = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptBta", mask, CPTBTA);
				CptThe = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptThe", mask, CPTTHE);
				CptPhi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPhi", mask, CPTPHI);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptAph.equals(comp.CptAph)) items.add(CPTAPH);
			if (CptBta.equals(comp.CptBta)) items.add(CPTBTA);
			if (CptThe.equals(comp.CptThe)) items.add(CPTTHE);
			if (CptPhi.equals(comp.CptPhi)) items.add(CPTPHI);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTAPH, CPTBTA, CPTTHE, CPTPHI));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcLivAlignData)
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
			super(VecMsdcVDpch.DPCHAPPMSDCLIVALIGNDATA, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcLivAlignData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcLivAlignDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCLIVALIGNDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcLivAlignDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcLivAlignData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCLIVALIGNDATA);

			contiac = new ContIac(0.0, 0.0);
			continf = new ContInf(false, "", "");
			statshr = new StatShr(0, false, 0.0, 0.0, false, 0.0, 0.0);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcLivAlignData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0.0, 0.0);
				continf = new ContInf(false, "", "");
				statshr = new StatShr(0, false, 0.0, 0.0, false, 0.0, 0.0);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};

