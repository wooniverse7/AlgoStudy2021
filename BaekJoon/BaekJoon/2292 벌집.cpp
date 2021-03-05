#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int x = 2;
	int cnt = 2;


	while (1) {
		if (n == 1) {
			cout << "1";
			break;
		}
		if (n < 8) {
			cout << "2";
			break;
		}
		if (n - 8 < 6 * x) {
			cout << cnt+1;
			break;
		}
		x += ++cnt;
	}

}

//int main() {
//	cin >> n;
//	int x = 2;
//	int cnt = 3;
//	int a = 2;
//
//	while (1) {
//		if (n == 1) {
//			cout << "1";
//			break;
//		}
//		if (n < 8) {
//			cout << "2";
//			break;
//		}
//		if (n - 8 < 6 * x) {
//			cout << cnt;
//			break;
//		}
//		cnt++;
//		x += ++a;
//	}
//
//}