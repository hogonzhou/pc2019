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

	//�㵽��ľ���
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



//�õ����ǽǶ�
double getAngle(Vector a);

//�õ����ǽǶ�
double getAngle(Line a);

//���򣺼���С����ǰ�棬������ͬ�ģ�����ߵ���������棬�Ա�ȥ��.
bool cmp(Line a, Line b);

//�õ���ֱ�ߵĽ���.
Point getIntersectPoint(Line a, Line b);


//�ж�b,c�Ľ����Ƿ���a���ұ�.
bool OnRight(Line a, Line b, Line c);
bool HalfPlaneIntersection();

//�ж�������˳�������� < 0,˵������ĵ�Ϊ˳ʱ�룬����Ϊ��ʱ��.
bool judge();


#endif // !HALF_PLANE_SELECT_INTERSECTION


