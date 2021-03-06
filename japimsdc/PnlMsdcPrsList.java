/**
  * \file PnlMsdcPrsList.java
  * Java API code for job PnlMsdcPrsList
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcPrsList {
	/**
		* VecVDo (full: VecVMsdcPrsListDo)
		*/
	public static class VecVDo {

		public static final int BUTMINIMIZECLICK = 1;
		public static final int BUTREGULARIZECLICK = 2;
		public static final int BUTNEWCLICK = 3;
		public static final int BUTDELETECLICK = 4;
		public static final int BUTFILTERCLICK = 5;
		public static final int BUTREFRESHCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butnewclick")) return BUTNEWCLICK;
			if (s.equals("butdeleteclick")) return BUTDELETECLICK;
			if (s.equals("butfilterclick")) return BUTFILTERCLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTNEWCLICK) return("ButNewClick");
			if (ix == BUTDELETECLICK) return("ButDeleteClick");
			if (ix == BUTFILTERCLICK) return("ButFilterClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacMsdcPrsList)
	  */
	public class ContIac extends Block {

		public static final int NUMFTOS = 1;

		public ContIac(
					int numFTos
				) {
			this.numFTos = numFTos;

			mask = new HashSet<Integer>(Arrays.asList(NUMFTOS));
		};

		public int numFTos;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacMsdcPrsList");

			String itemtag = "ContitemIacMsdcPrsList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFTos = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFTos", mask, NUMFTOS);

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
			if (difftag.isEmpty()) difftag = "ContIacMsdcPrsList";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacMsdcPrsList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFTos", numFTos);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFTos == comp.numFTos) items.add(NUMFTOS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFTOS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfMsdcPrsList)
	  */
	public class ContInf extends Block {

		public static final int BUTFILTERON = 1;
		public static final int NUMFCSIQST = 2;

		public ContInf(
					boolean ButFilterOn
					, int numFCsiQst
				) {
			this.ButFilterOn = ButFilterOn;
			this.numFCsiQst = numFCsiQst;

			mask = new HashSet<Integer>(Arrays.asList(BUTFILTERON, NUMFCSIQST));
		};

		public boolean ButFilterOn;
		public int numFCsiQst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcPrsList");

			String itemtag = "ContitemInfMsdcPrsList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButFilterOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButFilterOn", mask, BUTFILTERON);
				numFCsiQst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFCsiQst", mask, NUMFCSIQST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButFilterOn == comp.ButFilterOn) items.add(BUTFILTERON);
			if (numFCsiQst == comp.numFCsiQst) items.add(NUMFCSIQST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTFILTERON, NUMFCSIQST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrMsdcPrsList)
	  */
	public class StatShr extends Block {

		public static final int IXMSDCVEXPSTATE = 1;
		public static final int BUTDELETEACTIVE = 2;

		public StatShr(
					int ixMsdcVExpstate
					, boolean ButDeleteActive
				) {
			this.ixMsdcVExpstate = ixMsdcVExpstate;
			this.ButDeleteActive = ButDeleteActive;

			mask = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE, BUTDELETEACTIVE));
		};

		public int ixMsdcVExpstate;
		public boolean ButDeleteActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxMsdcVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcPrsList");

			String itemtag = "StatitemShrMsdcPrsList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxMsdcVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVExpstate", mask, IXMSDCVEXPSTATE);
				ixMsdcVExpstate = VecMsdcVExpstate.getIx(srefIxMsdcVExpstate);
				ButDeleteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteActive", mask, BUTDELETEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixMsdcVExpstate == comp.ixMsdcVExpstate) items.add(IXMSDCVEXPSTATE);
			if (ButDeleteActive == comp.ButDeleteActive) items.add(BUTDELETEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXMSDCVEXPSTATE, BUTDELETEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacMsdcPrsList)
	  */
	public class StgIac extends Block {

		public static final int TCOTITWIDTH = 1;
		public static final int TCOFNMWIDTH = 2;
		public static final int TCOLNMWIDTH = 3;
		public static final int TCOGRPWIDTH = 4;
		public static final int TCOOWNWIDTH = 5;
		public static final int TCOSEXWIDTH = 6;
		public static final int TCOTELWIDTH = 7;
		public static final int TCOEMLWIDTH = 8;

		public StgIac(
					int TcoTitWidth
					, int TcoFnmWidth
					, int TcoLnmWidth
					, int TcoGrpWidth
					, int TcoOwnWidth
					, int TcoSexWidth
					, int TcoTelWidth
					, int TcoEmlWidth
				) {
			this.TcoTitWidth = TcoTitWidth;
			this.TcoFnmWidth = TcoFnmWidth;
			this.TcoLnmWidth = TcoLnmWidth;
			this.TcoGrpWidth = TcoGrpWidth;
			this.TcoOwnWidth = TcoOwnWidth;
			this.TcoSexWidth = TcoSexWidth;
			this.TcoTelWidth = TcoTelWidth;
			this.TcoEmlWidth = TcoEmlWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOTITWIDTH, TCOFNMWIDTH, TCOLNMWIDTH, TCOGRPWIDTH, TCOOWNWIDTH, TCOSEXWIDTH, TCOTELWIDTH, TCOEMLWIDTH));
		};

		public int TcoTitWidth;
		public int TcoFnmWidth;
		public int TcoLnmWidth;
		public int TcoGrpWidth;
		public int TcoOwnWidth;
		public int TcoSexWidth;
		public int TcoTelWidth;
		public int TcoEmlWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacMsdcPrsList");

			String itemtag = "StgitemIacMsdcPrsList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoTitWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTitWidth", mask, TCOTITWIDTH);
				TcoFnmWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoFnmWidth", mask, TCOFNMWIDTH);
				TcoLnmWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoLnmWidth", mask, TCOLNMWIDTH);
				TcoGrpWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoGrpWidth", mask, TCOGRPWIDTH);
				TcoOwnWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoOwnWidth", mask, TCOOWNWIDTH);
				TcoSexWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSexWidth", mask, TCOSEXWIDTH);
				TcoTelWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTelWidth", mask, TCOTELWIDTH);
				TcoEmlWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoEmlWidth", mask, TCOEMLWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacMsdcPrsList";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacMsdcPrsList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTitWidth", TcoTitWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoFnmWidth", TcoFnmWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoLnmWidth", TcoLnmWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoGrpWidth", TcoGrpWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoOwnWidth", TcoOwnWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSexWidth", TcoSexWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTelWidth", TcoTelWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoEmlWidth", TcoEmlWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoTitWidth == comp.TcoTitWidth) items.add(TCOTITWIDTH);
			if (TcoFnmWidth == comp.TcoFnmWidth) items.add(TCOFNMWIDTH);
			if (TcoLnmWidth == comp.TcoLnmWidth) items.add(TCOLNMWIDTH);
			if (TcoGrpWidth == comp.TcoGrpWidth) items.add(TCOGRPWIDTH);
			if (TcoOwnWidth == comp.TcoOwnWidth) items.add(TCOOWNWIDTH);
			if (TcoSexWidth == comp.TcoSexWidth) items.add(TCOSEXWIDTH);
			if (TcoTelWidth == comp.TcoTelWidth) items.add(TCOTELWIDTH);
			if (TcoEmlWidth == comp.TcoEmlWidth) items.add(TCOEMLWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOTITWIDTH, TCOFNMWIDTH, TCOLNMWIDTH, TCOGRPWIDTH, TCOOWNWIDTH, TCOSEXWIDTH, TCOTELWIDTH, TCOEMLWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcPrsList)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TRS = 2;
		public static final int TXTSHOWING1 = 3;
		public static final int TXTSHOWING2 = 4;
		public static final int TCOTIT = 5;
		public static final int TCOFNM = 6;
		public static final int TCOLNM = 7;
		public static final int TCOGRP = 8;
		public static final int TCOOWN = 9;
		public static final int TCOSEX = 10;
		public static final int TCOTEL = 11;
		public static final int TCOEML = 12;

		public Tag(
					String Cpt
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoTit
					, String TcoFnm
					, String TcoLnm
					, String TcoGrp
					, String TcoOwn
					, String TcoSex
					, String TcoTel
					, String TcoEml
				) {
			this.Cpt = Cpt;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoTit = TcoTit;
			this.TcoFnm = TcoFnm;
			this.TcoLnm = TcoLnm;
			this.TcoGrp = TcoGrp;
			this.TcoOwn = TcoOwn;
			this.TcoSex = TcoSex;
			this.TcoTel = TcoTel;
			this.TcoEml = TcoEml;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOTIT, TCOFNM, TCOLNM, TCOGRP, TCOOWN, TCOSEX, TCOTEL, TCOEML));
		};

		public String Cpt;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoTit;
		public String TcoFnm;
		public String TcoLnm;
		public String TcoGrp;
		public String TcoOwn;
		public String TcoSex;
		public String TcoTel;
		public String TcoEml;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcPrsList");

			String itemtag = "TagitemMsdcPrsList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTit", mask, TCOTIT);
				TcoFnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoFnm", mask, TCOFNM);
				TcoLnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoLnm", mask, TCOLNM);
				TcoGrp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoGrp", mask, TCOGRP);
				TcoOwn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoOwn", mask, TCOOWN);
				TcoSex = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSex", mask, TCOSEX);
				TcoTel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTel", mask, TCOTEL);
				TcoEml = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoEml", mask, TCOEML);

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
			if (TcoTit.equals(comp.TcoTit)) items.add(TCOTIT);
			if (TcoFnm.equals(comp.TcoFnm)) items.add(TCOFNM);
			if (TcoLnm.equals(comp.TcoLnm)) items.add(TCOLNM);
			if (TcoGrp.equals(comp.TcoGrp)) items.add(TCOGRP);
			if (TcoOwn.equals(comp.TcoOwn)) items.add(TCOOWN);
			if (TcoSex.equals(comp.TcoSex)) items.add(TCOSEX);
			if (TcoTel.equals(comp.TcoTel)) items.add(TCOTEL);
			if (TcoEml.equals(comp.TcoEml)) items.add(TCOEML);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TRS, TXTSHOWING1, TXTSHOWING2, TCOTIT, TCOFNM, TCOLNM, TCOGRP, TCOOWN, TCOSEX, TCOTEL, TCOEML));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcPrsListData)
		*/
	public class DpchAppData extends DpchAppMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int STGIAC = 3;
		public static final int STGIACQRY = 4;
		public static final int ALL = 5;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, StgIac stgiac
					, QryMsdcPrsList.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecMsdcVDpch.DPCHAPPMSDCPRSLISTDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC, STGIAC, STGIACQRY));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
			if (has(STGIAC)) this.stgiac = stgiac;
			if (has(STGIACQRY)) this.stgiacqry = stgiacqry;
		};

		public ContIac contiac;
		public StgIac stgiac;
		public QryMsdcPrsList.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppMsdcPrsListData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcPrsListDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCPRSLISTDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcPrsListDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcPrsListData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFCSIQST = 4;
		public static final int FEEDFTOS = 5;
		public static final int STATSHR = 6;
		public static final int STGIAC = 7;
		public static final int TAG = 8;
		public static final int RST = 9;
		public static final int STATAPPQRY = 10;
		public static final int STATSHRQRY = 11;
		public static final int STGIACQRY = 12;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCPRSLISTDATA);

			contiac = new ContIac(0);
			continf = new ContInf(false, 0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			feedFTos = new Feed("FeedFTos");
			statshr = new StatShr(0, false);
			stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "");
			rst = new ListMsdcQPrsList();
			statappqry = (new QryMsdcPrsList()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryMsdcPrsList()).new StatShr(0, 0, 0);
			stgiacqry = (new QryMsdcPrsList()).new StgIac(0, 0, 0);
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFCsiQst;
		public Feed feedFTos;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListMsdcQPrsList rst;
		public QryMsdcPrsList.StatApp statappqry;
		public QryMsdcPrsList.StatShr statshrqry;
		public QryMsdcPrsList.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFCSIQST)) ss.add("feedFCsiQst");
			if (has(FEEDFTOS)) ss.add("feedFTos");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcPrsListData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFCsiQst.readXML(doc, basexpath, true)) add(FEEDFCSIQST);
				if (feedFTos.readXML(doc, basexpath, true)) add(FEEDFTOS);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stgiac.readXML(doc, basexpath, true)) add(STGIAC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (rst.readXML(doc, basexpath, true)) add(RST);
				if (statappqry.readXML(doc, basexpath, true)) add(STATAPPQRY);
				if (statshrqry.readXML(doc, basexpath, true)) add(STATSHRQRY);
				if (stgiacqry.readXML(doc, basexpath, true)) add(STGIACQRY);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				continf = new ContInf(false, 0);
				feedFCsiQst = new Feed("FeedFCsiQst");
				feedFTos = new Feed("FeedFTos");
				statshr = new StatShr(0, false);
				stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryMsdcPrsList()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryMsdcPrsList()).new StatShr(0, 0, 0);
				stgiacqry = (new QryMsdcPrsList()).new StgIac(0, 0, 0);
			};
		};

	};

};

