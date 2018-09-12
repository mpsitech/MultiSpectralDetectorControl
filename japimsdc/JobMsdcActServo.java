/**
  * \file JobMsdcActServo.java
  * Java API code for job JobMsdcActServo
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class JobMsdcActServo {
	/**
		* VecVMethod (full: VecVJobMsdcActServoMethod)
		*/
	public static class VecVMethod {

		public static final int SETPHI = 1;
		public static final int SETTHETA = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("setphi")) return SETPHI;
			if (s.equals("settheta")) return SETTHETA;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == SETPHI) return("setPhi");
			if (ix == SETTHETA) return("setTheta");

			return "";
		};

	};

	/**
		* VecVVar (full: VecVJobMsdcActServoVar)
		*/
	public static class VecVVar {

		public static final int THETAPHI = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("thetaphi")) return THETAPHI;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == THETAPHI) return("thetaPhi");

			return "";
		};

	};

	/**
	  * Stg (full: StgJobMsdcActServo)
	  */
	public class Stg extends Block {

		public static final int PHIMIN = 1;
		public static final int PHIMAX = 2;
		public static final int THETAMIN = 3;
		public static final int THETAMAX = 4;

		public Stg(
					double phimin
					, double phimax
					, double thetamin
					, double thetamax
				) {
			this.phimin = phimin;
			this.phimax = phimax;
			this.thetamin = thetamin;
			this.thetamax = thetamax;

			mask = new HashSet<Integer>(Arrays.asList(PHIMIN, PHIMAX, THETAMIN, THETAMAX));
		};

		public double phimin;
		public double phimax;
		public double thetamin;
		public double thetamax;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgJobMsdcActServo");

			String itemtag = "StgitemJobMsdcActServo";

			if (Xmlio.checkXPath(doc, basexpath)) {
				phimin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "phimin", mask, PHIMIN);
				phimax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "phimax", mask, PHIMAX);
				thetamin = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "thetamin", mask, THETAMIN);
				thetamax = Xmlio.extractDoubleAttrUclc(doc, basexpath, itemtag, "Si", "sref", "thetamax", mask, THETAMAX);

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
			if (difftag.isEmpty()) difftag = "StgJobMsdcActServo";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemJobMsdcActServo";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "phimin", phimin);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "phimax", phimax);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "thetamin", thetamin);
			Xmlio.writeDoubleAttr(doc, el, itemtag, "sref", "thetamax", thetamax);
		};

		public HashSet<Integer> comm(
					Stg comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Xmlio.compareDouble(phimin, comp.phimin) < 1.0e-4) items.add(PHIMIN);
			if (Xmlio.compareDouble(phimax, comp.phimax) < 1.0e-4) items.add(PHIMAX);
			if (Xmlio.compareDouble(thetamin, comp.thetamin) < 1.0e-4) items.add(THETAMIN);
			if (Xmlio.compareDouble(thetamax, comp.thetamax) < 1.0e-4) items.add(THETAMAX);

			return(items);
		};

		public HashSet<Integer> diff(
					Stg comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(PHIMIN, PHIMAX, THETAMIN, THETAMAX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

};

