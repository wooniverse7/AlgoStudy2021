#include<iostream>
#include<queue>

using namespace std;

queue<int> q,q2;
int arr[5001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int i = 1; i <= m; i++) {
			if (i == m) {
				q2.push(q.front()); // m번째 수는 q2에 삽입하고 q는 only pop
				q.pop();
			}
			else {// m번째가 아닌것은 다시 뒤로 삽입
				q.push(q.front());
				q.pop();
			}
		}
	}

	for (int i = 0; i < n; i++) {
		arr[i] = q2.front();
		q2.pop();
	}

	cout << "<";
	for (int i = 0; i < n-1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[n - 1] << ">";

}