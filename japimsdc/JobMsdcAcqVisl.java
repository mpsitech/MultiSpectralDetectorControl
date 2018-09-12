/**
  * \file JobMsdcAcqVisl.java
  * Java API code for job JobMsdcAcqVisl
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class JobMsdcAcqVisl {
	/**
		* VecVMethod (full: VecVJobMsdcAcqVislMethod)
		*/
	public static class VecVMethod {

		public static final int SETFOCUS = 1;
		public static final int SETOUTPUT = 2;
		public static final int SETTINT = 3;
		public static final int START = 4;
		public static final int STOP = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("setfocus")) return SETFOCUS;
			if (s.equals("setoutput")) return SETOUTPUT;
			if (s.equals("settint")) return SETTINT;
			if (s.equals("start")) return START;
			if (s.equals("stop")) return STOP;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == SETFOCUS) return("setFocus");
			if (ix == SETOUTPUT) return("setOutput");
			if (ix == SETTINT) return("setTint");
			if (ix == START) return("start");
			if (ix == STOP) return("stop");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVJobMsdcAcqVislSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int READY = 2;
		public static final int ACQIDLE = 3;
		public static final int ACQ = 4;
		public static final int PRCIDLE = 5;
		public static final int PRC = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("ready")) return READY;
			if (s.equals("acqidle")) return ACQIDLE;
			if (s.equals("acq")) return ACQ;
			if (s.equals("prcidle")) return PRCIDLE;
			if (s.equals("prc")) return PRC;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == READY) return("ready");
			if (ix == ACQIDLE) return("acqidle");
			if (ix == ACQ) return("acq");
			if (ix == PRCIDLE) return("prcidle");
			if (ix == PRC) return("prc");

			return "";
		};

	};

	/**
		* VecVVar (full: VecVJobMsdcAcqVislVar)
		*/
	public static class VecVVar {

		public static final int SEQNOTRGBX8GRAY8 = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("seqnotrgbx8gray8")) return SEQNOTRGBX8GRAY8;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == SEQNOTRGBX8GRAY8) return("seqnoTRgbx8Gray8");

			return "";
		};

	};

	/**
	  * Stg (full: StgJobMsdcAcqVisl)
	  */
	public class Stg extends Block {

		public static final int IXMSDCVCAMTYPE = 1;
		public static final int WIDTH = 2;
		public static final int HEIGHT = 3;
		public static final int HPIX = 4;
		public static final int PATH = 5;
		public static final int SERNO = 6;
		public static final int IXMSDCVSQRGRP = 7;
		public static final int F = 8;
		public static final int FN = 9;
		public static final int K1 = 10;
		public static final int K2 = 11;
		public static final int P1 = 12;
		public static final int P2 = 13;
		public static final int K3 = 14;
		public static final int K4 = 15;
		public static final int K5 = 16;
		public static final int K6 = 17;

		public Stg(
					int ixMsdcVCamtype
					, int width
					, int height
					, double hpix
					, String path
					, String serno
					, int ixMsdcVSqrgrp
					, double f
					, double fn
					, double k1
					, double k2
					, double p1
					, double p2
					, double k3
					, double k4
					, double k5
					, double k6
				) {
			this.ixMsdcVCamtype = ixMsdcVCamtype;
			this.width = width;
			this.height = height;
			this.hpix = hpix;
			this.path = path;
			this.serno = serno;
			this.ixMsdcVSqrgrp = ixMsdcVSqrgrp;
			this.f = f;
			this.fn = fn;
			this.k1 = k1;
			this.k2 = k2;
			this.p1 = p1;
			this.p2 = p2;
			this.k3 = k3;
			this.k4 = k4;
			this.k5 = k5;
			this.k6 = k6;

			mask = new HashSet<Integer>(Arrays.asList(IXMSDCVCAMTYPE, WIDTH, HEIGHT, HPIX, PATH, SERNO, IXMSDCVSQRGRP, F, FN, K1, K2, P1, P2, K3, K4, K5, K6));
		};

		public int ixMsdcVCamtype;
		public int width;
		public int height;
		public double hpix;
		public String path;
		public String serno;
		public int ixMsdcVSqrgrp;
		public double f;
		public double fn;
		public double k1;
		public double k2;
		public double p1;
		public double p2;
		public double k3;
		public double k4;
		public double k5;
		public double k6;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxMsdcVCamtype;
			String srefIxMsdcVSqrgrp;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgJobMsdcAcqVisl");

			String itemtag = "StgitemJobMsdcAcqVisl";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxMsdcVCamtype = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVCamtype", mask, IXMSDCVCAMTYPE);
				ixMsdcVCamtype = VecMsdcVCamtype.getIx(srefIxMsdcVCamtype);
				width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "width", mask, WIDTH);
				height = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "height", mask, HEIGHT);
				hpix = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "hpix", mask, HPIX);
				path = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "path", mask, PATH);
				serno = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "serno", mask, SERNO);
				srefIxMsdcVSqrgrp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxMsdcVSqrgrp", mask, IXMSDCVSQRGRP);
				ixMsdcVSqrgrp = VecMsdcVSqrgrp.getIx(srefIxMsdcVSqrgrp);
				f = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "f", mask, F);
				fn = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "fn", mask, FN);
				k1 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "k1", mask, K1);
				k2 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "k2", mask, K2);
				p1 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "p1", mask, P1);
				p2 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "p2", mask, P2);
				k3 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "k3", mask, K3);
				k4 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "k4", mask, K4);
				k5 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "k5", mask, K5);
				k6 = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "k6", mask, K6);

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
			if (difftag.isEmpty()) difftag = "StgJobMsdcAcqVisl";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemJobMsdcAcqVisl";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "srefIxMsdcVCamtype", VecMsdcVCamtype.getSref(ixMsdcVCamtype));
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "width", width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "height", height);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "hpix", hpix);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "path", path);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "serno", serno);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "srefIxMsdcVSqrgrp", VecMsdcVSqrgrp.getSref(ixMsdcVSqrgrp));
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "f", f);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "fn", fn);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "k1", k1);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "k2", k2);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "p1", p1);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "p2", p2);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "k3", k3);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "k4", k4);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "k5", k5);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "k6", k6);
		};

		public HashSet<Integer> comm(
					Stg comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixMsdcVCamtype == comp.ixMsdcVCamtype) items.add(IXMSDCVCAMTYPE);
			if (width == comp.width) items.add(WIDTH);
			if (height == comp.height) items.add(HEIGHT);
			if (Xmlio.compareDouble(hpix, comp.hpix) < 1.0e-4) items.add(HPIX);
			if (path.equals(comp.path)) items.add(PATH);
			if (serno.equals(comp.serno)) items.add(SERNO);
			if (ixMsdcVSqrgrp == comp.ixMsdcVSqrgrp) items.add(IXMSDCVSQRGRP);
			if (Xmlio.compareDouble(f, comp.f) < 1.0e-4) items.add(F);
			if (Xmlio.compareDouble(fn, comp.fn) < 1.0e-4) items.add(FN);
			if (Xmlio.compareDouble(k1, comp.k1) < 1.0e-4) items.add(K1);
			if (Xmlio.compareDouble(k2, comp.k2) < 1.0e-4) items.add(K2);
			if (Xmlio.compareDouble(p1, comp.p1) < 1.0e-4) items.add(P1);
			if (Xmlio.compareDouble(p2, comp.p2) < 1.0e-4) items.add(P2);
			if (Xmlio.compareDouble(k3, comp.k3) < 1.0e-4) items.add(K3);
			if (Xmlio.compareDouble(k4, comp.k4) < 1.0e-4) items.add(K4);
			if (Xmlio.compareDouble(k5, comp.k5) < 1.0e-4) items.add(K5);
			if (Xmlio.compareDouble(k6, comp.k6) < 1.0e-4) items.add(K6);

			return(items);
		};

		public HashSet<Integer> diff(
					Stg comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXMSDCVCAMTYPE, WIDTH, HEIGHT, HPIX, PATH, SERNO, IXMSDCVSQRGRP, F, FN, K1, K2, P1, P2, K3, K4, K5, K6));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

};

