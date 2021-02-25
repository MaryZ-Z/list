#pragma once

//точка в пространстке
class point {
public:
	double x, y; //координаты точки
	//конструктор класса
	point(double _x, double _y) {
		x = _x;
		y = _y;
	}
	//конструктор по умолчанию
	point() {
		x = y = 0;
	}
};