/**
  * \file ListMsdcQPrd1NData.java
  * Java API code for record set of table TblMsdcQPrd1NData
  * \author Alexander Wirthmueller
  * \date created: 15 Aug 2018
  * \date modified: 15 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListMsdcQPrd1NData {

	public ListMsdcQPrd1NData() {
		nodes = new ArrayList<MsdcQPrd1NData>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<MsdcQPrd1NData> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		MsdcQPrd1NData rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListMsdcQPrd1NData");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "MsdcQPrd1NData", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i=0;i<ics.size();i++) {
				rec = new MsdcQPrd1NData(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/MsdcQPrd1NData[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

