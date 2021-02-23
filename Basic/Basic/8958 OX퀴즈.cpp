#include<iostream>
#include<string>
using namespace std;

//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	string ox;
//	int t;
//	cin >> t;
//	while (t--) {
//		int sum = 0;
//		cin >> ox;
//		int lgth = ox.size();
//
//		for (int i = 0; i <= lgth; i++) {
//			int scr = 0;
//			if (ox[i] == 'O') {
//				scr = 1;
//				for (int j = 1; j <= i; j++)
//				{
//					if (i == 0) continue;
//					if (ox[i - j] == 'O')
//						scr++;
//					if (ox[i - j] == 'X')
//						break;
//				}
//				sum += scr;
//			}
//		}
//		cout << sum << '\n';
//	}
//	
//}

int main() {
	int t;
	string ox;

	cin >> t;
	while (t--) {
		int sum = 0; int scr = 0;
		cin >> ox;
		for (int i = 0; ox[i]; i++) {
			ox[i] == 'O' ? sum += ++scr : scr = 0; // 참이면 scr을 먼저 더해야 점수가 생김.
		}
		cout << sum << '\n';
	}
}