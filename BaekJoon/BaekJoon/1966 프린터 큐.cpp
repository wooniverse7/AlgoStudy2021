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
			pq.push(dt); // 우선순위만 정렬
		}

		while (!q.empty()) {
			int data = q.front().first;
			int idx = q.front().second;
			q.pop();

			// 최고 우선순위와 front의 우선순위가 같다면 q.pop은 유지, pq.pop 실행해서 다음 우선순위 탐색
			if (pq.top() == data) {
				pq.pop();
				++cnt;
				// 진행 중에 찾고자 하는 idx가 나오면 그 때의 삭제 순서를 출력
				if (idx == m) {
					cout << cnt << '\n';
					break; // 종료
				}
			}
			else {// pq와 우선순위가 다르면 뒤에 더 큰 우선순위가 있다는 뜻이므로 다시 후입 진행
				q.push({ data,idx });
			}
		}

	}
	
}

