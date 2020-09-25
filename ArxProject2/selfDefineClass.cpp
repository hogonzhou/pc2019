#include "selfDefineClass.h"


ACRX_DXF_DEFINE_MEMBERS(MyClass, AcDbCurve, AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, 0, Polygon, "AUTOCAD");

MyClass::MyClass()
{
	acutPrintf(TEXT("self defined class...\n"));
}

MyClass::~MyClass()
{
	acutPrintf(TEXT("exit MyClass...\n"));
}

