#include<iostream>
#include<stack>
#include<string>

using namespace std;

string bracket(string ip) {
	stack<char> st;
	for (int i = 0; i < ip.size(); i++) {
		if (ip[i] == '(') {
			st.push(ip[i]);
		}
		else if (ip[i] == ')')
		{
			if (st.empty())
			{
				return "NO";
			}
			else st.pop();
		}
	}

	if (st.empty()) return "YES";
	else return "NO";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string ip;
		cin >> ip;
		
		cout << bracket(ip) << '\n';

		// while������ for������ ���� while������ �ٷ� �Ѿ�� ����� ���� �Լ��� ����
		
	}
}