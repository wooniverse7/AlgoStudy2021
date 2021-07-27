// 배열, 재귀로만 풀기
#include<iostream>

using namespace std;

int arr[100002];
int k, dt;

void stack(int arr[], int n) {

	if (arr[n - 1] == 0) {
		stack(arr, n - 1);
	}
	else
		arr[n-1] = 0;
}

int main() {

	cin >> k;

	for (int i = 1; i <= k; i++) {
		cin >> dt;
		if (dt == 0) {
			stack(arr, i);
			
		}
		else {
			arr[i] = dt;
		}
	}

	int sum = 0;

	for (const auto& it : arr) {
		sum += it;
	}
	cout << sum;

}

// O(3n) time에 가능할 듯