#include "Point.h"
#include<iostream>
using namespace std;

Point::Point() {
	x = 0;
	y = 0;
}
Point::Point(int _x, int _y) {
	x = _x;
	y = _y;
}
Point::Point(const Point& pt) {
	x = pt.x;
	y = pt.y;
}

void Point::Print() const {
	cout << x << ", " << y << endl;
}