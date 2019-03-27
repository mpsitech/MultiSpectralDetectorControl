/**
  * \file SessMsdc.java
  * Java API code for job SessMsdc
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class SessMsdc {
	/**
	  * StatShr (full: StatShrSessMsdc)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFCRDNAV = 1;

		public StatShr(
					String scrJrefCrdnav
				) {
			this.scrJrefCrdnav = scrJrefCrdnav;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFCRDNAV));
		};

		public String scrJrefCrdnav;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrSessMsdc");

			String itemtag = "StatitemShrSessMsdc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefCrdnav = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCrdnav", mask, SCRJREFCRDNAV);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefCrdnav.equals(comp.scrJrefCrdnav)) items.add(SCRJREFCRDNAV);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFCRDNAV));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchEngData (full: DpchEngSessMsdcData)
		*/
	public class DpchEngData extends DpchEngMsdc {

		public static final int SCRJREF = 1;
		public static final int FEEDFENSSEC = 2;
		public static final int STATSHR = 3;

		public DpchEngData() {
			super(VecMsdcVDpch.DPCHENGSESSMSDCDATA);

			feedFEnsSec = new Feed("FeedFEnsSec");
			statshr = new StatShr("");
		};

		public Feed feedFEnsSec;
		public StatShr statshr;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(FEEDFENSSEC)) ss.add("feedFEnsSec");
			if (has(STATSHR)) ss.add("statshr");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngSessMsdcData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (feedFEnsSec.readXML(doc, basexpath, true)) add(FEEDFENSSEC);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
			} else {
				scrJref = "";
				feedFEnsSec = new Feed("FeedFEnsSec");
				statshr = new StatShr("");
			};
		};

	};

};

