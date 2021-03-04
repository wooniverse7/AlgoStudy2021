#include<iostream>

using namespace std;

int main() {
	unsigned long int A, B, C; // 기본 비용, 생산 비용, 제품 가격
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
	// 시간초과

	if (B >= C) {
		cout << "-1";
		return 0;
	}

	// A + Bx = Cx
	// A + (B-C)x = 0
	// x = A / (C-B)
	x = A/(C-B) + 1; // 그것보다 하나 더 있어야 손익분기점

	// O(1) time

	cout << x;
}