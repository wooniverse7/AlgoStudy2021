#include<iostream>
using namespace std;

int main() {
	int a, b;
	int b1, b2, b3;
	cin >> a >> b;
	b1 = b / 100; b2 = (b - b1*100) / 10; b3 = (b - b1*100 - b2*10);
	cout << a * b3 << '\n';
	cout << a * b2 << '\n';
	cout << a * b1 << '\n';
	cout << a * b << '\n';
}