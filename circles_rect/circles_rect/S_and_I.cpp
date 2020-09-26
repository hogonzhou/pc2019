// S_and_I.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include "S_and_I.h"
#include "myconfig.h"

using namespace std;

//���ֱ������.
const int maxn = 1e3;
//һ�����ֵ.
//const double EPS = 1e-5;
int T, n;
Line L[maxn], que[maxn];
Point p[maxn];
Vector operator -(Point a, Point b) { return Vector(b.x - a.x, b.y - a.y); }
double operator ^(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }  //���.
Vector operator *(Vector a, double k) { return Vector(a.x * k, a.y *k); }
Vector operator +(Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }

//�õ����ǽǶ�
double getAngle(Vector a)
{
	return atan2(a.y, a.x);
}

//�õ����ǽǶ�
double getAngle(Line a)
{
	return atan2(a.e.y - a.s.y, a.e.x - a.s.x);
}

//���򣺼���С����ǰ�棬������ͬ�ģ�����ߵ���������棬�Ա�ȥ��.
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


//�õ���ֱ�ߵĽ���.
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


//�ж�b,c�Ľ����Ƿ���a���ұ�.
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
	sort(L, L + n, cmp); //����
	int head = 0;
	int tail = 0;
	int cnt = 0;  //ģ��˫�˶���.

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
		//�ж��¼���ֱ�߲�����Ӱ��.
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


//�ж�������˳�������� < 0,˵������ĵ�Ϊ˳ʱ�룬����Ϊ��ʱ��.
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���:
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�


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


//���е�
Grid Grid::midPoint(IN const Grid& pnt)
{
	Grid midPnt;
	midPnt.x = (x + pnt.x) / 2.0;
	midPnt.y = (y + pnt.y) / 2.0;
	return midPnt;
}
