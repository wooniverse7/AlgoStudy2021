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
				enemy.push_back({ y,x }); // ������ ��ǥ�� �־���
			}
		}
	}

	// �ü� ��ġ ���� : 00...0111 ~ 1110...00
	vector<int> archer;
	for (int i = 0; i < M - 3; i++) {
		archer.push_back(0);
	}
	for (int i = 0; i < 3; i++) {
		archer.push_back(1);
	}

	int result = 0; // ������
	do {
		int cnt = 0; // �� ���պ� ��

		vector<pair<int, int>> temp = enemy; // �� ��ǥ copy

		vector<int> v; // ���� �ü� ��ġ
		for (int i = 0; i < archer.size(); i++) {
			if (archer[i] == 1) {
				v.push_back(i);
			}
		}
		
		// ������ ��� ����� ������
		while (!temp.empty()) {
			int y = N; // y��ǥ
			vector<int> target; //�ü��� ���� �� �ִ� ��

			// ���� �ü� ��ġ ������ ��� �ü��� ����
			for (int i = 0; i < v.size(); i++) {
				int x = v[i]; // ���� �ü� ��ġ ����, x��ǥ
				int idx = 0; // ������ y��ǥ
				int enemyX = temp[0].second; // ù��° ���� x��ǥ
				int dist = abs(y - temp[0].first) + abs(x - temp[0].second); // ù ��° ������ �Ÿ�
				// ��� ���� ó�� ����
				for (int j = 1; j < temp.size(); j++) {
					int tempDist = abs(y - temp[j].first) + abs(x - temp[j].second); // �ι�° ������ �ü����� �Ÿ�

					// ����� ��
					if (dist > tempDist) {
						enemyX = temp[j].second; // ���� x��ǥ
						dist = tempDist; // update
						idx = j; // �� ���� y��ǥ
					}
					// �� ���ʿ� �ִ� ��
					else if (dist == tempDist && enemyX > temp[j].second) {
						enemyX = temp[j].second; // �׋��� x��ǥ
						idx = j;
					}
				}

				// only can kill enemy is in range of archer
				if (dist <= D) {
					target.push_back(idx); // �� ���� ���� y��ǥ�� ����
				}
			}

			// �ߺ��� �� ����. unique�� �ߺ��� ���� ó�� idx�� ��ȯ�� �װ��������� ������ ����
			target.erase(unique(target.begin(), target.end()), target.end());
			sort(target.begin(), target.end());
			int shoot = 0;
			// �� óġ
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