#include<iostream>
using namespace std;

class Point {
public:
	void Print() const;

	Point();
	Point(int _x, int _y);
	Point(const Point& pt);

	void SetX(int value);
	void SetY(int value);
	int GetX() const { return x; };
	int GetY() const { return y; };

private:
	int x, y;
};
void Area(const Point& pt) {
	int area = pt.GetX() * pt.GetY();
	cout << "0, 0과 이 점이 이루는 사각형의 면적 = " << area << endl;
}

inline void Point::SetX(int value) {
	if (value < 0)
		x = 0;
	else if (value > 100)
		x = 100;
	else
		x = value;
}
inline void Point::SetY(int value) {
	if (value < 0)
		y = 0;
	else if (value > 100)
		y = 100;
	else
		y = value;
}