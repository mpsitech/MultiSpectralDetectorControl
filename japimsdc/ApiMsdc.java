/**
  * \file ApiMsdc.java
  * Msdc Java API package global functionality
  * \author Alexander Wirthmueller
  * \date created: 18 Dec 2018
  * \date modified: 18 Dec 2018
  */

package apimsdc;

import java.io.*;

import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;

import org.w3c.dom.*;
import org.xml.sax.*;

import sbecore.*;

public class ApiMsdc {

	public static final String MSDC_VERSION = "0.1.58";
	public static final int MSDC_VERSION_MAJOR = 0;
	public static final int MSDC_VERSION_MINOR = 1;
	public static final int MSDC_VERSION_SUB = 58;

	public static DpchEngMsdc readDpchEng(
				String s
			) {
		DpchEngMsdc dpcheng = null;

		try {
			InputSource is = new InputSource();
			is.setCharacterStream(new StringReader(s));

			Document doc = DocumentBuilderFactory.newInstance().newDocumentBuilder().parse(is);

			int ixMsdcVDpch = VecMsdcVDpch.getIx(Xmlio.extractRoot(doc));
			
			if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGDLGMSDCFILDOWNLOADDATA) dpcheng = (new DlgMsdcFilDownload()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGDLGMSDCNAVLOAINIDATA) dpcheng = (new DlgMsdcNavLoaini()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGM2MSESSMSDCDATA) dpcheng = (new M2msessMsdc()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCACK) dpcheng = new DpchEngMsdcAck();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCALERT) dpcheng = new DpchEngMsdcAlert();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCCONFIRM) dpcheng = new DpchEngMsdcConfirm();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCDATAPARDATA) dpcheng = (new PnlMsdcDatAPar()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCDATDATA) dpcheng = (new CrdMsdcDat()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCDATDETAILDATA) dpcheng = (new PnlMsdcDatDetail()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCDATHEADBARDATA) dpcheng = (new PnlMsdcDatHeadbar()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCDATLISTDATA) dpcheng = (new PnlMsdcDatList()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCDATRECDATA) dpcheng = (new PnlMsdcDatRec()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCDATREF1NFILEDATA) dpcheng = (new PnlMsdcDatRef1NFile()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCFILDATA) dpcheng = (new CrdMsdcFil()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCFILDETAILDATA) dpcheng = (new PnlMsdcFilDetail()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCFILHEADBARDATA) dpcheng = (new PnlMsdcFilHeadbar()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCFILLISTDATA) dpcheng = (new PnlMsdcFilList()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCFILRECDATA) dpcheng = (new PnlMsdcFilRec()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCLIVALIGNDATA) dpcheng = (new PnlMsdcLivAlign()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCLIVDATA) dpcheng = (new CrdMsdcLiv()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCLIVHEADBARDATA) dpcheng = (new PnlMsdcLivHeadbar()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCLIVSCILLDATA) dpcheng = (new PnlMsdcLivScill()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCLIVTRACKDATA) dpcheng = (new PnlMsdcLivTrack()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCLIVVIDEODATA) dpcheng = (new PnlMsdcLivVideo()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCLIVVIDEOLIVE) dpcheng = (new PnlMsdcLivVideo()).new DpchEngLive();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCNAVADMINDATA) dpcheng = (new PnlMsdcNavAdmin()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCNAVDATA) dpcheng = (new CrdMsdcNav()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCNAVHEADBARDATA) dpcheng = (new PnlMsdcNavHeadbar()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCNAVOPRDATA) dpcheng = (new PnlMsdcNavOpr()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCNAVPREDATA) dpcheng = (new PnlMsdcNavPre()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRD1NDATADATA) dpcheng = (new PnlMsdcPrd1NData()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRDDATA) dpcheng = (new CrdMsdcPrd()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRDDETAILDATA) dpcheng = (new PnlMsdcPrdDetail()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRDHEADBARDATA) dpcheng = (new PnlMsdcPrdHeadbar()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRDLISTDATA) dpcheng = (new PnlMsdcPrdList()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRDRECDATA) dpcheng = (new PnlMsdcPrdRec()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRSDATA) dpcheng = (new CrdMsdcPrs()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRSDETAILDATA) dpcheng = (new PnlMsdcPrsDetail()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRSHEADBARDATA) dpcheng = (new PnlMsdcPrsHeadbar()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRSLISTDATA) dpcheng = (new PnlMsdcPrsList()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCPRSRECDATA) dpcheng = (new PnlMsdcPrsRec()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCSCFACQUISDATA) dpcheng = (new PnlMsdcScfAcquis()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCSCFACTUDATA) dpcheng = (new PnlMsdcScfActu()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCSCFDATA) dpcheng = (new CrdMsdcScf()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCSCFHEADBARDATA) dpcheng = (new PnlMsdcScfHeadbar()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCSCFPRCCTLDATA) dpcheng = (new PnlMsdcScfPrcctl()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCSCFSOURCEDATA) dpcheng = (new PnlMsdcScfSource()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCSUSPEND) dpcheng = new DpchEngMsdcSuspend();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSGAACCESSDATA) dpcheng = (new PnlMsdcUsgAAccess()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSGDATA) dpcheng = (new CrdMsdcUsg()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSGDETAILDATA) dpcheng = (new PnlMsdcUsgDetail()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSGHEADBARDATA) dpcheng = (new PnlMsdcUsgHeadbar()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSGLISTDATA) dpcheng = (new PnlMsdcUsgList()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSGMNUSERDATA) dpcheng = (new PnlMsdcUsgMNUser()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSGRECDATA) dpcheng = (new PnlMsdcUsgRec()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSR1NSESSIONDATA) dpcheng = (new PnlMsdcUsr1NSession()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSRAACCESSDATA) dpcheng = (new PnlMsdcUsrAAccess()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSRDATA) dpcheng = (new CrdMsdcUsr()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSRDETAILDATA) dpcheng = (new PnlMsdcUsrDetail()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSRHEADBARDATA) dpcheng = (new PnlMsdcUsrHeadbar()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSRLISTDATA) dpcheng = (new PnlMsdcUsrList()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSRMNUSERGROUPDATA) dpcheng = (new PnlMsdcUsrMNUsergroup()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGMSDCUSRRECDATA) dpcheng = (new PnlMsdcUsrRec()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGROOTMSDCDATA) dpcheng = (new RootMsdc()).new DpchEngData();
			else if (ixMsdcVDpch == VecMsdcVDpch.DPCHENGSESSMSDCDATA) dpcheng = (new SessMsdc()).new DpchEngData();

			if (dpcheng != null) dpcheng.readXML(doc,  "",  true);

		} catch (IOException e) {
			System.out.println(e.toString());
		} catch (ParserConfigurationException e) {
			System.out.println(e.toString());
		} catch (SAXException e) {
			System.out.println(e.toString());
		};

		return dpcheng;
	};

	public static String writeDpchApp(
				DpchAppMsdc dpchapp
			) {
		Document doc;
		StringWriter str = new StringWriter();

		try {
			doc = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
	
			dpchapp.writeXML(doc, null);
	
			Transformer tr = TransformerFactory.newInstance().newTransformer();
	
			tr.transform(new DOMSource(doc), new StreamResult(str));
	
			return(str.toString());

		} catch (ParserConfigurationException e) {
			System.out.println(e.toString());
		} catch (TransformerConfigurationException e) {
			System.out.println(e.toString());
		} catch (TransformerException e) {
			System.out.println(e.toString());
		};
		
		return "";
	};
};

