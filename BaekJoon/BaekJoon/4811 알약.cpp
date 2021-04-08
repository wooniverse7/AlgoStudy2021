#include<iostream>
using namespace std;

long long mz[31][31];

long long DP(int w, int h) {

	if (mz[w][h] != 0) return mz[w][h]; // 이미 있는값은 리턴
	if (w < 0 || h < 0) return 0; // 둘 중에 한 종류가 없을 때
	if (w == 0) return 1;// w를 다 집었을때
	
	return mz[w][h] = (DP(w-1, h+1) + DP(w, h - 1)); // w 1개 -> h +1개 / h -1개
	
}

int main() {
	int N;
	while (1) {
		cin >> N;
		if (N == 0) break;
		cout << DP(N, 0) << '\n'; // w개수
	};

}

// bottom-up 방식
//#include <iostream>
//using namespace std;
//typedef long long ll;
//
//ll dp[33][33];
//
//int main() {
//	for (int h = 0; h <= 30; h++) {
//		for (int w = 0; w <= 30; w++) {
//			if (h > w) continue; // 조건: h는 w개수보다 많을 수 없다.
//			if (h == 0) dp[w][h] = 1; // w로만 정렬
//			else dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
//		}
//	}
//	int n;
//	while (1) {
//		cin >> n;
//		if (n == 0)break;
//		cout << dp[n][n] << "\n";
//	}
//}
