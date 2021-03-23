#include<iostream>
#include<stack>

using namespace std;

int plate[124];
int x;

void hanoi(int *plate, int from, int to, int cnt) {
	if (plate[0] == 0) {
		cout << from << " " << to << '\n';
		return;
	}
	else {

	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		plate[i] = x;
	}
	hanoi(plate, 1, 3, 0);
	cout << cnt;
}

//void hanoi(stack<int>& hn, int from, int to) {
//	
//}
//
//int main() {
//	int n;
//	stack<int> hn;
//	int x;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> x;
//		hn.push(x);
//	}
//	hanoi(hn, 1, 3);
//}

//#include<iostream>
//
//using namespace std;
//
//int n, cnt;
//
//void hanoi(int n, int from, int to, int cnt) {
//	int mid = 6 - from - to;
//
//	if (n == 1) {
//		cout << from << " " << to << '\n';
//		return;
//	}
//	else {
//		hanoi(n - 1, from, mid, cnt + 1);
//		hanoi(1, from, to, cnt + 1);
//		hanoi(n - 1, mid, to, cnt + 1);
//	}
//	cout << cnt << '\n';
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	
//	cin >> n;
//	int cnt = 0;
//
//	hanoi(n, 1, 3, 0);
//	//cout << cnt << '\n';
//
//}