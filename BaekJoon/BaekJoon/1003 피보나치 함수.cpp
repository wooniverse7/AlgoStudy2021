#include<iostream>

using namespace std;

int t, N;
int d[42], e[42]; // d[n]�� f(1)�� ����, e[N]�� N�� �Է����� �� f(0)�� ȣ���� ����.

int main() {
	cin >> t;
	d[0] = 1;
	d[1] = 0;
	e[0] = 0;
	e[1] = 1;

	for (int i = 2; i < 41; ++i) {
		d[i] = d[i - 1] + d[i - 2];
		e[i] = e[i - 1] + e[i - 2];
	}
	while (t--) {
		cin >> N;
		
		cout << d[N] << " " << e[N] << '\n';
	}
}