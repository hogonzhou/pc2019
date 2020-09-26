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
	//��2Բ�ĵľ���
	double distantFromCenterToCenter(IN const StCircle& stCirc);
	//AB��Բ�Ƿ��ཻ
	bool isIntersectedWith(IN const StCircle& stCirc);
	//AB�Ƿ�������
	bool isCircumscribedWith(IN const StCircle& stCirc);
	//���˶���Ϊ����ֵ��ʱ�򣬱�Ǵ˶����Ƿ�Ϸ�.
	bool m_isValid;
};


//���ܣ�����Բ������Բ.��Բ�β��ص�����������.��Բ����Բ����������0��1��2.
//���룺1.����������԰������Բ��a��b.2.����԰c�İ뾶��֪��
//���: ���Ƿ��������Բ������������Բ�����ꡣ
//���أ�����Բ��Բ��.
class CalCircumscribedCircles
{
public:
	CalCircumscribedCircles(IN const StCircle first, IN const StCircle second, IN const StCircle circForCenter);
	//ע�⣬��һ��Բ�͵ڶ���Բ˳���ܴ�	
	~CalCircumscribedCircles();

public:		
	StCircle rtnLeftCircumscribedCircle();
	StCircle rtnRightCircumscribedCircle();
	StCircle rtnMidCircumscribedCircle();
	//ԲA��԰b�Ƿ�����.
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
	//a�ߺ�c�ߵļн�.a��:԰a���ĵ�Բb����; b��:Բb���ĵ�Բc����.
	double m_angBtwAC;
	//����Բ����ɵ������ε�������;
	double m_edgeA;//��֪
	double m_edgeB;//δ֪
	double m_edgeC;//δ֪.
	//ԲA��԰b�Ƿ�����.
	bool m_bCircumscribedAB;
};


//�ڳ���������ڷŸ���Բ�Σ�Բ��֮�䲻���е���.
//Ҫ�󳤷��������������.
class FillCirclesInRect
{
	;
};

