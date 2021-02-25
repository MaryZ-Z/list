#pragma once
#include "point.h"
#include <iostream>
using namespace std;

class ellipse {
public:
	point center;	//координаты центра эллипса
	double a, b;	//длины полуосей. а - полуось, которая проходит вдоль оси х, b вдоль оси y

	double getSquare();	//функция возвращает площадь эллипса
	pair<point, point> getFocus();	//функция возвращает пару точек, которые являюся фокусами эллипа
	void setCenter(double x, double y);	//функция, которая изменяет центр эллипса
	void setAxis(double a, double b);	//функция, которая изменяет значение полуосей (a вдоль оси х, b вдоль оси y)
	void input();	//функция для ввода центра эллипса и полуосей
};