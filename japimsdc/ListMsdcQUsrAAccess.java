/**
  * \file ListMsdcQUsrAAccess.java
  * Java API code for record set of table TblMsdcQUsrAAccess
  * \author Alexander Wirthmueller
  * \date created: 29 Aug 2018
  * \date modified: 29 Aug 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListMsdcQUsrAAccess {

	public ListMsdcQUsrAAccess() {
		nodes = new ArrayList<MsdcQUsrAAccess>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<MsdcQUsrAAccess> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		MsdcQUsrAAccess rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListMsdcQUsrAAccess");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "MsdcQUsrAAccess", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i=0;i<ics.size();i++) {
				rec = new MsdcQUsrAAccess(i+1, "", "", "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/MsdcQUsrAAccess[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

