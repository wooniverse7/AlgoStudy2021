// const
// �ڷ� Ÿ�� �� const : �ش� ����� ���� �������� ����. 
// �ڷ� Ÿ�԰� ���� ���� ���� �� : �ּҸ� �ٲ��� ����

// �Լ��� const�� ����ϴ� ���
// ��� ������ ���� �������� �ʴ� �޼��忡���� ���
// Const ��ü�� ����ؼ� �� �Լ��� ȣ���� �� �ִ�.

#include<iostream>
using namespace std;

typedef unsigned int* ui_ptr; // �ڷ����� ���� ����

typedef void (*FP1)(int); // ���� Ÿ�� (����ҷ��� ������ �̸�)(�ñ״��� : �Ű����� Ÿ��) = 
typedef void (Point::*FP2)(int); // Ŭ������ ����Լ� ������ �Լ�������. �ش� �κп� �����ϱ� ����

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
	cout << "0, 0�� �� ���� �̷�� �簢���� ���� = " << area << endl;
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