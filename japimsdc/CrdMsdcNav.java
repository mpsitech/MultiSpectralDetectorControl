/**
  * \file CrdMsdcNav.java
  * Java API code for job CrdMsdcNav
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdMsdcNav {
	/**
		* VecVDo (full: VecVMsdcNavDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;
		public static final int MITSESSPSCLICK = 3;
		public static final int MITSESTRMCLICK = 4;
		public static final int MITCRDUSGCLICK = 5;
		public static final int MITCRDUSRCLICK = 6;
		public static final int MITCRDPRSCLICK = 7;
		public static final int MITCRDSCFCLICK = 8;
		public static final int MITCRDLIVCLICK = 9;
		public static final int MITCRDPRDCLICK = 10;
		public static final int MITCRDDATCLICK = 11;
		public static final int MITCRDFILCLICK = 12;
		public static final int MITAPPLOICLICK = 13;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;
			if (s.equals("mitsesspsclick")) return MITSESSPSCLICK;
			if (s.equals("mitsestrmclick")) return MITSESTRMCLICK;
			if (s.equals("mitcrdusgclick")) return MITCRDUSGCLICK;
			if (s.equals("mitcrdusrclick")) return MITCRDUSRCLICK;
			if (s.equals("mitcrdprsclick")) return MITCRDPRSCLICK;
			if (s.equals("mitcrdscfclick")) return MITCRDSCFCLICK;
			if (s.equals("mitcrdlivclick")) return MITCRDLIVCLICK;
			if (s.equals("mitcrdprdclick")) return MITCRDPRDCLICK;
			if (s.equals("mitcrddatclick")) return MITCRDDATCLICK;
			if (s.equals("mitcrdfilclick")) return MITCRDFILCLICK;
			if (s.equals("mitapploiclick")) return MITAPPLOICLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
			if (ix == MITSESSPSCLICK) return("MitSesSpsClick");
			if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
			if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
			if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
			if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
			if (ix == MITCRDSCFCLICK) return("MitCrdScfClick");
			if (ix == MITCRDLIVCLICK) return("MitCrdLivClick");
			if (ix == MITCRDPRDCLICK) return("MitCrdPrdClick");
			if (ix == MITCRDDATCLICK) return("MitCrdDatClick");
			if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
			if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVMsdcNavSge)
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
	  * ContInf (full: ContInfMsdcNav)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MTXSESSES1 = 3;
		public static final int MTXSESSES2 = 4;
		public static final int MTXSESSES3 = 5;

		public ContInf(
					int numFSge
					, String MrlAppHlp
					, String MtxSesSes1
					, String MtxSesSes2
					, String MtxSesSes3
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;
			this.MtxSesSes1 = MtxSesSes1;
			this.MtxSesSes2 = MtxSesSes2;
			this.MtxSesSes3 = MtxSesSes3;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3));
		};

		public int numFSge;
		public String MrlAppHlp;
		public String MtxSesSes1;
		public String MtxSesSes2;
		public String MtxSesSes3;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfMsdcNav");

			String itemtag = "ContitemInfMsdcNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MtxSesSes1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxSesSes1", mask, MTXSESSES1);
				MtxSesSes2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxSesSes2", mask, MTXSESSES2);
				MtxSesSes3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxSesSes3", mask, MTXSESSES3);

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
			if (MtxSesSes1.equals(comp.MtxSesSes1)) items.add(MTXSESSES1);
			if (MtxSesSes2.equals(comp.MtxSesSes2)) items.add(MTXSESSES2);
			if (MtxSesSes3.equals(comp.MtxSesSes3)) items.add(MTXSESSES3);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppMsdcNav)
	  */
	public class StatApp extends Block {

		public static final int IXMSDCVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONEHEADBAR = 5;
		public static final int INITDONEPRE = 6;
		public static final int INITDONEADMIN = 7;
		public static final int INITDONEOPR = 8;

		public StatApp(
					int ixMsdcVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneHeadbar
					, boolean initdonePre
					, boolean initdoneAdmin
					, boolean initdoneOpr
				) {
			this.ixMsdcVReqitmode = ixMsdcVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneHeadbar = initdoneHeadbar;
			this.initdonePre = initdonePre;
			this.initdoneAdmin = initdoneAdmin;
			this.initdoneOpr = initdoneOpr;

			mask = new HashSet<Integer>(Arrays.asList(IXMSDCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEOPR));
		};

		public int ixMsdcVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneHeadbar;
		public boolean initdonePre;
		public boolean initdoneAdmin;
		public boolean initdoneOpr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxMsdcVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppMsdcNav");

			String itemtag = "StatitemAppMsdcNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxMsdcVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVReqitmode", mask, IXMSDCVREQITMODE);
				ixMsdcVReqitmode = VecMsdcVReqitmode.getIx(srefIxMsdcVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);
				initdonePre = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdonePre", mask, INITDONEPRE);
				initdoneAdmin = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAdmin", mask, INITDONEADMIN);
				initdoneOpr = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneOpr", mask, INITDONEOPR);

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
			if (initdoneHeadbar == comp.initdoneHeadbar) items.add(INITDONEHEADBAR);
			if (initdonePre == comp.initdonePre) items.add(INITDONEPRE);
			if (initdoneAdmin == comp.initdoneAdmin) items.add(INITDONEADMIN);
			if (initdoneOpr == comp.initdoneOpr) items.add(INITDONEOPR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXMSDCVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEOPR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrMsdcNav)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFDLGLOAINI = 1;
		public static final int SCRJREFHEADBAR = 2;
		public static final int SCRJREFPRE = 3;
		public static final int PNLPREAVAIL = 4;
		public static final int SCRJREFADMIN = 5;
		public static final int PNLADMINAVAIL = 6;
		public static final int SCRJREFOPR = 7;
		public static final int PNLOPRAVAIL = 8;
		public static final int MSPCRD1AVAIL = 9;
		public static final int MITCRDUSGAVAIL = 10;
		public static final int MITCRDUSRAVAIL = 11;
		public static final int MITCRDPRSAVAIL = 12;
		public static final int MITCRDSCFAVAIL = 13;
		public static final int MSPCRD2AVAIL = 14;
		public static final int MITCRDLIVAVAIL = 15;
		public static final int MITCRDPRDAVAIL = 16;
		public static final int MITCRDDATAVAIL = 17;
		public static final int MITCRDDATACTIVE = 18;
		public static final int MITCRDFILAVAIL = 19;
		public static final int MSPAPP2AVAIL = 20;
		public static final int MITAPPLOIAVAIL = 21;

		public StatShr(
					String scrJrefDlgloaini
					, String scrJrefHeadbar
					, String scrJrefPre
					, boolean pnlpreAvail
					, String scrJrefAdmin
					, boolean pnladminAvail
					, String scrJrefOpr
					, boolean pnloprAvail
					, boolean MspCrd1Avail
					, boolean MitCrdUsgAvail
					, boolean MitCrdUsrAvail
					, boolean MitCrdPrsAvail
					, boolean MitCrdScfAvail
					, boolean MspCrd2Avail
					, boolean MitCrdLivAvail
					, boolean MitCrdPrdAvail
					, boolean MitCrdDatAvail
					, boolean MitCrdDatActive
					, boolean MitCrdFilAvail
					, boolean MspApp2Avail
					, boolean MitAppLoiAvail
				) {
			this.scrJrefDlgloaini = scrJrefDlgloaini;
			this.scrJrefHeadbar = scrJrefHeadbar;
			this.scrJrefPre = scrJrefPre;
			this.pnlpreAvail = pnlpreAvail;
			this.scrJrefAdmin = scrJrefAdmin;
			this.pnladminAvail = pnladminAvail;
			this.scrJrefOpr = scrJrefOpr;
			this.pnloprAvail = pnloprAvail;
			this.MspCrd1Avail = MspCrd1Avail;
			this.MitCrdUsgAvail = MitCrdUsgAvail;
			this.MitCrdUsrAvail = MitCrdUsrAvail;
			this.MitCrdPrsAvail = MitCrdPrsAvail;
			this.MitCrdScfAvail = MitCrdScfAvail;
			this.MspCrd2Avail = MspCrd2Avail;
			this.MitCrdLivAvail = MitCrdLivAvail;
			this.MitCrdPrdAvail = MitCrdPrdAvail;
			this.MitCrdDatAvail = MitCrdDatAvail;
			this.MitCrdDatActive = MitCrdDatActive;
			this.MitCrdFilAvail = MitCrdFilAvail;
			this.MspApp2Avail = MspApp2Avail;
			this.MitAppLoiAvail = MitAppLoiAvail;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFOPR, PNLOPRAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDSCFAVAIL, MSPCRD2AVAIL, MITCRDLIVAVAIL, MITCRDPRDAVAIL, MITCRDDATAVAIL, MITCRDDATACTIVE, MITCRDFILAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL));
		};

		public String scrJrefDlgloaini;
		public String scrJrefHeadbar;
		public String scrJrefPre;
		public boolean pnlpreAvail;
		public String scrJrefAdmin;
		public boolean pnladminAvail;
		public String scrJrefOpr;
		public boolean pnloprAvail;
		public boolean MspCrd1Avail;
		public boolean MitCrdUsgAvail;
		public boolean MitCrdUsrAvail;
		public boolean MitCrdPrsAvail;
		public boolean MitCrdScfAvail;
		public boolean MspCrd2Avail;
		public boolean MitCrdLivAvail;
		public boolean MitCrdPrdAvail;
		public boolean MitCrdDatAvail;
		public boolean MitCrdDatActive;
		public boolean MitCrdFilAvail;
		public boolean MspApp2Avail;
		public boolean MitAppLoiAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrMsdcNav");

			String itemtag = "StatitemShrMsdcNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefDlgloaini = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgloaini", mask, SCRJREFDLGLOAINI);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);
				scrJrefPre = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefPre", mask, SCRJREFPRE);
				pnlpreAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlpreAvail", mask, PNLPREAVAIL);
				scrJrefAdmin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAdmin", mask, SCRJREFADMIN);
				pnladminAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnladminAvail", mask, PNLADMINAVAIL);
				scrJrefOpr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefOpr", mask, SCRJREFOPR);
				pnloprAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnloprAvail", mask, PNLOPRAVAIL);
				MspCrd1Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", mask, MSPCRD1AVAIL);
				MitCrdUsgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdUsgAvail", mask, MITCRDUSGAVAIL);
				MitCrdUsrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdUsrAvail", mask, MITCRDUSRAVAIL);
				MitCrdPrsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPrsAvail", mask, MITCRDPRSAVAIL);
				MitCrdScfAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdScfAvail", mask, MITCRDSCFAVAIL);
				MspCrd2Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", mask, MSPCRD2AVAIL);
				MitCrdLivAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdLivAvail", mask, MITCRDLIVAVAIL);
				MitCrdPrdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPrdAvail", mask, MITCRDPRDAVAIL);
				MitCrdDatAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdDatAvail", mask, MITCRDDATAVAIL);
				MitCrdDatActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdDatActive", mask, MITCRDDATACTIVE);
				MitCrdFilAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdFilAvail", mask, MITCRDFILAVAIL);
				MspApp2Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspApp2Avail", mask, MSPAPP2AVAIL);
				MitAppLoiAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitAppLoiAvail", mask, MITAPPLOIAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefDlgloaini.equals(comp.scrJrefDlgloaini)) items.add(SCRJREFDLGLOAINI);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);
			if (scrJrefPre.equals(comp.scrJrefPre)) items.add(SCRJREFPRE);
			if (pnlpreAvail == comp.pnlpreAvail) items.add(PNLPREAVAIL);
			if (scrJrefAdmin.equals(comp.scrJrefAdmin)) items.add(SCRJREFADMIN);
			if (pnladminAvail == comp.pnladminAvail) items.add(PNLADMINAVAIL);
			if (scrJrefOpr.equals(comp.scrJrefOpr)) items.add(SCRJREFOPR);
			if (pnloprAvail == comp.pnloprAvail) items.add(PNLOPRAVAIL);
			if (MspCrd1Avail == comp.MspCrd1Avail) items.add(MSPCRD1AVAIL);
			if (MitCrdUsgAvail == comp.MitCrdUsgAvail) items.add(MITCRDUSGAVAIL);
			if (MitCrdUsrAvail == comp.MitCrdUsrAvail) items.add(MITCRDUSRAVAIL);
			if (MitCrdPrsAvail == comp.MitCrdPrsAvail) items.add(MITCRDPRSAVAIL);
			if (MitCrdScfAvail == comp.MitCrdScfAvail) items.add(MITCRDSCFAVAIL);
			if (MspCrd2Avail == comp.MspCrd2Avail) items.add(MSPCRD2AVAIL);
			if (MitCrdLivAvail == comp.MitCrdLivAvail) items.add(MITCRDLIVAVAIL);
			if (MitCrdPrdAvail == comp.MitCrdPrdAvail) items.add(MITCRDPRDAVAIL);
			if (MitCrdDatAvail == comp.MitCrdDatAvail) items.add(MITCRDDATAVAIL);
			if (MitCrdDatActive == comp.MitCrdDatActive) items.add(MITCRDDATACTIVE);
			if (MitCrdFilAvail == comp.MitCrdFilAvail) items.add(MITCRDFILAVAIL);
			if (MspApp2Avail == comp.MspApp2Avail) items.add(MSPAPP2AVAIL);
			if (MitAppLoiAvail == comp.MitAppLoiAvail) items.add(MITAPPLOIAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFOPR, PNLOPRAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDSCFAVAIL, MSPCRD2AVAIL, MITCRDLIVAVAIL, MITCRDPRDAVAIL, MITCRDDATAVAIL, MITCRDDATACTIVE, MITCRDFILAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagMsdcNav)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MITSESSPS = 3;
		public static final int MITSESTRM = 4;
		public static final int MITCRDUSG = 5;
		public static final int MITCRDUSR = 6;
		public static final int MITCRDPRS = 7;
		public static final int MITCRDSCF = 8;
		public static final int MITCRDLIV = 9;
		public static final int MITCRDPRD = 10;
		public static final int MITCRDDAT = 11;
		public static final int MITCRDFIL = 12;
		public static final int MITAPPLOI = 13;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
					, String MitSesSps
					, String MitSesTrm
					, String MitCrdUsg
					, String MitCrdUsr
					, String MitCrdPrs
					, String MitCrdScf
					, String MitCrdLiv
					, String MitCrdPrd
					, String MitCrdDat
					, String MitCrdFil
					, String MitAppLoi
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;
			this.MitSesSps = MitSesSps;
			this.MitSesTrm = MitSesTrm;
			this.MitCrdUsg = MitCrdUsg;
			this.MitCrdUsr = MitCrdUsr;
			this.MitCrdPrs = MitCrdPrs;
			this.MitCrdScf = MitCrdScf;
			this.MitCrdLiv = MitCrdLiv;
			this.MitCrdPrd = MitCrdPrd;
			this.MitCrdDat = MitCrdDat;
			this.MitCrdFil = MitCrdFil;
			this.MitAppLoi = MitAppLoi;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITSESSPS, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDSCF, MITCRDLIV, MITCRDPRD, MITCRDDAT, MITCRDFIL, MITAPPLOI));
		};

		public String MitAppAbt;
		public String MrlAppHlp;
		public String MitSesSps;
		public String MitSesTrm;
		public String MitCrdUsg;
		public String MitCrdUsr;
		public String MitCrdPrs;
		public String MitCrdScf;
		public String MitCrdLiv;
		public String MitCrdPrd;
		public String MitCrdDat;
		public String MitCrdFil;
		public String MitAppLoi;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagMsdcNav");

			String itemtag = "TagitemMsdcNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MitSesSps = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitSesSps", mask, MITSESSPS);
				MitSesTrm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitSesTrm", mask, MITSESTRM);
				MitCrdUsg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdUsg", mask, MITCRDUSG);
				MitCrdUsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdUsr", mask, MITCRDUSR);
				MitCrdPrs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPrs", mask, MITCRDPRS);
				MitCrdScf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdScf", mask, MITCRDSCF);
				MitCrdLiv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdLiv", mask, MITCRDLIV);
				MitCrdPrd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPrd", mask, MITCRDPRD);
				MitCrdDat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdDat", mask, MITCRDDAT);
				MitCrdFil = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdFil", mask, MITCRDFIL);
				MitAppLoi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppLoi", mask, MITAPPLOI);

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
			if (MitSesSps.equals(comp.MitSesSps)) items.add(MITSESSPS);
			if (MitSesTrm.equals(comp.MitSesTrm)) items.add(MITSESTRM);
			if (MitCrdUsg.equals(comp.MitCrdUsg)) items.add(MITCRDUSG);
			if (MitCrdUsr.equals(comp.MitCrdUsr)) items.add(MITCRDUSR);
			if (MitCrdPrs.equals(comp.MitCrdPrs)) items.add(MITCRDPRS);
			if (MitCrdScf.equals(comp.MitCrdScf)) items.add(MITCRDSCF);
			if (MitCrdLiv.equals(comp.MitCrdLiv)) items.add(MITCRDLIV);
			if (MitCrdPrd.equals(comp.MitCrdPrd)) items.add(MITCRDPRD);
			if (MitCrdDat.equals(comp.MitCrdDat)) items.add(MITCRDDAT);
			if (MitCrdFil.equals(comp.MitCrdFil)) items.add(MITCRDFIL);
			if (MitAppLoi.equals(comp.MitAppLoi)) items.add(MITAPPLOI);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITSESSPS, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDSCF, MITCRDLIV, MITCRDPRD, MITCRDDAT, MITCRDFIL, MITAPPLOI));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppMsdcNavDo)
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
			super(VecMsdcVDpch.DPCHAPPMSDCNAVDO, scrJref);

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
			Element el = doc.createElement("DpchAppMsdcNavDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngMsdcNavData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGMSDCNAVDATA);

			continf = new ContInf(0, "", "", "", "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false, false);
			statshr = new StatShr("", "", "", false, "", false, "", false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngMsdcNavData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "", "", "", "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(0, 0, "", 0, false, false, false, false);
				statshr = new StatShr("", "", "", false, "", false, "", false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

