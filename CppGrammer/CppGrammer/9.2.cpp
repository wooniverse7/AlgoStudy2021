// const, ��ü �迭
#include<iostream>
#include"Point.h"
using namespace std;

void main() {
	// ���� �Ҵ�. �����ͷ� �޾ƾ� �Ѵ�. �ּҸ� �޾ƾ� �ϴϱ�
	Point p1(5, 10);
	Point* p2 = new Point(); // default
	Point* p3 = new Point(50, 50); // �Ű�����
	Point* p4 = new Point(p1); // ���� ������

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