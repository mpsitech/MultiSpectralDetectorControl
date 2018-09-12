/**
  * \file ListMsdcQUsr1NSession.java
  * Java API code for record set of table TblMsdcQUsr1NSession
  * \author Alexander Wirthmueller
  * \date created: 12 Sep 2018
  * \date modified: 12 Sep 2018
  */

package apimsdc;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListMsdcQUsr1NSession {

	public ListMsdcQUsr1NSession() {
		nodes = new ArrayList<MsdcQUsr1NSession>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<MsdcQUsr1NSession> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		MsdcQUsr1NSession rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListMsdcQUsr1NSession");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "MsdcQUsr1NSession", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i=0;i<ics.size();i++) {
				rec = new MsdcQUsr1NSession(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/MsdcQUsr1NSession[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

