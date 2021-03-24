#include<iostream>
#include<stack>

using namespace std;

stack<int> s;
int n, dt;
string cmd;

int main() {
	cin >> n;
	while (n > 0) {
		cin >> cmd;
		n--;
		if (cmd == "push") {
			cin >> dt;
			s.push(dt);
		}
		else if (cmd == "pop") {
			if (s.empty())
				cout << "-1" << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (cmd == "size") {
			cout << s.size() << '\n';
		}
		else if (cmd == "empty") {
			if (s.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		else if (cmd == "top") {
			if (s.empty()) cout << "-1" << '\n';
			else cout << s.top() << '\n';
		}
	}
}