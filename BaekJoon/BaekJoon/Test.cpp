#include<iostream>

using namespace std;

int n;

void hanoi(int n, int from, int to) {
	int mid = 6 - from - to;

	if (n == 1) {
		cout << from << " " << to << '\n';
		return;
	}
	else {
		hanoi(n - 1, from, mid);
		hanoi(1, from, to);
		hanoi(n - 1, mid, to);
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	hanoi(n, 1, 3);
}