#include<iostream>

using namespace std;

int t, N;
long long table[105] = { 0, 1, 1, 1, 2, 2, };
bool calculated[105];

//long long dp(int n) {
//	if (n <= 3) return 1;
//	else if (n <= 5) return 2;
//	
//	if (calculated[n]) return table[n];
//	
//	table[n] = dp(n - 1) + dp(n - 5);
//	calculated[n] = true;
//
//	return table[n];
//}

int main() {
	cin >> t;

	for (int i = 5; i <= 100; i++) {
		table[i] = table[i - 2] + table[i - 3];
	}
	while (t--) {
		cin >> N;
		//cout << table(N) << '\n'; // bottome-up
		cout << table[N] << '\n'; // top-down
	}
}