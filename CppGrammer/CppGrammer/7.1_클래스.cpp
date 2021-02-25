#include<iostream>
using namespace std;
// 1. class 키워드를 사용
// 2. public과 같은 접근제어와 관련된 키워드 사용
// 3. 멤버 함수(메서드)를 정의 가능

// 생성자 : 객체를 생성할 때 자동적으로 호출되는 함수
// 소멸자 : 객체가 소멸할 때 자동으로 호출되는 함수
class Point {
public:
	int x, y;
	
	// 생성자들
	Point(); // 생성자는 리턴 타입이 없다. 클래스 이름과 같다.
	Point(int _x, int _y); // 받을려고 하는 인수는 언더스코어_를 붙이면 좋다.(위와 구분위해)
	// 복사 생성자 : 자신과 동일한 타입의 객체에 대한 레퍼런스(별명)를 인자로 받음
	Point(const Point& pt);

	// 메서드
	void Print();
};
// 1. 클래스 정의 안에는 메서드의 프로토타입만 남겨둔다.
// 2. 클래스 정의 밖에서는 범위 지정 연산자를 사용해서 함수를 정의
Point::Point() :x(0), y(0) { // 생성자
	
}
Point::Point(int _x, int _y) : x(_x), y(_y) { // 매개변수 생성자
	//x = _x;
	//y = _y;
}
Point::Point(const Point& pt){ // 생성자
	cout << "Copy Constructor!" << endl;
	x = pt.x;
	y = 0; // x는 원래 값, y는 내가 설정한 값을 받고 싶을 떄.
}
void Point::Print() {
	cout << x << ", " << y << endl;
}
int main() {
	Point p1;
	p1.x = 10;
	p1.y = 10;

	p1.Print();

	Point p2 = p1;
	p2.Print();

	Point p3(10, 20);
	p3.Print();

	Point p4(p1);
	p4.Print();
}