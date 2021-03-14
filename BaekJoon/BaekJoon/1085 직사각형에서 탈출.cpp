#include<iostream>

using namespace std;

int x, y, w, h;
int lf, rt, up, dw;

int main() {
	cin >> x >> y >> w >> h;
	int arr[4] = { x, w - x, h - y, y };

	int min = 1005;
	for (int i = 0; i < 4; i++) {
		if (arr[i] <= min) {
			min = arr[i];
		}
	}
	cout << min;
}