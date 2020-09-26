#ifndef HALF_PLANE_SELECT_INTERSECTION
#define  HALF_PLANE_SELECT_INTERSECTION
//#pragma once

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include "myconfig.h"

using namespace std;



typedef struct Grid
{
	double x, y;
	Grid(double a = 0, double b = 0) { x = a; y = b; }

	//点到点的距离
	double distantTo(IN const Grid& pnt);
	Grid midPoint(IN const Grid& pnt);
}Point, Vector;



Vector operator -(Point a, Point b);
double operator ^(Vector a, Vector b);
Vector operator *(Vector a,double k);
Vector operator +(Vector a,Vector b);

struct Line
{
	Point s, e;
	Line() {}
	Line(Point a, Point b) { s = a; e = b; }
};



//得到极角角度
double getAngle(Vector a);

//得到极角角度
double getAngle(Line a);

//排序：极角小的排前面，极角相同的，最左边的排在最后面，以便去重.
bool cmp(Line a, Line b);

//得到两直线的交点.
Point getIntersectPoint(Line a, Line b);


//判断b,c的交点是否在a的右边.
bool OnRight(Line a, Line b, Line c);
bool HalfPlaneIntersection();

//判断输入点的顺序，如果面积 < 0,说明输入的点为顺时针，否则为逆时针.
bool judge();


#endif // !HALF_PLANE_SELECT_INTERSECTION


