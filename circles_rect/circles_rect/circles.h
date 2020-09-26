#pragma once
#include "S_and_I.h"
#include "myconfig.h"

void test();

struct StCircle
{
	double m_radius;
	Point m_center;
	StCircle(const StCircle& circle);
	StCircle();
	//求2圆心的距离
	double distantFromCenterToCenter(IN const StCircle& stCirc);
	//AB两圆是否相交
	bool isIntersectedWith(IN const StCircle& stCirc);
	//AB是否相外切
	bool isCircumscribedWith(IN const StCircle& stCirc);
	//当此对象为返回值的时候，标记此对象是否合法.
	bool m_isValid;
};


//功能：求俩圆的外切圆.俩圆形不重叠，可能相切.俩圆外切圆数量可能是0，1，2.
//输入：1.用来求外切园的两个圆形a和b.2.外切园c的半径已知。
//输出: 求是否存在外切圆，几个？求其圆心坐标。
//返回：外切圆的圆心.
class CalCircumscribedCircles
{
public:
	CalCircumscribedCircles(IN const StCircle first, IN const StCircle second, IN const StCircle circForCenter);
	//注意，第一个圆和第二个圆顺序不能错。	
	~CalCircumscribedCircles();

public:		
	StCircle rtnLeftCircumscribedCircle();
	StCircle rtnRightCircumscribedCircle();
	StCircle rtnMidCircumscribedCircle();
	//圆A和园b是否相切.
	bool isCircumscribedCircleAB();	
	bool isLeftCircumscribedCircleExist();
	bool isMidCircumscribedCircleExist();

public:
	static bool isEqual(const double& d1,const double& d2);
	bool calAngleA(IN const double a,IN const double b,IN const double c,OUT double& ang);
	Vector rotate(Vector vAB, double ang);
	Vector scale(Vector vAC, double scale);
	StCircle prsCircumscribedCircle(double angleBtwAC);
	bool isCircumscribedCircleExist();

private:
	StCircle m_firstCirc;
	StCircle m_secondCirc;	
	StCircle m_circForCenter;
	double m_rA;
	double m_rB;
	double m_rC;
	bool bCircumscribedCircleExist;
	bool bLeftCircumscribedCircleExist;
	bool bRightCircumscribedCircleExist;
	bool bMidCircumscribedCircleExist;
	//a边和c边的夹角.a边:园a中心到圆b中心; b边:圆b中心到圆c中心.
	double m_angBtwAC;
	//三个圆心组成的三角形的三条边;
	double m_edgeA;//已知
	double m_edgeB;//未知
	double m_edgeC;//未知.
	//圆A和园b是否相切.
	bool m_bCircumscribedAB;
};


//在长方形里面摆放各种圆形，圆形之间不能有叠加.
//要求长方形面积最优利用.
class FillCirclesInRect
{
	;
};

