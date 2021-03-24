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

		// while문안의 for문에서 다음 while문으로 바로 넘어가는 방법을 몰라 함수로 만듬
		
	}
}