/**
  * \file PnlMsdcScfSource.java
  * Java API code for job PnlMsdcScfSource
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlMsdcScfSource {
	/**
		* VecVDo (full: VecVMsdcScfSourceDo)
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
	  * ContIac (full: ContIacMsdcScfSource)
	  */
	public class ContIac extends Block {

		public static final int TXFFPP = 1;
		public static final int SLDFXA = 2;
		public static final int SLDFA0 = 3;
		public static final int SLDFB0 = 4;
		public static final int UPDFAM = 5;
		public static final int SLDFSA = 6;
		public static final int SLDFT0 = 7;
		public static final int SLDFP0 = 8;
		public static final int SLDTRP = 9;

		public ContIac(
					String TxfFpp
					, double SldFxa
					, double SldFa0
					, double SldFb0
					, int UpdFam
					, double SldFsa
					, double SldFt0
					, double SldFp0
					, double SldTrp
				) {
			this.TxfFpp = TxfFpp;
			this.SldFxa = SldFxa;
			this.SldFa0 = SldFa0;
			this.SldFb0 = SldFb0;
			this.UpdFam = UpdFam;
			this.SldFsa = SldFsa;
			this.SldFt0 = SldFt0;
			this.SldFp0 = SldFp0;
			this.SldTrp = SldTrp;

			mask = new HashSet<Integer>(Arrays.asList(TXFFPP, SLDFXA, SLDFA0, SLDFB0, UPDFAM, SLDFSA, SLDFT0, SLDFP0, SLDTRP));
		};

		public String TxfFpp;
		public double SldFxa;
		public double SldFa0;
		public double SldFb0;
		public int UpdFam;
		public double SldFsa;
		public double SldFt0;
		public double SldFp0;
		public double SldTrp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacMsdcScfSource");

			String itemtag = "ContitemIacMsdcScfSource";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfFpp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFpp", mask, TXFFPP);
				SldFxa = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldFxa", mask, SLDFXA);
				SldFa0 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldFa0", mask, SLDFA0);
				SldFb0 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldFb0", mask, SLDFB0);
				UpdFam = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "UpdFam", mask, UPDFAM);
				SldFsa = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldFsa", mask, SLDFSA);
				SldFt0 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldFt0", mask, SLDFT0);
				SldFp0 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldFp0", mask, SLDFP0);
				SldTrp = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "SldTrp", mask, SLDTRP);

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
			if (difftag.isEmpty()) difftag = "ContIacMsdcScfSource";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacMsdcScfSource";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFpp", TxfFpp);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFxa", SldFxa);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFa0", SldFa0);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFb0", SldFb0);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "UpdFam", UpdFam);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFsa", SldFsa);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFt0", SldFt0);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldFp0", SldFp0);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "SldTrp", SldTrp);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfFpp.equals(comp.TxfFpp)) items.add(TXFFPP);
			if (Xmlio.compareDouble(SldFxa, comp.SldFxa) < 1.0e-4) items.add(SLDFXA);
			if (Xmlio.compareDouble(SldFa0, comp.SldFa0) < 1.0e-4) items.add(SLDFA0);
			if (Xmlio.compareDouble(SldFb0, comp.SldFb0) < 1.0e-4) items.add(SLDFB0);
			if (UpdFam == comp.UpdFam) items.add(UPDFAM);
			if (Xmlio.compareDouble(SldFsa, comp.SldFsa) < 1.0e-4) items.add(SLDFSA);
			if (Xmlio.compareDouble(SldFt0, comp.SldFt0) < 1.0e-4) items.add(SLDFT0);
			if (Xmlio.compareDouble(SldFp0, comp.SldFp0) < 1.0e-4) items.add(SLDFP0);
			if (Xmlio.compareDouble(SldTrp, comp.SldTrp) < 1.0e-4) items.add(SLDTRP);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFFPP, SLDFXA, SLDFA0, SLDFB0, UPDFAM, SLDFSA, SLDFT0, SLDFP0, SLDTRP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfMsdcScfSource)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcScfSource");

			String itemtag = "ContitemInfMsdcScfSource";

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
	  * StatApp (full: StatAppMsdcScfSource)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcScfSource");

			String itemtag = "StatitemAppMsdcScfSource";

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
	  * StatShr (full: StatShrMsdcScfSource)
	  */
	public class StatShr extends Block {

		public static final int SLDFXAMIN = 1;
		public static final int SLDFXAMAX = 2;
		public static final int SLDFA0MIN = 3;
		public static final int SLDFA0MAX = 4;
		public static final int SLDFB0MIN = 5;
		public static final int SLDFB0MAX = 6;
		public static final int UPDFAMMIN = 7;
		public static final int UPDFAMMAX = 8;
		public static final int SLDFSAMIN = 9;
		public static final int SLDFSAMAX = 10;
		public static final int SLDFT0MIN = 11;
		public static final int SLDFT0MAX = 12;
		public static final int SLDFP0MIN = 13;
		public static final int SLDFP0MAX = 14;
		public static final int SLDTRPMIN = 15;
		public static final int SLDTRPMAX = 16;
		public static final int SLDTRPRAST = 17;

		public StatShr(
					double SldFxaMin
					, double SldFxaMax
					, double SldFa0Min
					, double SldFa0Max
					, double SldFb0Min
					, double SldFb0Max
					, int UpdFamMin
					, int UpdFamMax
					, double SldFsaMin
					, double SldFsaMax
					, double SldFt0Min
					, double SldFt0Max
					, double SldFp0Min
					, double SldFp0Max
					, double SldTrpMin
					, double SldTrpMax
					, double SldTrpRast
				) {
			this.SldFxaMin = SldFxaMin;
			this.SldFxaMax = SldFxaMax;
			this.SldFa0Min = SldFa0Min;
			this.SldFa0Max = SldFa0Max;
			this.SldFb0Min = SldFb0Min;
			this.SldFb0Max = SldFb0Max;
			this.UpdFamMin = UpdFamMin;
			this.UpdFamMax = UpdFamMax;
			this.SldFsaMin = SldFsaMin;
			this.SldFsaMax = SldFsaMax;
			this.SldFt0Min = SldFt0Min;
			this.SldFt0Max = SldFt0Max;
			this.SldFp0Min = SldFp0Min;
			this.SldFp0Max = SldFp0Max;
			this.SldTrpMin = SldTrpMin;
			this.SldTrpMax = SldTrpMax;
			this.SldTrpRast = SldTrpRast;

			mask = new HashSet<Integer>(Arrays.asList(SLDFXAMIN, SLDFXAMAX, SLDFA0MIN, SLDFA0MAX, SLDFB0MIN, SLDFB0MAX, UPDFAMMIN, UPDFAMMAX, SLDFSAMIN, SLDFSAMAX, SLDFT0MIN, SLDFT0MAX, SLDFP0MIN, SLDFP0MAX, SLDTRPMIN, SLDTRPMAX, SLDTRPRAST));
		};

		public double SldFxaMin;
		public double SldFxaMax;
		public double SldFa0Min;
		public double SldFa0Max;
		public double SldFb0Min;
		public double SldFb0Max;
		public int UpdFamMin;
		public int UpdFamMax;
		public double SldFsaMin;
		public double SldFsaMax;
		public double SldFt0Min;
		public double SldFt0Max;
		public double SldFp0Min;
		public double SldFp0Max;
		public double SldTrpMin;
		public double SldTrpMax;
		public double SldTrpRast;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcScfSource");

			String itemtag = "StatitemShrMsdcScfSource";

			if (Xmlio.checkXPath(doc, basexpath)) {
				SldFxaMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFxaMin", mask, SLDFXAMIN);
				SldFxaMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFxaMax", mask, SLDFXAMAX);
				SldFa0Min = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFa0Min", mask, SLDFA0MIN);
				SldFa0Max = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFa0Max", mask, SLDFA0MAX);
				SldFb0Min = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFb0Min", mask, SLDFB0MIN);
				SldFb0Max = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFb0Max", mask, SLDFB0MAX);
				UpdFamMin = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdFamMin", mask, UPDFAMMIN);
				UpdFamMax = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UpdFamMax", mask, UPDFAMMAX);
				SldFsaMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFsaMin", mask, SLDFSAMIN);
				SldFsaMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFsaMax", mask, SLDFSAMAX);
				SldFt0Min = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFt0Min", mask, SLDFT0MIN);
				SldFt0Max = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFt0Max", mask, SLDFT0MAX);
				SldFp0Min = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFp0Min", mask, SLDFP0MIN);
				SldFp0Max = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldFp0Max", mask, SLDFP0MAX);
				SldTrpMin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTrpMin", mask, SLDTRPMIN);
				SldTrpMax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTrpMax", mask, SLDTRPMAX);
				SldTrpRast = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SldTrpRast", mask, SLDTRPRAST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Xmlio.compareDouble(SldFxaMin, comp.SldFxaMin) < 1.0e-4) items.add(SLDFXAMIN);
			if (Xmlio.compareDouble(SldFxaMax, comp.SldFxaMax) < 1.0e-4) items.add(SLDFXAMAX);
			if (Xmlio.compareDouble(SldFa0Min, comp.SldFa0Min) < 1.0e-4) items.add(SLDFA0MIN);
			if (Xmlio.compareDouble(SldFa0Max, comp.SldFa0Max) < 1.0e-4) items.add(SLDFA0MAX);
			if (Xmlio.compareDouble(SldFb0Min, comp.SldFb0Min) < 1.0e-4) items.add(SLDFB0MIN);
			if (Xmlio.compareDouble(SldFb0Max, comp.SldFb0Max) < 1.0e-4) items.add(SLDFB0MAX);
			if (UpdFamMin == comp.UpdFamMin) items.add(UPDFAMMIN);
			if (UpdFamMax == comp.UpdFamMax) items.add(UPDFAMMAX);
			if (Xmlio.compareDouble(SldFsaMin, comp.SldFsaMin) < 1.0e-4) items.add(SLDFSAMIN);
			if (Xmlio.compareDouble(SldFsaMax, comp.SldFsaMax) < 1.0e-4) items.add(SLDFSAMAX);
			if (Xmlio.compareDouble(SldFt0Min, comp.SldFt0Min) < 1.0e-4) items.add(SLDFT0MIN);
			if (Xmlio.compareDouble(SldFt0Max, comp.SldFt0Max) < 1.0e-4) items.add(SLDFT0MAX);
			if (Xmlio.compareDouble(SldFp0Min, comp.SldFp0Min) < 1.0e-4) items.add(SLDFP0MIN);
			if (Xmlio.compareDouble(SldFp0Max, comp.SldFp0Max) < 1.0e-4) items.add(SLDFP0MAX);
			if (Xmlio.compareDouble(SldTrpMin, comp.SldTrpMin) < 1.0e-4) items.add(SLDTRPMIN);
			if (Xmlio.compareDouble(SldTrpMax, comp.SldTrpMax) < 1.0e-4) items.add(SLDTRPMAX);
			if (Xmlio.compareDouble(SldTrpRast, comp.SldTrpRast) < 1.0e-4) items.add(SLDTRPRAST);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SLDFXAMIN, SLDFXAMAX, SLDFA0MIN, SLDFA0MAX, SLDFB0MIN, SLDFB0MAX, UPDFAMMIN, UPDFAMMAX, SLDFSAMIN, SLDFSAMAX, SLDFT0MIN, SLDFT0MAX, SLDFP0MIN, SLDFP0MAX, SLDTRPMIN, SLDTRPMAX, SLDTRPRAST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcScfSource)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int HDGFPG = 2;
		public static final int CPTFPP = 3;
		public static final int CPTFXA = 4;
		public static final int CPTFA0 = 5;
		public static final int CPTFB0 = 6;
		public static final int CPTFAM = 7;
		public static final int CPTFSA = 8;
		public static final int CPTFT0 = 9;
		public static final int CPTFP0 = 10;
		public static final int CPTTRP = 11;

		public Tag(
					String Cpt
					, String HdgFpg
					, String CptFpp
					, String CptFxa
					, String CptFa0
					, String CptFb0
					, String CptFam
					, String CptFsa
					, String CptFt0
					, String CptFp0
					, String CptTrp
				) {
			this.Cpt = Cpt;
			this.HdgFpg = HdgFpg;
			this.CptFpp = CptFpp;
			this.CptFxa = CptFxa;
			this.CptFa0 = CptFa0;
			this.CptFb0 = CptFb0;
			this.CptFam = CptFam;
			this.CptFsa = CptFsa;
			this.CptFt0 = CptFt0;
			this.CptFp0 = CptFp0;
			this.CptTrp = CptTrp;

			mask = new HashSet<Integer>(Arrays.asList(CPT, HDGFPG, CPTFPP, CPTFXA, CPTFA0, CPTFB0, CPTFAM, CPTFSA, CPTFT0, CPTFP0, CPTTRP));
		};

		public String Cpt;
		public String HdgFpg;
		public String CptFpp;
		public String CptFxa;
		public String CptFa0;
		public String CptFb0;
		public String CptFam;
		public String CptFsa;
		public String CptFt0;
		public String CptFp0;
		public String CptTrp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcScfSource");

			String itemtag = "TagitemMsdcScfSource";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				HdgFpg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgFpg", mask, HDGFPG);
				CptFpp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFpp", mask, CPTFPP);
				CptFxa = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFxa", mask, CPTFXA);
				CptFa0 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFa0", mask, CPTFA0);
				CptFb0 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFb0", mask, CPTFB0);
				CptFam = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFam", mask, CPTFAM);
				CptFsa = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFsa", mask, CPTFSA);
				CptFt0 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFt0", mask, CPTFT0);
				CptFp0 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFp0", mask, CPTFP0);
				CptTrp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTrp", mask, CPTTRP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (HdgFpg.equals(comp.HdgFpg)) items.add(HDGFPG);
			if (CptFpp.equals(comp.CptFpp)) items.add(CPTFPP);
			if (CptFxa.equals(comp.CptFxa)) items.add(CPTFXA);
			if (CptFa0.equals(comp.CptFa0)) items.add(CPTFA0);
			if (CptFb0.equals(comp.CptFb0)) items.add(CPTFB0);
			if (CptFam.equals(comp.CptFam)) items.add(CPTFAM);
			if (CptFsa.equals(comp.CptFsa)) items.add(CPTFSA);
			if (CptFt0.equals(comp.CptFt0)) items.add(CPTFT0);
			if (CptFp0.equals(comp.CptFp0)) items.add(CPTFP0);
			if (CptTrp.equals(comp.CptTrp)) items.add(CPTTRP);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, HDGFPG, CPTFPP, CPTFXA, CPTFA0, CPTFB0, CPTFAM, CPTFSA, CPTFT0, CPTFP0, CPTTRP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppMsdcScfSourceData)
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
			super(VecMsdcVDpch.DPCHAPPMSDCSCFSOURCEDATA, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcScfSourceData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcScfSourceDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCSCFSOURCEDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcScfSourceDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcScfSourceData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCSCFSOURCEDATA);

			contiac = new ContIac("", 0.0, 0.0, 0.0, 0, 0.0, 0.0, 0.0, 0.0);
			continf = new ContInf(false);
			statapp = new StatApp(0);
			statshr = new StatShr(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcScfSourceData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", 0.0, 0.0, 0.0, 0, 0.0, 0.0, 0.0, 0.0);
				continf = new ContInf(false);
				statapp = new StatApp(0);
				statshr = new StatShr(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

