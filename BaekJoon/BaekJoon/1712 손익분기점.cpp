#include<iostream>

using namespace std;

int main() {
	unsigned long int A, B, C; // �⺻ ���, ���� ���, ��ǰ ����
	unsigned long long int x = 0;
	cin >> A >> B >> C;

	//while (1) {
	//	++x;
	//	if (B >= C) {
	//		x = -1;
	//		break;
	//	}
	//	if (A + x * B < C * x)
	//		break;
	//}
	// �ð��ʰ�

	if (B >= C) {
		cout << "-1";
		return 0;
	}

	// A + Bx = Cx
	// A + (B-C)x = 0
	// x = A / (C-B)
	x = A/(C-B) + 1; // �װͺ��� �ϳ� �� �־�� ���ͺб���

	// O(1) time

	cout << x;
}