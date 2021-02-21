#include<iostream>
using namespace std;

int a, b;

int main() {
	while (cin >> a >> b) { // 입력이 없을 경우 종료. 즉, 두 수의 입력이 있는게 while문 조건
		cout << a + b << '\n';
	}
}