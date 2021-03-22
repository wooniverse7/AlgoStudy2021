#include<iostream>

using namespace std;

int main() {
	int up, down, top, n;

	cin >> up >> down >> top;

	// n일차의 높이를 구해야 함
	//n = top / (up - down);
	//cout << n + 1;

	// 시간초과
	//int h = 0;
	//while (1) {
	//	h += up;
	//	if (top <= h) {
	//		cout << n;
	//		break;
	//	}
	//	h -= down;
	//	n++;
	//}

	////up을 뺏으니 하루가 적다. down을 빼야한다.
	//n = (top - up) / (up - down) + 1;

	//if ((top - up) % (up - down) == 0) {
	//	cout << n;
	//}
	//else{
	//	// 나머지가 있으면 1을 더해준다.
	//	cout << n+1;
	//}

	cout << (top - down - 1) / (up - down) + 1;
	// int의 나눗셈 연산 나머지 성질을 이용
	// 미리 1을 빼서 (top-down)%(up-down)의 나머지가 없는것을 있게만든 후 무조건 +1
	// 원래 나머지 있던 것들은 up-down >= 1이기 때문에 영향X
	// 그러니 몫에 -1을 빼고 전체에 무조건 +1을 하면 된다.
}