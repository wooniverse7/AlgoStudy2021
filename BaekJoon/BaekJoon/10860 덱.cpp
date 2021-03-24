#include<iostream>
#include<deque>
#include<string>

using namespace std;
deque<int> dq;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, dt;
	cin >> n;
	string cmd;
	while (n > 0) {
		cin >> cmd;
		n--;
		if (cmd == "push_front") {
			cin >> dt;
			dq.push_front(dt);
		}
		else if (cmd == "push_back") {
			cin >> dt;
			dq.push_back(dt);
		}
		else if (cmd == "pop_front") {
			if (dq.empty()) cout << "-1" << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (dq.empty()) cout << "-1" << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty") {
			if (dq.empty()) cout << "1" << '\n';
			else {
				cout << "0" << '\n';
			}
		}
		else if (cmd == "front") {
			if (dq.empty()) cout << "-1" << '\n';
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (dq.empty()) cout << "-1" << '\n';
			else {
				cout << dq.back() << '\n';
			}
		}
	}
}
