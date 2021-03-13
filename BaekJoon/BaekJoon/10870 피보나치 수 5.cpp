#include<iostream>

using namespace std;

int rst;
int fibo(int n) {
	if (n <= 1)
		return n;

	rst = fibo(n - 1) + fibo(n - 2);
	return rst;
}

int main() {
	int n;
	cin >> n;
	cout << fibo(n);
}