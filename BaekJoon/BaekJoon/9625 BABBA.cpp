#include<iostream>

using namespace std;

int k;
int cntA[51];
int cntB[51];

void dp(int k) {

	cntA[0] = 1;
	cntB[0] = 0;
	cntA[1] = 0;
	cntB[1] = 1;

	for (int i = 2; i <= k; i++) {
		cntA[i] = cntB[i - 1];
		cntB[i] = cntA[i - 1] + cntB[i - 1];
	}

}

int main() {
	cin >> k;
	dp(k);
	cout << cntA[k] << " " << cntB[k];
}