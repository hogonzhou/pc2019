#include "circles.h"

CalCircumscribedCircles::CalCircumscribedCircles(IN const StCircle first, IN const StCircle second, IN const StCircle circForCenter)
{
	m_firstCirc = first;
	m_secondCirc = second;
	m_circForCenter = circForCenter;

	bCircumscribedCircleExist =false;
	bLeftCircumscribedCircleExist = false;
	bRightCircumscribedCircleExist = false;
	bMidCircumscribedCircleExist = false;

	m_edgeA = m_firstCirc.m_center.distantTo(m_secondCirc.m_center);
	m_edgeB = 0;
	m_edgeC = 0;
	m_rA = m_firstCirc.m_radius;
	m_rB = m_secondCirc.m_radius;
	m_rC = m_circForCenter.m_radius;

	if (isCircumscribedCircleExist())
	{
		//m_edgeA = m_firstCirc.m_center.distantTo(m_secondCirc.m_center);
		m_edgeB = m_rB + m_rC;
		m_edgeC = m_rC + m_rA;
		//求圆形a圆心所在的夹角.
		calAngleA(m_edgeA, m_edgeB, m_edgeC, m_angBtwAC);		
	}
}

CalCircumscribedCircles::~CalCircumscribedCircles()
{
}


StCircle 
CalCircumscribedCircles::prsCircumscribedCircle(double angleBtwAC)
{	
	//计算外切圆形的圆心坐标,各参数顺序不能错.
	//求外切圆圆心坐标.
	//已知三条边边长，其中两点坐标，求第三点坐标.	
	//m_angBtwAC = calAngleA(m_edgeA,m_edgeB,m_edgeC,m_angBtwAC);
	Vector vA = m_firstCirc.m_center;
	Vector vAB = m_firstCirc.m_center - m_secondCirc.m_center;
	Vector vAC;
	vAC = rotate(vAB, angleBtwAC);
	//调整长度	
	vAC = scale(vAC, m_edgeC / m_edgeA);
	//加上vA.
	vAC = vAC + vA;
	m_circForCenter.m_center = vAC;
	m_circForCenter.m_isValid = true;

	return m_circForCenter;
}


StCircle
CalCircumscribedCircles::rtnLeftCircumscribedCircle()
{
	if (!bRightCircumscribedCircleExist)
	{
		m_circForCenter.m_isValid = false;
		return m_circForCenter;
	}
	return prsCircumscribedCircle(m_angBtwAC);
}


//计算右切圆.
StCircle 
CalCircumscribedCircles::rtnRightCircumscribedCircle()
{
	if (!bRightCircumscribedCircleExist)
	{
		m_circForCenter.m_isValid = false;
		return m_circForCenter;
	}
	return prsCircumscribedCircle(2*Pi - m_angBtwAC);
}

Vector
CalCircumscribedCircles::rotate(Vector vAB, double ang)
{
	//通过对vAB旋转得到vAC.
	Vector vAC;
	vAC.x = cos(ang) * vAB.x - sin(ang)*vAB.y;
	vAC.y = sin(ang) *vAB.x + cos(ang) * vAB.y;

	return vAC;
}

Vector 
CalCircumscribedCircles::scale(Vector vAC, double scale)
{
	//调整长度
	vAC = vAC * scale;	
	return vAC;
}

StCircle 
CalCircumscribedCircles::rtnMidCircumscribedCircle()
{
	StCircle tempCirc;
	tempCirc = m_circForCenter;
	if (bMidCircumscribedCircleExist)
	{
		tempCirc.m_center = m_firstCirc.m_center.midPoint(m_secondCirc.m_center);
		tempCirc.m_isValid = true;
	}
	return tempCirc;
}


bool
CalCircumscribedCircles::isCircumscribedCircleAB()
{
	bool bFlag = m_firstCirc.isCircumscribedWith(m_secondCirc);
	return bFlag;
}


bool 
CalCircumscribedCircles::isLeftCircumscribedCircleExist()
{
	return bLeftCircumscribedCircleExist;
}


bool
CalCircumscribedCircles::isMidCircumscribedCircleExist()
{
	return bMidCircumscribedCircleExist;
}


//判断两个double是否相等.
bool
CalCircumscribedCircles::isEqual(const double& d1, const double& d2)
{
	double temp = fabs(d1 - d2);
	if(temp >= 0 && temp <= EPS)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//计算a边与c边的夹角，也是b对的角(也是第一个圆形A圆心所在的角)
//已知：三角形三条边a、b、c
//a：第一个圆形中心到第二个圆形中心的边长，b:第二个圆形圆心到第三个圆形圆心的边长;c:以此类推.
bool 
CalCircumscribedCircles::calAngleA(IN const double a, IN const double b, IN const double c,OUT double& ang)
{
	double cosA = (a*a + c * c - b * b) / (2 * a*c);
	if(cosA > 1.0f or cosA < -1.0f)
	{
		return false;
	}
	ang = acosf(cosA);
	return true;
}

bool 
CalCircumscribedCircles::isCircumscribedCircleExist()
{
	//求2圆形中心距离.	
	double radiusSbct = fabs(m_rA -m_rB);
	double dist = m_firstCirc.m_center.distantTo(m_secondCirc.m_center);
	
	//两圆形一个完全包含另一个.则不存在外切园.
	//两圆形离得太远.
	if (dist < radiusSbct + EPS)
	{
		bCircumscribedCircleExist = false;		
	}
	else if(dist  > EPS + m_rA + m_rB + m_rC)
	{
		bCircumscribedCircleExist = false;
	}
	else if (isEqual(dist, m_rA + m_rB + m_rC))
	{
		bMidCircumscribedCircleExist = true;
		bCircumscribedCircleExist = true;
	}
	else
	{
		bCircumscribedCircleExist = true;
		bLeftCircumscribedCircleExist = true;
		bRightCircumscribedCircleExist = true;
	}
	return bCircumscribedCircleExist;
} 


/*======================
struct StCircle
======================*/
StCircle::StCircle(const StCircle& circle)
{
	m_center = circle.m_center;
	m_radius = circle.m_radius;
	m_isValid = false;
}


StCircle::StCircle()
{
}

double
StCircle::distantFromCenterToCenter(IN const StCircle& stCirc)
{	
	double dist = m_center.distantTo(stCirc.m_center);
	return dist;
}


//AB两圆是否相交
//判断圆心距离即可
bool 
StCircle::isIntersectedWith(IN const StCircle& stCirc)
{
	double dist = m_center.distantTo(stCirc.m_center);
	double distMin = fabs(m_radius - stCirc.m_radius);
	double distMax = m_radius + stCirc.m_radius;
	if ((dist > distMin + EPS) && (dist < distMax - EPS))
	{
		return true;
	}
	return false;
}


bool 
StCircle::isCircumscribedWith(IN const StCircle& stCirc)
{
	double rA = m_radius;
	double rB = stCirc.m_radius;
	double dist = m_center.distantTo(stCirc.m_center);
	bool bFlag = CalCircumscribedCircles::isEqual(dist, rA + rB);

	return bFlag;
}

/*======================
test part
======================*/
void
test()
{
	Point pnt(1,1);
	StCircle c1;
	c1.m_radius = 5;
	c1.m_center = pnt;

	pnt.x = 16;
	pnt.y = 10;
	StCircle c2;
	c2.m_radius = 8;
	c2.m_center = pnt;
		
	StCircle c3;
	c3.m_radius = 7;	

	CalCircumscribedCircles calIt(c1, c2, c3);
	calIt.rtnLeftCircumscribedCircle();
	calIt.rtnRightCircumscribedCircle();
}
