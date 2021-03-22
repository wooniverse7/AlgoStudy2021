#include<iostream>
#include<string>

using namespace std;

int a, b, c, sum;
string num = "0123456789";


int main() {
	cin >> a >> b >> c;
	sum = a * b * c;
	string s = to_string(sum);

	for (int i = 0; i < 10; i++) {
		int cnt = 0;
		for (int j = 0; j < s.size(); j++) {
			if (num[i] == s[j]) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}

}