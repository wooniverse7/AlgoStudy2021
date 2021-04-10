#include<iostream>

using namespace std;

int arr[12];
int cnt;
int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n-1; i >= 0; i--) { // 범위 시작 = n-1
		if (k / arr[i] > 0) {
			cnt += k / arr[i];
			k %= arr[i];
		}
	}

	cout << cnt;
}