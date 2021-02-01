#include<iostream>
#include<queue>
using namespace std;

int arr[10002];

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q, q2;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i = 1; i <= k; i++) {
			if (i == k) {
				q2.push(q.front());
				q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}

	for(int i = 1; i <= n; i++){
		arr[i] = q2.front();
		q2.pop();
	}
	cout << "<" << arr[1];

	for (int i = 2; i <= n; i++) 
		cout << ", " << arr[i];
	cout << ">";
	
}