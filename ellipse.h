#pragma once
#include "point.h"
#include <iostream>
using namespace std;

class ellipse {
public:
	point center;	//���������� ������ �������
	double a, b;	//����� ��������. � - �������, ������� �������� ����� ��� �, b ����� ��� y

	double getSquare();	//������� ���������� ������� �������
	pair<point, point> getFocus();	//������� ���������� ���� �����, ������� ������� �������� ������
	void setCenter(double x, double y);	//�������, ������� �������� ����� �������
	void setAxis(double a, double b);	//�������, ������� �������� �������� �������� (a ����� ��� �, b ����� ��� y)
	void input();	//������� ��� ����� ������ ������� � ��������
};