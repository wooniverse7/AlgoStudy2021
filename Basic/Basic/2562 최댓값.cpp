#include<iostream>
using namespace std;

int arr1[10];
int arr2[10];

int main() {
	int max = 0;

	for (int i = 0; i < 9; i++) {
		cin >> arr1[i];
		arr2[i] = arr1[i];
		if (arr1[i] > max) {
			max = arr1[i];
		}
	}

	int cnt = 0;
	while (max != arr2[cnt]) {
		cnt++;
	}
	cnt++; // idx가 7번째는 8번 째 수이다.

	cout << max << " " << cnt;
}