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
				P += S[i]; // =�� �ƴ϶� +=�� ���� �ϳ��� ������� �Ѵ�.
			}
		}
		for (auto P1 : P)
			cout << P1;
		cout << '\n';
	}

}