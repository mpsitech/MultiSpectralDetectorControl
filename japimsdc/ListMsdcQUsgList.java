/**
  * \file ListMsdcQUsgList.java
  * Java API code for record set of table TblMsdcQUsgList
  * \author Alexander Wirthmueller
  * \date created: 4 Oct 2018
  * \date modified: 4 Oct 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListMsdcQUsgList {

	public ListMsdcQUsgList() {
		nodes = new ArrayList<MsdcQUsgList>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<MsdcQUsgList> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		MsdcQUsgList rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListMsdcQUsgList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "MsdcQUsgList", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i=0;i<ics.size();i++) {
				rec = new MsdcQUsgList(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/MsdcQUsgList[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

