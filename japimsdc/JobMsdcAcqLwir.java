/**
  * \file JobMsdcAcqLwir.java
  * Java API code for job JobMsdcAcqLwir
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class JobMsdcAcqLwir {
	/**
		* VecVMethod (full: VecVJobMsdcAcqLwirMethod)
		*/
	public static class VecVMethod {

		public static final int SETOUTPUT = 1;
		public static final int START = 2;
		public static final int STOP = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("setoutput")) return SETOUTPUT;
			if (s.equals("start")) return START;
			if (s.equals("stop")) return STOP;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == SETOUTPUT) return("setOutput");
			if (ix == START) return("start");
			if (ix == STOP) return("stop");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVJobMsdcAcqLwirSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int READY = 2;
		public static final int WAITBUF = 3;
		public static final int ACQ = 4;
		public static final int PRCIDLE = 5;
		public static final int PRC = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("ready")) return READY;
			if (s.equals("waitbuf")) return WAITBUF;
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
			if (ix == WAITBUF) return("waitbuf");
			if (ix == ACQ) return("acq");
			if (ix == PRCIDLE) return("prcidle");
			if (ix == PRC) return("prc");

			return "";
		};

	};

	/**
		* VecVVar (full: VecVJobMsdcAcqLwirVar)
		*/
	public static class VecVVar {

		public static final int SEQNOTGRAY16 = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("seqnotgray16")) return SEQNOTGRAY16;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == SEQNOTGRAY16) return("seqnoTGray16");

			return "";
		};

	};

	/**
	  * Stg (full: StgJobMsdcAcqLwir)
	  */
	public class Stg extends Block {

		public static final int WIDTH = 1;
		public static final int HEIGHT = 2;
		public static final int HPIX = 3;
		public static final int SERNO = 4;
		public static final int A = 5;
		public static final int B = 6;
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
					int width
					, int height
					, double hpix
					, String serno
					, double a
					, double b
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
			this.width = width;
			this.height = height;
			this.hpix = hpix;
			this.serno = serno;
			this.a = a;
			this.b = b;
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

			mask = new HashSet<Integer>(Arrays.asList(WIDTH, HEIGHT, HPIX, SERNO, A, B, IXMSDCVSQRGRP, F, FN, K1, K2, P1, P2, K3, K4, K5, K6));
		};

		public int width;
		public int height;
		public double hpix;
		public String serno;
		public double a;
		public double b;
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
			String srefIxMsdcVSqrgrp;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgJobMsdcAcqLwir");

			String itemtag = "StgitemJobMsdcAcqLwir";

			if (Xmlio.checkXPath(doc, basexpath)) {
				width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "width", mask, WIDTH);
				height = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "height", mask, HEIGHT);
				hpix = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "hpix", mask, HPIX);
				serno = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "serno", mask, SERNO);
				a = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "a", mask, A);
				b = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "b", mask, B);
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
			if (difftag.isEmpty()) difftag = "StgJobMsdcAcqLwir";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemJobMsdcAcqLwir";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "width", width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "height", height);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "hpix", hpix);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "serno", serno);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "a", a);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "b", b);
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

			if (width == comp.width) items.add(WIDTH);
			if (height == comp.height) items.add(HEIGHT);
			if (Xmlio.compareDouble(hpix, comp.hpix) < 1.0e-4) items.add(HPIX);
			if (serno.equals(comp.serno)) items.add(SERNO);
			if (Xmlio.compareDouble(a, comp.a) < 1.0e-4) items.add(A);
			if (Xmlio.compareDouble(b, comp.b) < 1.0e-4) items.add(B);
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

			diffitems = new HashSet<Integer>(Arrays.asList(WIDTH, HEIGHT, HPIX, SERNO, A, B, IXMSDCVSQRGRP, F, FN, K1, K2, P1, P2, K3, K4, K5, K6));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

};

