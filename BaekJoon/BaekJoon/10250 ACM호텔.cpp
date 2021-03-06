#include<iostream>

using namespace std;

int main() {
	int T;
	int H, W, N;
	int yy = 0, xx = 0;
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		if (N % H == 0) {
			yy = H;
			xx = N / H;
		}
		else {
			yy = N % H;
			xx = N / H + 1;
		}

		if (xx < 10) {
			cout << yy << '0' << xx;
		}
		else {
			cout << yy << xx;
		}
		cout << '\n';

	}
}