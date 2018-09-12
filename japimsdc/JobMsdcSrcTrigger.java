/**
  * \file JobMsdcSrcTrigger.java
  * Java API code for job JobMsdcSrcTrigger
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class JobMsdcSrcTrigger {
	/**
		* VecVSge (full: VecVJobMsdcSrcTriggerSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int RUN = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("run")) return RUN;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == RUN) return("run");

			return "";
		};

	};

	/**
	  * Stg (full: StgJobMsdcSrcTrigger)
	  */
	public class Stg extends Block {

		public static final int DT = 1;

		public Stg(
					float dt
				) {
			this.dt = dt;

			mask = new HashSet<Integer>(Arrays.asList(DT));
		};

		public float dt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgJobMsdcSrcTrigger");

			String itemtag = "StgitemJobMsdcSrcTrigger";

			if (Xmlio.checkXPath(doc, basexpath)) {
				dt = Xmlio.extractFloatAttrUclc(doc, basexpath, itemtag, "Si", "sref", "dt", mask, DT);

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
			if (difftag.isEmpty()) difftag = "StgJobMsdcSrcTrigger";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemJobMsdcSrcTrigger";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeFloatAttr(doc, el, itemtag, "sref", "dt", dt);
		};

		public HashSet<Integer> comm(
					Stg comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Xmlio.compareFloat(dt, comp.dt) < 1.0e-4) items.add(DT);

			return(items);
		};

		public HashSet<Integer> diff(
					Stg comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

};

