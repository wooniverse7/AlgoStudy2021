#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<bool> mal(10, false); // 고장난 버튼

bool check(int num) {
	string s = to_string(num);
	for (int i = 0; i < s.length(); i++) {
		if (mal[s[i] - 48]) // 고장난 버튼이면 0이 될 테니까
		{
			return false; // 경우에서 제외
		}
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		mal[tmp] = true; // 고장난 버튼 입력
	}

	string str = to_string(n);
	int res = abs(n - 100); // 숫자버튼말고 +/-만 눌렀을 때 
	for (int i = 0; i < 1000000; i++) { // 10만 자리 모두 검사 필요
		if (check(i)) 
		{
			int minimum = to_string(i).length() + abs(n - i); // 숫자 i 버튼 수 + (+/- 클릭 수)
			res = min(minimum, res);
		}
	}

	cout << res << endl;
}

// O(n) time, 비교 연산 100만