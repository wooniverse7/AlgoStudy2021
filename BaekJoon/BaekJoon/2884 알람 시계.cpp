#include<iostream>
using namespace std;

int main() {
	int h, m;
	
	cin >> h >> m;

	if (m < 45) {
		h--;
		m = 60 + (m - 45);
	}
	else {
		m -= 45;
	}

	if (h < 0) h = 23;

	cout << h << " " << m;
}