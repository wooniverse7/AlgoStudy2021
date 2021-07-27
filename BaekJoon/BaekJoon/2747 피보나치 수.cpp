#include<iostream>

using namespace std;

int table[50];
bool calculated[50];

// top-down
int fibo(int n) {
	if (n < 2) return n;
	//return fibo(n - 1) + fibo(n - 2);

	if (calculated[n]) return table[n]; //ÇÙ½É

	table[n] = fibo(n - 1) + fibo(n - 2);
	calculated[n] = true;

	return table[n];
}

int main() {
	int n = 0;
	cin >> n;
	cout << fibo(n);
}

// bottom-up
int main() {

}