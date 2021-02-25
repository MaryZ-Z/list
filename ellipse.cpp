#pragma once
#include "ellipse.h"
#include <math.h>

//����� ��
double pi = 3.14159265359;

//������� ���������� ������� �������
double ellipse::getSquare() {
	//������� ������� ������� ����� �������: a*b*pi
	return a*b*pi;
}
//������� ���������� ������ ������
pair<point, point> ellipse::getFocus() {
	point f1, f2; //������ �������
	double c;	//�������� ���������� ����� �������� (f1f2 = 2c)

	//������ ��������� �� ������� �������, ����� ����� ����������� ��� ������
	if (a > b) {
		c = sqrt(a*a - b*b);	//������� ���������� ����� ��������
		f1 = point(center.x+c, center.y);	//���� ���������� ����� �������� ����� ����� � ���� ������
		f2 = point(center.x-c, center.y);
	}
	else {
		c = sqrt(b*b-a*a);
		f1 = point(center.x, center.y+c);
		f2 = point(center.x, center.y-c);
	}
	//��������� ���� �����
	return make_pair(f1, f2);
}
//�������, ������� �������� ����� �������
void ellipse::setCenter(double x, double y) {
	center = point(x,y);
}
//�������, ������� �������� �������� �������� (a ����� ��� �, b ����� ��� y)
void ellipse::setAxis(double x, double y) {
	//����� �������� �� ����� ���� ��������������
	if (x <= 0 || y <= 0)
		cout << "������������ �������� ��������!" << endl;
	a = x;
	b = y;
}
//������� ��� ����� ������ ������� � ��������
void ellipse::input() {
	cout << "������� ���������� ������ ������� ";
	cin >> center.x >> center.y;
	cout << "������� ����� �������� ";
	cin >> a >> b;
}

