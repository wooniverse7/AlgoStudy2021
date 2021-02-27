// const
// 자료 타입 앞 const : 해당 대상의 값을 변경하지 못함. 
// 자료 타입과 변수 사이 왔을 때 : 주소를 바꾸지 못함

// 함수에 const를 사용하는 경우
// 멤버 변수의 값을 변경하지 않는 메서드에서만 사용
// Const 객체를 사용해서 이 함수를 호출할 수 있다.

#include<iostream>
using namespace std;

typedef unsigned int* ui_ptr; // 자료형에 대한 별명

typedef void (*FP1)(int); // 리턴 타입 (사용할려는 포인터 이름)(시그니쳐 : 매개변수 타입) = 
typedef void (Point::*FP2)(int); // 클래스의 멤버함수 참조용 함수포인터. 해당 부분에 접근하기 위해

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

int main() {
	Point pt(100, 100);
	//FP2 fp2 = &Point::SetY;
	//(pt.*fp2)(50);

	pt.Print();

}