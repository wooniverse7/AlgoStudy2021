#include<iostream>
using namespace std;

int main() {

	// & ���ۻ��� ��ȣ�� �ٱ��� ������ �ٲ�
	int a1 = 1, b1 = 2;
	auto inha6 = [&a1, b1](float c, int d)-> int {
		a1 = 4;
		return a1 + b1 + c + d;
	};
	cout << "inha6 : " << inha6(3.5f, 4) << endl;
	cout << a1 << endl;

}