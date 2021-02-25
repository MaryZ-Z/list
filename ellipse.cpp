#pragma once
#include "ellipse.h"
#include <math.h>

//число пи
double pi = 3.14159265359;

//функция возвращает площадь эллипса
double ellipse::getSquare() {
	//формула площади эллипса через полуоси: a*b*pi
	return a*b*pi;
}
//функция возвращает фокусы эллипа
pair<point, point> ellipse::getFocus() {
	point f1, f2; //фокусы эллипса
	double c;	//половина расстояния между фокусами (f1f2 = 2c)

	//фокусы находятся на большей полуоси, тогда нужно рассмотреть два случая
	if (a > b) {
		c = sqrt(a*a - b*b);	//формула расстояния между фокусами
		f1 = point(center.x+c, center.y);	//зная расстояние между фокусами можно найти и сами фокусы
		f2 = point(center.x-c, center.y);
	}
	else {
		c = sqrt(b*b-a*a);
		f1 = point(center.x, center.y+c);
		f2 = point(center.x, center.y-c);
	}
	//возращаем пару точек
	return make_pair(f1, f2);
}
//функция, которая изменяет центр эллипса
void ellipse::setCenter(double x, double y) {
	center = point(x,y);
}
//функция, которая изменяет значение полуосей (a вдоль оси х, b вдоль оси y)
void ellipse::setAxis(double x, double y) {
	//длины полуосей не могут быть отрицательными
	if (x <= 0 || y <= 0)
		cout << "Недопустимое значение полуосей!" << endl;
	a = x;
	b = y;
}
//функция для ввода центра эллипса и полуосей
void ellipse::input() {
	cout << "Введите координаты центра эллипса ";
	cin >> center.x >> center.y;
	cout << "Введите длины полуосей ";
	cin >> a >> b;
}

