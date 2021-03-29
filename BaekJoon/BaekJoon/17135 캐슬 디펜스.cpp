#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 16
int N, M, D;
int board[MAX][MAX];

int main() {
	cin >> N >> M >> D;
	int num;

	vector<pair<int, int>> enemy;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];

			if (board[y][x] == 1) {
				enemy.push_back({ y,x }); // 적들의 좌표를 넣어줌
			}
		}
	}

	// 궁수 위치 조합 : 00...0111 ~ 1110...00
	vector<int> archer;
	for (int i = 0; i < M - 3; i++) {
		archer.push_back(0);
	}
	for (int i = 0; i < 3; i++) {
		archer.push_back(1);
	}

	int result = 0; // 최종값
	do {
		int cnt = 0; // 각 조합별 값

		vector<pair<int, int>> temp = enemy; // 적 좌표 copy

		vector<int> v; // 현재 궁수 위치
		for (int i = 0; i < archer.size(); i++) {
			if (archer[i] == 1) {
				v.push_back(i);
			}
		}
		
		// 적들이 모두 사라질 떄까지
		while (!temp.empty()) {
			int y = N; // y좌표
			vector<int> target; //궁수가 죽일 수 있는 적

			// 현재 궁수 위치 내에서 모든 궁수에 대해
			for (int i = 0; i < v.size(); i++) {
				int x = v[i]; // 현재 궁수 위치 순서, x좌표
				int idx = 0; // 갱신할 y좌표
				int enemyX = temp[0].second; // 첫번째 적의 x좌표
				int dist = abs(y - temp[0].first) + abs(x - temp[0].second); // 첫 번째 적과의 거리
				// 모든 적의 처리 순서
				for (int j = 1; j < temp.size(); j++) {
					int tempDist = abs(y - temp[j].first) + abs(x - temp[j].second); // 두번째 적부터 궁수와의 거리

					// 가까운 적
					if (dist > tempDist) {
						enemyX = temp[j].second; // 적의 x좌표
						dist = tempDist; // update
						idx = j; // 그 떄의 y좌표
					}
					// 더 왼쪽에 있는 적
					else if (dist == tempDist && enemyX > temp[j].second) {
						enemyX = temp[j].second; // 그떄의 x좌표
						idx = j;
					}
				}

				// only can kill enemy is in range of archer
				if (dist <= D) {
					target.push_back(idx); // 그 때의 적의 y좌표를 넣음
				}
			}

			// 중복된 적 삭제. unique로 중복된 값의 처음 idx가 반환되 그곳에서부터 끝까지 삭제
			target.erase(unique(target.begin(), target.end()), target.end());
			sort(target.begin(), target.end());
			int shoot = 0;
			// 적 처치
			for (int i = 0; i < target.size(); i++) {
				temp.erase(temp.begin() + (target[i] - shoot++));
				cnt++;
			}

			if (temp.empty()) {
				break;
			}

			// next round
			vector<pair<int, int>> copyTemp;
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i].first < N - 1) {
					copyTemp.push_back({ temp[i].first + 1, temp[i].second });
				}
			}
			temp = copyTemp;
		}
		result = max(cnt, result);
		
	} while (next_permutation(archer.begin(), archer.end()));

	cout << result;

}