#include<iostream>
#include<string>
using namespace std;

int main() {
	int t, r;
	cin >> t;
	while (t--) {
		string S;
		string P;
		cin >> r;
		cin >> S;

		for (int i = 0; i < S.size(); i++) {
			for (int j = 0; j < r; j++) {
				P += S[i]; // =이 아니라 +=를 해줘 하나씩 더해줘야 한다.
			}
		}
		for (auto P1 : P)
			cout << P1;
		cout << '\n';
	}

}