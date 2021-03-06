#include<iostream>

using namespace std;

// 제곱근을 쓰지 않고, r의 차이도 제곱해서 int형으로 만들어주는게 좋을듯
// 실수 연산에는 오차가 존재할 수 있다.

int main() {
	int x1, y1, r1, x2, y2, r2;
	int t;
	int dist;
	int rsum, rdif;
	cin >> t;

	while (t--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		dist = (x1 - x2) * (x1 - x2) + (y1-y2) * (y1-y2);
		rsum = (r1 + r2) * (r1 + r2);
		rdif = (r1 - r2) * (r1 - r2);

		//if (x1 == x2 && y1 == y2) {
		//	if ((r1 == r2)) {
		//		cout << "-1" << '\n';
		//	
		//	}
		//	else {
		//		cout << "0" << '\n';
		//	
		//	}
		//}
		//else if (dist < abs(r1 + r2)) {
		//	if (abs(r2 - r1) == dist)
		//		cout << "1" << '\n';
		//	else if (abs(r2 - r1) > dist)
		//		cout << "0" << '\n';
		//	else
		//		cout << "2" << '\n';
		//}
		//else if (dist = abs(r1 + r2)) {
		//	if (x1 == x2 && y1 == y2) {
		//		cout << "-1" << '\n';
		//	}
		//	else
		//		cout << "1" << '\n';
		//}
		//else if (dist > abs(r1 + r2)) {
		//	cout << "0" << '\n';
		//}

		// 좌표 같을 때
		if (dist == 0) {
			if (r1 == r2)
				cout << "-1" << '\n';
			else
				cout << "0" << '\n';
		}// 좌표 다를 때
		else if (dist == rsum || dist == rdif) {
			cout << "1" << '\n';
		}
		else if (dist < rsum && dist > rdif)
			cout << "2" << '\n';
		else
			cout << "0" << '\n';
	}
}