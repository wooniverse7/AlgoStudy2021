#include<iostream>
#include<queue>

using namespace std;

int n, dt;
queue <int> q;
string cmd;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n > 0) {
		cin >> cmd;
		n--;
		if (cmd == "push") {
			cin >> dt;
			q.push(dt);
		}
		else if (cmd == "pop") {
			if (q.empty()) cout << "-1" << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (cmd == "size") {
			cout << q.size() << '\n';
		}
		else if (cmd == "empty") {
			if (q.empty()) cout << "1" << '\n';
			else {
				cout << "0" << '\n';
			}
		}
		else if (cmd == "front") {
			if (q.empty()) cout << "-1" << '\n';
			else {
				cout << q.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (q.empty()) cout << "-1" << '\n';
			else {
				cout << q.back() << '\n';
			}
		}
	}
}