#pragma once

//����� � ������������
class point {
public:
	double x, y; //���������� �����
	//����������� ������
	point(double _x, double _y) {
		x = _x;
		y = _y;
	}
	//����������� �� ���������
	point() {
		x = y = 0;
	}
};