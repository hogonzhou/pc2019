#pragma once

#include <rxboiler.h>
#include "adesk.h"
#include "dbcurve.h"
#include "stdAfx.h"


/*
* class MyClass
* 添加了类型自动识别功能.可以返回类描述符对象.
*/
class MyClass :public AcDbCurve
{
public:
	//自定义类加入下列宏，用来声明类型识别功能.
	ACRX_DECLARE_MEMBERS(MyClass);

	MyClass();
	~MyClass();

private:
	int m_count;
};
