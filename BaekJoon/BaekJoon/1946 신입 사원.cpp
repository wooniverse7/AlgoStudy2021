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

		int bound = i1[0].second; // �Ȱ��� �ݺ��� ���ϱ� ���� �հ��� ���ο� ���ڸ� �Է�
		// �� �������ʹ� �� ��° �հ��ڿ͸� ��

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