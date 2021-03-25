#include<iostream>
#include<queue>

using namespace std;

int main() {
	int t;
	int n, m;
	cin >> t;
	while (t--) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int cnt = 0;

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int dt;
			cin >> dt;
			q.push({dt, i });
			pq.push(dt); // �켱������ ����
		}

		while (!q.empty()) {
			int data = q.front().first;
			int idx = q.front().second;
			q.pop();

			// �ְ� �켱������ front�� �켱������ ���ٸ� q.pop�� ����, pq.pop �����ؼ� ���� �켱���� Ž��
			if (pq.top() == data) {
				pq.pop();
				++cnt;
				// ���� �߿� ã���� �ϴ� idx�� ������ �� ���� ���� ������ ���
				if (idx == m) {
					cout << cnt << '\n';
					break; // ����
				}
			}
			else {// pq�� �켱������ �ٸ��� �ڿ� �� ū �켱������ �ִٴ� ���̹Ƿ� �ٽ� ���� ����
				q.push({ data,idx });
			}
		}

	}
	
}

