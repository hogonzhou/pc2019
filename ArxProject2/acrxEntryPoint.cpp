// (C) Copyright 2002-2012 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include "selfDefineClass.h"
#include ".\\src_code\brkgroups.h"
#include ".\\src_code\brkarc.h"
#include ".\\src_code\chkInterSection.h"
#include ".\\src_code\chgEntClr.h"
#include ".\\src_code\deldim.h"
#include ".\\src_code\delhth.h"
#include ".\\src_code\delcutlines.h"
#include ".\\src_code\ext.h"
#include ".\\src_code\explode_insert.h"
#include ".\\src_code\explodeMtext.h"
#include ".\\src_code\fr_out.h"
#include ".\\src_code\itrblk.h"
#include ".\\src_code\kubun.h"
#include ".\\src_code\laigeguangdian.h"
#include ".\\src_code\purge.h"
#include ".\\src_code\qylogo.h"
#include ".\\src_code\repa.h"
#include ".\\src_code\setdim.h"
#include ".\\src_code\shortcut.h"
#include ".\\src_code\szhc.h"
#include ".\\src_code\sz01_id_append.h"
#include ".\\src_code\test.h"
#include ".\\src_code\openalllayer.h"
#include ".\\src_code\xiamenchenhong_text.h"
#include ".\\src_code\basefunc.h"
#include ".\\src_code\openalllayer.h"
#include ".\\src_code\createlayer.h"
#include ".\\src_code\ajustfont.h"
#include ".\\src_code\explodeMtext.h"
#include ".\\src_code\splitpolyline.h"
#include ".\\src_code\splitpolyline.h"
#include ".\\src_code\tmt.h"
#include ".\\src_code\prtDir.h"
#include ".\\src_code\polyline_info.h"
//shanghai sumsung,widen the lines with different color to different width.
#include ".\\src_code\shanghaisanxing.h" 
#include ".\\src_code\qylogo.h" 
#include ".\\src_code\bk.h" 
#include ".\\src_code\hcgx_one.h" 
#include ".\\src_code\mapan.h" 
#include ".\\src_code\ltlogo.h"
#include ".\\src_code\draw2.h"
#include ".\\src_code\t2la.h"
#include ".\\src_code\selfintersect.h"
#include ".\\src_code\to_pl.h"
#include ".\\src_code\elapsetime.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("owal")

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CArxProject2App : public AcRxArxApp {

public:
	CArxProject2App () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		// TODO: Add your initialization code here

		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}
	
	// The ACED_ARXCOMMAND_ENTRY_AUTO macro can be applied to any static member 
	// function of the CArxProject2App class.
	// The function should take no arguments and return nothing.
	//
	// NOTE: ACED_ARXCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid and
	// have arguments to define context and command mechanism.
	
	// ACED_ARXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext)
	// ACED_ARXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext)
	// only differs that it creates a localized name using a string in the resource file
	//   locCmdId - resource ID for localized command

	// Modal Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, owalMyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL)
	static void owalMyGroupMyCommand () {
		// Put your command code here
		MyClass myobj;

		//if (myobj.isA() == MyClass::desc())
		if(AcDbCurve* p = AcDbCurve::cast(&myobj))
		{
			acutPrintf(TEXT("I am a AcDbCurve class \n"));
		}
		else
		{
			acutPrintf(TEXT("I am not a AcDbCurve class \n"));
		}
	}

	// Modal Command with pickfirst selection
	// ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, owalMyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET)
	static void owalMyGroupMyPickFirst () {
		ads_name result ;
		int iRet =acedSSGet (ACRX_T("_I"), NULL, NULL, NULL, result) ;
		if ( iRet == RTNORM )
		{
			// There are selected entities
			// Put your command using pickfirst set code here
		}
		else
		{
			// There are no selected entities
			// Put your command code here
		}
	}

	// Application Session Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, owalMyGroup, MySessionCmd, MySessionCmdLocal, ACRX_CMD_MODAL | ACRX_CMD_SESSION)
	static void owalMyGroupMySessionCmd () {
		// Put your command code here
	}

	// ----- ZHGpc2004m.test command (do not rename)
	static void ZHGpc2004mtest(void)
	{
		// Add your code for command ZHGpc2004m.test here
		//1
		//getnet();//testing function:select objects by the polyline fence.

		//2
		//CShsx objShsx;
		//objShsx.doit();

		//3
		/*
		ads_name ss;

		try
		{
			SM_SetVar();
			SM_FoundSS(ss);
			SM_ToPl(ss,0.0005);
			//SM_EndChkWithArea(ss,true);
			acedSSFree(ss);
		}
		catch(...)
		{
			acutPrintf("\nwhat happened?");
		}
		*/

		//3
		//test the hash_map.

		acutPrintf(_T("\nlong type size is %d"), sizeof(long));
		unordered_map<int, int> hm;
		hm[1] = 2;
		pair<int, int> a(2, 5);
		hm.insert(a);
		acutPrintf(_T("\nhm[1] is %d"), hm[1]);
		acutPrintf(_T("\nhm[2] is %d"), hm[2]);
	}


	// ----- ZHGpc2004m.owal command (do not rename)
	//Here it is just for testing funtion.
	static void ZHGpc2004mowal(void)
	{
		// Add your code for command ZHGpc2004m.owal here
		//prtDir();
		CMapan obj;
		obj.doit();
	}


	// ----- ZHGpc2004m.fr_out command (do not rename)
	static void ZHGpc2004mfr_out(void)
	{
		// Add your code for command ZHGpc2004m.fr_out here
		fr_out();
	}


	// ----- ZHGpc2004m.dg command (do not rename)
	static void ZHGpc2004mdg(void)
	{
		// Add your code for command ZHGpc2004m.dg here
		drawedge();
	}

	// ----- ZHGpc2004m.ext command (do not rename)
	static void ZHGpc2004mext(void)
	{
		// Add your code for command ZHGpc2004m.ext here
		mb();
	}

	// ----- ZHGpc2004m.pc command (do not rename)
	static void ZHGpc2004mpc(void)
	{
		// Add your code for command ZHGpc2004m.pc here
		purge();
	}

	// ----- ZHGpc2004m.kubun command (do not rename)
	static void ZHGpc2004mkubun(void)
	{
		// Add your code for command ZHGpc2004m.kubun here
		kubun();
	}

	// ----- ZHGpc2004m.szhc command (do not rename)
	static void ZHGpc2004mszhc(void)
	{
		// Add your code for command ZHGpc2004m.szhc here
		suzhouhongce();
	}

	// ----- ZHGpc2004m.repa command (do not rename)
	static void ZHGpc2004mrepa(void)
	{
		// Add your code for command ZHGpc2004m.repa here
		arc_report();
	}

	// ----- ZHGpc2004m.xi command (do not rename)
	static void ZHGpc2004mxi(void)
	{
		// Add your code for command ZHGpc2004m.xi here
		xb();
	}

	// ----- ZHGpc2004m.dh command (do not rename)
	static void ZHGpc2004mdh(void)
	{
		// Add your code for command ZHGpc2004m.dh here
		delHatch();
	}

	// ----- ZHGpc2004m.dm command (do not rename)
	static void ZHGpc2004mdm(void)
	{
		// Add your code for command ZHGpc2004m.dm here
		chcolo();
	}

	// ----- ZHGpc2004m.xg command (do not rename)
	static void ZHGpc2004mxg(void)
	{
		// Add your code for command ZHGpc2004m.xg here
		brk_groups();
	}

	// ----- ZHGpc2004m.del_cut command (do not rename)
	static void ZHGpc2004mdel_cut(void)
	{
		// Add your code for command ZHGpc2004m.del_cut here
		del_cut();
	}

	// ----- ZHGpc2004m.xa command (do not rename)
	static void ZHGpc2004mxa(void)
	{
		// Add your code for command ZHGpc2004m.xa here
		breakbigarc();
	}

	// ----- ZHGpc2004m.repb command (do not rename)
	static void ZHGpc2004mrepb(void)
	{
		// Add your code for command ZHGpc2004m.repb here
		iterateBlkrcd();
	}

	// ----- ZHGpc2004m.sz01id command (do not rename)
	static void ZHGpc2004msz01id(void)
	{
		// Add your code for command ZHGpc2004m.sz01id here
		sz01id();
	}

	// ----- ZHGpc2004m.k command (do not rename)
	static void ZHGpc2004mk(void)
	{
		// Add your code for command ZHGpc2004m.k here
		CLayerOpt objLyrOpt;
		objLyrOpt.displayAll();
	}

	// ----- ZHGpc2004m.g command (do not rename)
	static void ZHGpc2004mg(void)
	{
		// Add your code for command ZHGpc2004m.g here
		CLayerOpt objLyrOpt;
		objLyrOpt.displayNone();
	}

	// ----- ZHGpc2004m.deldim command (do not rename)
	static void ZHGpc2004mdeldim(void)
	{
		// Add your code for command ZHGpc2004m.deldim here
		deldim();
	}

	// ----- ZHGpc2004m.lockalllayers command (do not rename)
	static void ZHGpc2004mlockalllayers(void)
	{
		// Add your code for command ZHGpc2004m.lockalllayers here
		CLayerOpt objLyrOpt;
		objLyrOpt.lockAll();
	}

	// ----- ZHGpc2004m.unlockalllayers command (do not rename)
	static void ZHGpc2004munlockalllayers(void)
	{
		// Add your code for command ZHGpc2004m.unlockalllayers here
		CLayerOpt objLyrOpt;
		objLyrOpt.unlockAll();
	}

	// ----- ZHGpc2004m.frozenalllayers command (do not rename)
	static void ZHGpc2004mfrozenalllayers(void)
	{
		// Add your code for command ZHGpc2004m.frozenalllayers here
	}

	// ----- ZHGpc2004m.unfrozenalllayers command (do not rename)
	static void ZHGpc2004munfrozenalllayers(void)
	{
		// Add your code for command ZHGpc2004m.unfrozenalllayers here
		CLayerOpt objLyrOpt;
		objLyrOpt.frozenAll();
	}

	// ----- ZHGpc2004m.createlayer command (do not rename)
	static void ZHGpc2004mcreatelayer(void)
	{
		// Add your code for command ZHGpc2004m.createlayer here
		createNewLayer();
	}

	// ----- ZHGpc2004m.set2arial command (do not rename)
	static void ZHGpc2004mset2arial(void)
	{
		// Add your code for command ZHGpc2004m.set2arial here
		CAjustFont jf(_T("arial"), WIN_TEXT);
		jf.apply();
		acedCommandS(RTSTR, "regen", 0);
	}

	// ----- ZHGpc2004m.explodemtext command (do not rename)
	static void ZHGpc2004mexplodemtext(void)
	{
		// Add your code for command ZHGpc2004m.explodemtext here
		explode_mtext();
	}

	// ----- ZHGpc2004m.chkb command (do not rename)
	static void ZHGpc2004mchkb(void)
	{
		// Add your code for command ZHGpc2004m.chkb here
		CBlkTblOpt objBlkTblOpt;
		objBlkTblOpt.modRcdName();
	}

	// ----- ZHGpc2004m.splitpl command (do not rename)
	static void ZHGpc2004msplitpl(void)
	{
		// Add your code for command ZHGpc2004m.splitpl here
		test_optimze();
	}

	// ----- ZHGpc2004m.tmtf command (do not rename)
	static void ZHGpc2004mtmtf(void)
	{
		// Add your code for command ZHGpc2004m.tmtf here
		test_fillet();
	}

	// ----- ZHGpc2004m.tmtadd command (do not rename)
	static void ZHGpc2004mtmtadd(void)
	{
		// Add your code for command ZHGpc2004m.tmtadd here
		testAddVtx();
	}

	// ----- ZHGpc2004m.set2txt command (do not rename)
	static void ZHGpc2004mset2txt(void)
	{
		// Add your code for command ZHGpc2004m.set2txt here
		CAjustFont jf(_T("txt.shx"), SHAPE_TEXT);
		jf.apply();
		acedCommandS(RTSTR, "regen", 0);
	}

	// ----- ZHGpc2004m.sumsung command (do not rename)
	static void ZHGpc2004msumsung(void)
	{//sumsung widen lines.
		// Add your code for command ZHGpc2004m.sumsung here
		CShsx objShsx;
		objShsx.doit();
	}

	static void ZHGpc2004mpline_vtx_num(void)
	{//report the number of vertex of the polyline.
		//return static void();
		CRptNumOfPline rpt;
		rpt.rpt();
	}

	// ----- ZHGpc2004m.qylogo command
	static void ZHGpc2004mqylogo(void)
	{
		// Add your code for command ZHGpc2004m.longtulogo here
		qylogo();
	}

	// ----- ZHGpc2004m.mp80bk command (do not rename)
	static void ZHGpc2004mmp80bk(void)
	{
		CLongtuBk bk;
		bk.drawBk();
		// Add your code for command ZHGpc2004m.mp80bk here
	}

	// ----- ZHGpc2004m.hongchengguangxue command
	static void ZHGpc2004mhongchengguangxue(void)
	{
		// Add your code for command ZHGpc2004m.hcgx here
		CHcgxAjustLines obj;
		obj.doit();
	}

	// - ZHGpc2010.ltlogo command (do not rename)

	static void ZHGpc2010ltlogo(void)
	{
		// Add your code for command ZHGpc2010.ltlogo here
		CLtlogo obj;
		obj.drawLogoWithParam();
	}

	// - ZHGpc2010.owal1 command (do not rename)
	static void ZHGpc2010owal1(void)
	{
		//读取一个文件的0和1，然后画一系列长方形。
		// Add your code for command ZHGpc2004m.readzeroone here
		//CLaigerFst obj;
		//obj.doit();

		CLaigerTwo obj;
		obj.doit();
		// Add your code for command ZHGpc2010.owal1 here
	}

	// ----- ZHGpc2010.t51 command
	static void ZHGpc2010t51(void)
	{
		//文字加宽。
		// Add your code for command ZHGpc2010.t2la here
		CTxt2pl obj;
		//obj.testlineWiden();
		obj.starText2PL();
	}

	// - ZHGpc2010.selfint command (do not rename)
	static void ZHGpc2010selfint(void)
	{
		ads_name ss;
		ads_name ssUnit;
		Adesk::Int32 nlen;
		//select(ss);

		int flag;
		flag = acedSSGet(NULL, NULL, NULL, NULL, ss); //选取一个实体.
		if (flag != RTNORM)
		{
			return;
		}

		flag = acedSSLength(ss, &nlen);
		if (flag != RTNORM)
		{
			return;
		}

		if (nlen != 1)
		{
			return;
		}
		else
		{
			acedSSName(ss, 0, ssUnit);
		}


		AcDbEntity *pent;

		AcDbObjectId id;
		acdbGetObjectId(id, ssUnit);
		acdbOpenAcDbEntity(pent, id, AcDb::kForRead);
		pent->upgradeOpen();

		AcDbPolyline *pln;
		pln = (AcDbPolyline*)pent;
		pent->downgradeOpen();
		pent->close(); //关闭多义线.

		//CPrsPlnSgmtPnt obj(pln);

		CTimeElapse objtime;
		CPrsPlnSgmtPnt obj(pln);
		obj.brk();
		// Add your code for command ZHGpc2010.selfint here
	}

	// - ZHGpc2010.owal2016topolyline command (do not rename)
	//线条聚合功能；
	static void ZHGpc2010owal2016topolyline(void)
	{
		CGraphEnts obj;
		obj.to_polyline();
		// Add your code for command ZHGpc2010.owal2016topolyline here
	}

	// The ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO macros can be applied to any static member 
	// function of the CArxProject2App class.
	// The function may or may not take arguments and have to return RTNORM, RTERROR, RTCAN, RTFAIL, RTREJ to AutoCAD, but use
	// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal to return
	// a value to the Lisp interpreter.
	//
	// NOTE: ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid.
	
	//- ACED_ADSFUNCTION_ENTRY_AUTO(classname, name, regFunc) - this example
	//- ACED_ADSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc) - only differs that it creates a localized name using a string in the resource file
	//- ACED_ADSCOMMAND_ENTRY_AUTO(classname, name, regFunc) - a Lisp command (prefix C:)
	//- ACED_ADSCOMMAND_ENTRYBYID_AUTO(classname, name, nameId, regFunc) - only differs that it creates a localized name using a string in the resource file

	// Lisp Function is similar to ARX Command but it creates a lisp 
	// callable function. Many return types are supported not just string
	// or integer.
	// ACED_ADSFUNCTION_ENTRY_AUTO(CArxProject2App, MyLispFunction, false)
	static int ads_MyLispFunction () {
		//struct resbuf *args =acedGetArgs () ;
		
		// Put your command code here

		//acutRelRb (args) ;
		
		// Return a value to the AutoCAD Lisp Interpreter
		// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal

		return (RTNORM) ;
	}

	static void owalMyGroupHello()
	{
		acutPrintf(TEXT("owalMyGrougHello...\n"));
	}	
} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CArxProject2App)

ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, owalMyGroup, MyCommand, mycom, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, owalMyGroup, MyPickFirst, mypick, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, owalMyGroup, MySessionCmd, myses, ACRX_CMD_MODAL | ACRX_CMD_SESSION, NULL)
ACED_ADSSYMBOL_ENTRY_AUTO(CArxProject2App, MyLispFunction, false)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, owalMyGroup, Hello, hi, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, owal, owal, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, fr_out, fr_out, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, dg, dg, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, ext, ext, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, pc, pc, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, kubun, kubun, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, szhc, szhc, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, repa, repa, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, xi, xi, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, dh, dh, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, dm, dm, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, xg, xg, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, del_cut, del_cut, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, xa, xa, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, repb, repb, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, test, test, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, sz01id, sz01id, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, k, releaselockfrozendisplay, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, g, trunoffdisplay, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, deldim, deldim, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, lockalllayers, ss, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, unlockalllayers, js, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, frozenalllayers, dj, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, unfrozenalllayers, jd, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, createlayer, ra, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, set2arial, ar, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, explodemtext, xm, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, chkb, checkandChangeBlockRecordName, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, splitpl, splitpolyline, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, tmtf, fillettmt, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, tmtadd, tmt_add_vertex, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, set2txt, txt, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, sumsung, sanxing, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, pline_vtx_num, pi, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, qylogo, qylogo, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, mp80bk, fr, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2004m, hongchengguangxue, hcgx, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2010, ltlogo, ltlogo, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2010, owal1, drawRects, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2010, t51, txt2pl51, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2010, selfint, selfintersection, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject2App, ZHGpc2010, owal2016topolyline, topln, ACRX_CMD_TRANSPARENT, NULL)

