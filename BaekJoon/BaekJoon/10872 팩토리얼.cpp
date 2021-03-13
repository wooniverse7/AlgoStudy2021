#include<iostream>

using namespace std;
int num;
int fact(int f) {
	if (f <= 1)
		return 1;
	if (f == 2)
		return 2;

	num = f * fact(f - 1);

	return num;
}

int main() {
	int n;
	cin >> n;

	cout << fact(n);

}