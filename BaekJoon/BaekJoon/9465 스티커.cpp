#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int d[2][100002]; // memoization
bool v[2][100002]; // 배열 입력

void DP(int n) {
	if (n == 0) {
		d[0][0] = v[0][0];
		d[1][0] = v[1][0];
	}
	else {

	}

}

int main() {
	
	int t;
	int n;
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			v[i][j] = num;

			DP(n);
		}
	}

	
}