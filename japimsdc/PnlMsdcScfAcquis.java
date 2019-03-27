/**
  * \file PnlMsdcScfAcquis.java
  * Java API code for job PnlMsdcScfAcquis
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcScfAcquis {
	/**
		* VecVDo (full: VecVMsdcScfAcquisDo)
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
	  * ContIac (full: ContIacMsdcScfAcquis)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPVTY = 1;
		public static final int TXFVLP = 2;
		public static final int TXFVRP = 3;

		public ContIac(
					int numFPupVty
					, String TxfVlp
					, String TxfVrp
				) {
			this.numFPupVty = numFPupVty;
			this.TxfVlp = TxfVlp;
			this.TxfVrp = TxfVrp;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPVTY, TXFVLP, TXFVRP));
		};

		public int numFPupVty;
		public String TxfVlp;
		public String TxfVrp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacMsdcScfAcquis");

			String itemtag = "ContitemIacMsdcScfAcquis";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupVty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupVty", mask, NUMFPUPVTY);
				TxfVlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfVlp", mask, TXFVLP);
				TxfVrp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfVrp", mask, TXFVRP);

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
			if (difftag.isEmpty()) difftag = "ContIacMsdcScfAcquis";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacMsdcScfAcquis";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupVty", numFPupVty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfVlp", TxfVlp);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfVrp", TxfVrp);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupVty == comp.numFPupVty) items.add(NUMFPUPVTY);
			if (TxfVlp.equals(comp.TxfVlp)) items.add(TXFVLP);
			if (TxfVrp.equals(comp.TxfVrp)) items.add(TXFVRP);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPVTY, TXFVLP, TXFVRP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfMsdcScfAcquis)
	  */
	public class ContInf extends Block {

		public static final int BUTMASTERON = 1;
		public static final int TXTISN = 2;
		public static final int TXTIPS = 3;
		public static final int TXTIFL = 4;
		public static final int TXTIFN = 5;
		public static final int TXTVPS = 6;
		public static final int TXTVFL = 7;
		public static final int TXTVFN = 8;

		public ContInf(
					boolean ButMasterOn
					, String TxtIsn
					, String TxtIps
					, String TxtIfl
					, String TxtIfn
					, String TxtVps
					, String TxtVfl
					, String TxtVfn
				) {
			this.ButMasterOn = ButMasterOn;
			this.TxtIsn = TxtIsn;
			this.TxtIps = TxtIps;
			this.TxtIfl = TxtIfl;
			this.TxtIfn = TxtIfn;
			this.TxtVps = TxtVps;
			this.TxtVfl = TxtVfl;
			this.TxtVfn = TxtVfn;

			mask = new HashSet<Integer>(Arrays.asList(BUTMASTERON, TXTISN, TXTIPS, TXTIFL, TXTIFN, TXTVPS, TXTVFL, TXTVFN));
		};

		public boolean ButMasterOn;
		public String TxtIsn;
		public String TxtIps;
		public String TxtIfl;
		public String TxtIfn;
		public String TxtVps;
		public String TxtVfl;
		public String TxtVfn;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcScfAcquis");

			String itemtag = "ContitemInfMsdcScfAcquis";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButMasterOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButMasterOn", mask, BUTMASTERON);
				TxtIsn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtIsn", mask, TXTISN);
				TxtIps = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtIps", mask, TXTIPS);
				TxtIfl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtIfl", mask, TXTIFL);
				TxtIfn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtIfn", mask, TXTIFN);
				TxtVps = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVps", mask, TXTVPS);
				TxtVfl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVfl", mask, TXTVFL);
				TxtVfn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVfn", mask, TXTVFN);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButMasterOn == comp.ButMasterOn) items.add(BUTMASTERON);
			if (TxtIsn.equals(comp.TxtIsn)) items.add(TXTISN);
			if (TxtIps.equals(comp.TxtIps)) items.add(TXTIPS);
			if (TxtIfl.equals(comp.TxtIfl)) items.add(TXTIFL);
			if (TxtIfn.equals(comp.TxtIfn)) items.add(TXTIFN);
			if (TxtVps.equals(comp.TxtVps)) items.add(TXTVPS);
			if (TxtVfl.equals(comp.TxtVfl)) items.add(TXTVFL);
			if (TxtVfn.equals(comp.TxtVfn)) items.add(TXTVFN);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTMASTERON, TXTISN, TXTIPS, TXTIFL, TXTIFN, TXTVPS, TXTVFL, TXTVFN));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppMsdcScfAcquis)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcScfAcquis");

			String itemtag = "StatitemAppMsdcScfAcquis";

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
	  * Tag (full: TagMsdcScfAcquis)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int HDGIWI = 2;
		public static final int CPTISN = 3;
		public static final int CPTIPS = 4;
		public static final int CPTIFL = 5;
		public static final int CPTIFN = 6;
		public static final int HDGVIS = 7;
		public static final int CPTVTY = 8;
		public static final int CPTVLP = 9;
		public static final int CPTVRP = 10;
		public static final int CPTVPS = 11;
		public static final int CPTVFL = 12;
		public static final int CPTVFN = 13;

		public Tag(
					String Cpt
					, String HdgIwi
					, String CptIsn
					, String CptIps
					, String CptIfl
					, String CptIfn
					, String HdgVis
					, String CptVty
					, String CptVlp
					, String CptVrp
					, String CptVps
					, String CptVfl
					, String CptVfn
				) {
			this.Cpt = Cpt;
			this.HdgIwi = HdgIwi;
			this.CptIsn = CptIsn;
			this.CptIps = CptIps;
			this.CptIfl = CptIfl;
			this.CptIfn = CptIfn;
			this.HdgVis = HdgVis;
			this.CptVty = CptVty;
			this.CptVlp = CptVlp;
			this.CptVrp = CptVrp;
			this.CptVps = CptVps;
			this.CptVfl = CptVfl;
			this.CptVfn = CptVfn;

			mask = new HashSet<Integer>(Arrays.asList(CPT, HDGIWI, CPTISN, CPTIPS, CPTIFL, CPTIFN, HDGVIS, CPTVTY, CPTVLP, CPTVRP, CPTVPS, CPTVFL, CPTVFN));
		};

		public String Cpt;
		public String HdgIwi;
		public String CptIsn;
		public String CptIps;
		public String CptIfl;
		public String CptIfn;
		public String HdgVis;
		public String CptVty;
		public String CptVlp;
		public String CptVrp;
		public String CptVps;
		public String CptVfl;
		public String CptVfn;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcScfAcquis");

			String itemtag = "TagitemMsdcScfAcquis";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				HdgIwi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgIwi", mask, HDGIWI);
				CptIsn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIsn", mask, CPTISN);
				CptIps = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIps", mask, CPTIPS);
				CptIfl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIfl", mask, CPTIFL);
				CptIfn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIfn", mask, CPTIFN);
				HdgVis = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgVis", mask, HDGVIS);
				CptVty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVty", mask, CPTVTY);
				CptVlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVlp", mask, CPTVLP);
				CptVrp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVrp", mask, CPTVRP);
				CptVps = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVps", mask, CPTVPS);
				CptVfl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVfl", mask, CPTVFL);
				CptVfn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVfn", mask, CPTVFN);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (HdgIwi.equals(comp.HdgIwi)) items.add(HDGIWI);
			if (CptIsn.equals(comp.CptIsn)) items.add(CPTISN);
			if (CptIps.equals(comp.CptIps)) items.add(CPTIPS);
			if (CptIfl.equals(comp.CptIfl)) items.add(CPTIFL);
			if (CptIfn.equals(comp.CptIfn)) items.add(CPTIFN);
			if (HdgVis.equals(comp.HdgVis)) items.add(HDGVIS);
			if (CptVty.equals(comp.CptVty)) items.add(CPTVTY);
			if (CptVlp.equals(comp.CptVlp)) items.add(CPTVLP);
			if (CptVrp.equals(comp.CptVrp)) items.add(CPTVRP);
			if (CptVps.equals(comp.CptVps)) items.add(CPTVPS);
			if (CptVfl.equals(comp.CptVfl)) items.add(CPTVFL);
			if (CptVfn.equals(comp.CptVfn)) items.add(CPTVFN);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, HDGIWI, CPTISN, CPTIPS, CPTIFL, CPTIFN, HDGVIS, CPTVTY, CPTVLP, CPTVRP, CPTVPS, CPTVFL, CPTVFN));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcScfAcquisData)
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
			super(VecMsdcVDpch.DPCHAPPMSDCSCFACQUISDATA, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcScfAcquisData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcScfAcquisDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCSCFACQUISDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcScfAcquisDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcScfAcquisData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPVTY = 4;
		public static final int STATAPP = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCSCFACQUISDATA);

			contiac = new ContIac(0, "", "");
			continf = new ContInf(false, "", "", "", "", "", "", "");
			feedFPupVty = new Feed("FeedFPupVty");
			statapp = new StatApp(0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupVty;
		public StatApp statapp;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPVTY)) ss.add("feedFPupVty");
			if (has(STATAPP)) ss.add("statapp");
			if (has(TAG)) ss.add("tag");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcScfAcquisData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupVty.readXML(doc, basexpath, true)) add(FEEDFPUPVTY);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", "");
				continf = new ContInf(false, "", "", "", "", "", "", "");
				feedFPupVty = new Feed("FeedFPupVty");
				statapp = new StatApp(0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

