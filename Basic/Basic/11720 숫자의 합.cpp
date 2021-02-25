#include<iostream>
#include<string>
using namespace std;

char arr[101];
int iarr[101];
int n;
int sum;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		iarr[i] = arr[i] - '0';
		sum += iarr[i];
	}
	cout << sum;
}