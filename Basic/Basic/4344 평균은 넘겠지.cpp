#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie();

	int t;

	cin >> t;
	while (t--) {
		float cnt = 0;
		int n;
		float sum = 0, avg = 0;
		int arr[1001] = { 0 };
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		avg = sum / (float)n;

		//cout << avg << '\n';

		for (int i = 0; i < n; i++) {
			if ((float)arr[i] > avg) cnt++;
		}

		//cout << cnt << '\n';

		cout << fixed;
		cout.precision(3);
		cout << (cnt / (float)n)*100 << "%" <<'\n';
	}
	
}