#include<iostream>
using namespace std;

int arr[10001];
int main() {
	int n, x;
	//int num;
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // i index에 입력값 삽입. i가 입력되는게 아님. 
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] < x)
			cout << arr[i] << " ";
	}
	
}