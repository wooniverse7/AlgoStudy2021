// ��� ������ bfs�� ������ �ϳ��� �Ÿ��� 2���ϰ� ������ 0

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<string>> places;
int map[5][5];
bool visited[5][5];

typedef struct {
    int y, x;
}Dir;

Dir moveDir[4] = { {1,0}, {-1,0},{0,1},{0,-1} };

int bfs(int cnt) {
    queue<pair<char, char>> q;
    // �켱 p�� ��ǥ�� �� ť�� �ִ´�
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (map[i][j] == '1') {
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }

    int dst = 0;
    while (!q.empty()) {
        int curSize = q.size();
        // ���� ť�� �ִ� ĭ���κ��� ��ĭ�� ����
        for (int i = 0; i < curSize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nextY = y + moveDir[i].y;
                int nextX = x + moveDir[i].x;

                // ���� ���� �ְ�
                if (0 <= nextY && nextY < 5 && 0 <= nextX && nextX < 5) {
                    // �ٸ� P�� ������ ��� ��ȯ
                    if (map[nextY][nextX] == 1 && map[nextY][nextX] != 1)
                        return dst;
                    //���� �湮���� ���� ��ĭ�̸� �湮 ǥ�� �� ť�� ����
                    else if (map[nextY][nextX] == 0 && !visited[nextY][nextX])
                    {
                        visited[nextY][nextX] = true;
                        q.push(make_pair(nextY, nextX));
                    }
                }
            }
        }
        dst++;
    }
}

int makeMap(vector<string> place) {
    int cnt = 0;
    // 5���� 2���� �迭�� �ϳ��� char 2���� �迭�� ����
    // map�� ���ڷ� ����(P = 1, O = 0, X = -1),
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // p���� ���ϱ�
            if (place[i][j] == 'P') {
                map[i][j] = 1;
                cnt++;
            }
            else if (place[i][j] == 'O') {
                map[i][j] = 0;
            }
            else if (place[i][j] == 'X') {
                map[i][j] = -1;
            }
        }
    }

    // p������ŭ bfs����
    int result = -1;
    for (int i = 1; i < cnt; i++) {
        result = min(result, bfs(i));
    }

    if (result < 2)
        return 1;
    else
        return 0;

}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < 5; i++) {
        int finalrst = makeMap(places[i]);
        answer.push_back(finalrst);
    }

    return answer;
}

int main() {
    places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}
    ,{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}
    ,{"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"}��
    ,{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}
    ,{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };

    cout << solution(places);
}

