// S_and_I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include "S_and_I.h"
#include "myconfig.h"

using namespace std;

//最大直线数量.
const int maxn = 1e3;
//一个误差值.
//const double EPS = 1e-5;
int T, n;
Line L[maxn], que[maxn];
Point p[maxn];
Vector operator -(Point a, Point b) { return Vector(b.x - a.x, b.y - a.y); }
double operator ^(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }  //叉乘.
Vector operator *(Vector a, double k) { return Vector(a.x * k, a.y *k); }
Vector operator +(Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }

//得到极角角度
double getAngle(Vector a)
{
	return atan2(a.y, a.x);
}

//得到极角角度
double getAngle(Line a)
{
	return atan2(a.e.y - a.s.y, a.e.x - a.s.x);
}

//排序：极角小的排前面，极角相同的，最左边的排在最后面，以便去重.
bool
cmp(Line a, Line b)
{
	Vector va = a.e - a.s;
	Vector vb = b.e - b.s;
	double A = getAngle(va);
	double B = getAngle(vb);
	if (fabs(A - B) < EPS)
	{
		return ((va) ^ (b.e - a.s)) >= 0;
	}
	else
	{
		return A < B;
	}
}


//得到两直线的交点.
Point
getIntersectPoint(Line a, Line b)
{
	double a1 = a.s.y - a.e.y;
	double b1 = a.e.x - a.s.x;
	double c1 = a.s.x * a.e.y - a.e.x * a.s.y;
	double a2 = b.s.y - b.e.y;
	double b2 = b.e.x - b.s.x;
	double c2 = b.s.x * b.e.y - b.e.x * b.s.y;

	return Point((c1*b2 - b1 * c2) / (a2*b1 - a1 * b2), (a2*c1 - a1 * c2) / (a1*b2 - a2 * b1));
}


//判断b,c的交点是否在a的右边.
bool
OnRight(Line a, Line b, Line c)
{
	Point o = getIntersectPoint(b, c);
	if (((a.e - a.s) ^ (o - a.s)) < 0)
	{
		return true;
	}
	return false;
}


bool
HalfPlaneIntersection()
{
	sort(L, L + n, cmp); //排序
	int head = 0;
	int tail = 0;
	int cnt = 0;  //模拟双端队列.

	for (int i = 0; i < n - 1; i++)
	{
		if (fabs(getAngle(L[i])) - getAngle(L[i + 1]) < EPS)
		{
			continue;
		}
		L[cnt++] = L[i];
	}
	L[cnt++] = L[n - 1];

	for (int i = 0; i < cnt; i++)
	{
		//判断新加入直线产生的影响.
		while (tail - head > 1 && OnRight(L[i], que[tail - 1], que[tail - 2]))
		{
			tail--;
		}

		while (tail - head > 1 && OnRight(L[i], que[head], que[head + 1]))
		{
			head++;
		}
		que[tail++] = L[i];
	}

	while (tail - head > 1 && OnRight(que[head], que[tail - 1], que[tail - 2]))
	{
		tail--;
	}

	while (tail - head > 1 && OnRight(que[tail - 1], que[head], que[head + 1]))
	{
		head++;
	}
	if (tail - head < 3)
	{
		return false;
	}
	return true;

}


//判断输入点的顺序，如果面积 < 0,说明输入的点为顺时针，否则为逆时针.
bool
judge()
{
	double ans = 0;
	for (int i = 1; i < n - 1; i++)
	{
		ans += ((p[i] - p[0]) ^ (p[i + 1] - p[0]));
	}
	return ans < 0;
}

int test()
{
	std::cout << "Hello World!\n";

	scanf_s("%d", &T);
	while (T--)
	{
		for (int i = n - 1; i >= 0; i++)
		{
			scanf_s("%1f,%1f", &p[i].x, &p[i].y);
		}

		if (judge())
		{
			for (int i = 0; i < n; i++)
			{
				L[i] = Line(p[(i + 1) % n], p[i]);
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				L[i] = Line(p[i], p[(i + 1) % n]);
			}
		}

		if (HalfPlaneIntersection())
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


/*======================
struct Grid
======================*/
double Grid::distantTo(IN const Grid& pnt)
{
	double x1 = pnt.x;
	double y1 = pnt.y;

	double dist = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
	return dist;
}


//求中点
Grid Grid::midPoint(IN const Grid& pnt)
{
	Grid midPnt;
	midPnt.x = (x + pnt.x) / 2.0;
	midPnt.y = (y + pnt.y) / 2.0;
	return midPnt;
}
