#include<iostream>
using namespace std;
// 1. class Ű���带 ���
// 2. public�� ���� ��������� ���õ� Ű���� ���
// 3. ��� �Լ�(�޼���)�� ���� ����

// ������ : ��ü�� ������ �� �ڵ������� ȣ��Ǵ� �Լ�
// �Ҹ��� : ��ü�� �Ҹ��� �� �ڵ����� ȣ��Ǵ� �Լ�
class Point {
public:
	int x, y;
	
	// �����ڵ�
	Point(); // �����ڴ� ���� Ÿ���� ����. Ŭ���� �̸��� ����.
	Point(int _x, int _y); // �������� �ϴ� �μ��� ������ھ�_�� ���̸� ����.(���� ��������)
	// ���� ������ : �ڽŰ� ������ Ÿ���� ��ü�� ���� ���۷���(����)�� ���ڷ� ����
	Point(const Point& pt);

	// �޼���
	void Print();
};
// 1. Ŭ���� ���� �ȿ��� �޼����� ������Ÿ�Ը� ���ܵд�.
// 2. Ŭ���� ���� �ۿ����� ���� ���� �����ڸ� ����ؼ� �Լ��� ����
Point::Point() :x(0), y(0) { // ������
	
}
Point::Point(int _x, int _y) : x(_x), y(_y) { // �Ű����� ������
	//x = _x;
	//y = _y;
}
Point::Point(const Point& pt){ // ������
	cout << "Copy Constructor!" << endl;
	x = pt.x;
	y = 0; // x�� ���� ��, y�� ���� ������ ���� �ް� ���� ��.
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