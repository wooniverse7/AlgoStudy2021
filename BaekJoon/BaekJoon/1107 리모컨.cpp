#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<bool> mal(10, false); // ���峭 ��ư

bool check(int num) {
	string s = to_string(num);
	for (int i = 0; i < s.length(); i++) {
		if (mal[s[i] - 48]) // ���峭 ��ư�̸� 0�� �� �״ϱ�
		{
			return false; // ��쿡�� ����
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
		mal[tmp] = true; // ���峭 ��ư �Է�
	}

	string str = to_string(n);
	int res = abs(n - 100); // ���ڹ�ư���� +/-�� ������ �� 
	for (int i = 0; i < 1000000; i++) { // 10�� �ڸ� ��� �˻� �ʿ�
		if (check(i)) 
		{
			int minimum = to_string(i).length() + abs(n - i); // ���� i ��ư �� + (+/- Ŭ�� ��)
			res = min(minimum, res);
		}
	}

	cout << res << endl;
}

// O(n) time, �� ���� 100��