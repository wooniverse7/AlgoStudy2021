#include<iostream>
#include<vector>

using namespace std;

int a[103];

int getGCD(int a, int b) {
	return b ? getGCD(b, a % b) : a;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				
				sum += getGCD(a[i], a[j]);
				
			}
		}

		cout << sum << '\n';
	}
}