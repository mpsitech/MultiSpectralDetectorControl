/**
  * \file JobMsdcSrcMsdd.java
  * Java API code for job JobMsdcSrcMsdd
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class JobMsdcSrcMsdd {
	/**
		* VecVSge (full: VecVJobMsdcSrcMsddSge)
		*/
	public static class VecVSge {

		public static final int NC = 1;
		public static final int READY = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("nc")) return NC;
			if (s.equals("ready")) return READY;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == NC) return("nc");
			if (ix == READY) return("ready");

			return "";
		};

	};

	/**
	  * Stg (full: StgJobMsdcSrcMsdd)
	  */
	public class Stg extends Block {

		public static final int PATH = 1;
		public static final int ADXLA = 2;
		public static final int ADXLALPHA0 = 3;
		public static final int ADXLBETA0 = 4;
		public static final int ALIGNMAX = 5;
		public static final int SERVOA = 6;
		public static final int SERVOTHETA0 = 7;
		public static final int SERVOPHI0 = 8;

		public Stg(
					String path
					, float adxlA
					, float adxlAlpha0
					, float adxlBeta0
					, int alignMax
					, float servoA
					, float servoTheta0
					, float servoPhi0
				) {
			this.path = path;
			this.adxlA = adxlA;
			this.adxlAlpha0 = adxlAlpha0;
			this.adxlBeta0 = adxlBeta0;
			this.alignMax = alignMax;
			this.servoA = servoA;
			this.servoTheta0 = servoTheta0;
			this.servoPhi0 = servoPhi0;

			mask = new HashSet<Integer>(Arrays.asList(PATH, ADXLA, ADXLALPHA0, ADXLBETA0, ALIGNMAX, SERVOA, SERVOTHETA0, SERVOPHI0));
		};

		public String path;

		public float adxlA;
		public float adxlAlpha0;
		public float adxlBeta0;

		public int alignMax;

		public float servoA;
		public float servoTheta0;
		public float servoPhi0;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgJobMsdcSrcMsdd");

			String itemtag = "StgitemJobMsdcSrcMsdd";

			if (Xmlio.checkXPath(doc, basexpath)) {
				path = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "path", mask, PATH);
				adxlA = Xmlio.extractFloatAttrUclc(doc, basexpath, itemtag, "Si", "sref", "adxlA", mask, ADXLA);
				adxlAlpha0 = Xmlio.extractFloatAttrUclc(doc, basexpath, itemtag, "Si", "sref", "adxlAlpha0", mask, ADXLALPHA0);
				adxlBeta0 = Xmlio.extractFloatAttrUclc(doc, basexpath, itemtag, "Si", "sref", "adxlBeta0", mask, ADXLBETA0);
				alignMax = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "alignMax", mask, ALIGNMAX);
				servoA = Xmlio.extractFloatAttrUclc(doc, basexpath, itemtag, "Si", "sref", "servoA", mask, SERVOA);
				servoTheta0 = Xmlio.extractFloatAttrUclc(doc, basexpath, itemtag, "Si", "sref", "servoTheta0", mask, SERVOTHETA0);
				servoPhi0 = Xmlio.extractFloatAttrUclc(doc, basexpath, itemtag, "Si", "sref", "servoPhi0", mask, SERVOPHI0);

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
			if (difftag.isEmpty()) difftag = "StgJobMsdcSrcMsdd";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemJobMsdcSrcMsdd";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "path", path);
			Xmlio.writeFloatAttr(doc, el, itemtag, "sref", "adxlA", adxlA);
			Xmlio.writeFloatAttr(doc, el, itemtag, "sref", "adxlAlpha0", adxlAlpha0);
			Xmlio.writeFloatAttr(doc, el, itemtag, "sref", "adxlBeta0", adxlBeta0);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "alignMax", alignMax);
			Xmlio.writeFloatAttr(doc, el, itemtag, "sref", "servoA", servoA);
			Xmlio.writeFloatAttr(doc, el, itemtag, "sref", "servoTheta0", servoTheta0);
			Xmlio.writeFloatAttr(doc, el, itemtag, "sref", "servoPhi0", servoPhi0);
		};

		public HashSet<Integer> comm(
					Stg comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (path.equals(comp.path)) items.add(PATH);
			if (Xmlio.compareFloat(adxlA, comp.adxlA) < 1.0e-4) items.add(ADXLA);
			if (Xmlio.compareFloat(adxlAlpha0, comp.adxlAlpha0) < 1.0e-4) items.add(ADXLALPHA0);
			if (Xmlio.compareFloat(adxlBeta0, comp.adxlBeta0) < 1.0e-4) items.add(ADXLBETA0);
			if (alignMax == comp.alignMax) items.add(ALIGNMAX);
			if (Xmlio.compareFloat(servoA, comp.servoA) < 1.0e-4) items.add(SERVOA);
			if (Xmlio.compareFloat(servoTheta0, comp.servoTheta0) < 1.0e-4) items.add(SERVOTHETA0);
			if (Xmlio.compareFloat(servoPhi0, comp.servoPhi0) < 1.0e-4) items.add(SERVOPHI0);

			return(items);
		};

		public HashSet<Integer> diff(
					Stg comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(PATH, ADXLA, ADXLALPHA0, ADXLBETA0, ALIGNMAX, SERVOA, SERVOTHETA0, SERVOPHI0));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

};

