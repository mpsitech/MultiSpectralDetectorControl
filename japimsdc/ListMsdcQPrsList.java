/**
  * \file ListMsdcQPrsList.java
  * Java API code for record set of table TblMsdcQPrsList
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListMsdcQPrsList {

	public ListMsdcQPrsList() {
		nodes = new ArrayList<MsdcQPrsList>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<MsdcQPrsList> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		MsdcQPrsList rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListMsdcQPrsList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "MsdcQPrsList", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i=0;i<ics.size();i++) {
				rec = new MsdcQPrsList(i+1, "", "", "", "", "", "", "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/MsdcQPrsList[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

