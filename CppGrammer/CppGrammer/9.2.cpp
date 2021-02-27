// const, 객체 배열
#include<iostream>
#include"Point.h"
using namespace std;

void main() {
	// 동적 할당. 포인터로 받아야 한다. 주소를 받아야 하니까
	Point p1(5, 10);
	Point* p2 = new Point(); // default
	Point* p3 = new Point(50, 50); // 매개변수
	Point* p4 = new Point(p1); // 복사 생성자

	(*p2).Print();
	p3->Print();
	p4->Print();

	//for (auto i = 0; i < 4; i++)
	//	arr[i].Print();

	//Point arr[4] = {
	//Point(10, 20), Point(11, 27),
	//Point(99, 80), Point(1000, -99)
	//};
}