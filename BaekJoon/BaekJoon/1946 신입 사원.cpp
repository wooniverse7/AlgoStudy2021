#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

pair<int, int> i1[100001];


int main() {
	int t, n, fst, snd;

	cin >> t;

	while (t--) {
		int cnt = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> fst >> snd;
			//i1[i].first = fst;
			//i1[i].second = snd;
			i1[i] = { fst, snd };
		}

		sort(i1, i1 + n);

		int bound = i1[0].second; // 똑같은 반복을 피하기 위해 합격한 새로운 비교자를 입력
		// 그 다음부터는 두 번째 합격자와만 비교

		for (int i = 1; i < n; i++) {
			if (i1[i].second < bound) {
				cnt++;
				bound = i1[i].second;
			}
		}
		cout << cnt+1 << '\n';
		memset(i1, 0, n);
	}
}