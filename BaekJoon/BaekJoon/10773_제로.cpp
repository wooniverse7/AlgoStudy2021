// ����
#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack<int> s;

	int t, n;
	int sum = 0;

	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 0) {
			s.pop();
		}
		// else�� 0����
		else
			s.push(n);
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << endl;
}