#include<iostream>
using namespace std;

//float arr[1001];
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	int n;
//	int max = -1;
//	float avg = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//		if (arr[i] > max) {
//			max = arr[i];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		arr[i] = arr[i] / max * 100;
//		avg += arr[i] / (float)n;
//	}
//
//	cout << avg;
//}

int main() {
	float n;
	float num;
	float max = -1;
	float sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > max) max = num;
		sum += num;
	}
	cout << sum / n / max * 100;
}