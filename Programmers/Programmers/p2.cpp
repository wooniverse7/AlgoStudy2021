// 모든 점에서 bfs를 돌려서 하나라도 거리가 2이하가 나오면 0

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
    // 우선 p의 좌표를 다 큐에 넣는다
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
        // 현재 큐에 있는 칸으로부터 한칸씩 전진
        for (int i = 0; i < curSize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nextY = y + moveDir[i].y;
                int nextX = x + moveDir[i].x;

                // 범위 내에 있고
                if (0 <= nextY && nextY < 5 && 0 <= nextX && nextX < 5) {
                    // 다른 P에 도달할 경우 반환
                    if (map[nextY][nextX] == 1 && map[nextY][nextX] != 1)
                        return dst;
                    //아직 방문하지 않은 빈칸이면 방문 표시 후 큐에 넣음
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
    // 5개의 2차원 배열을 하나의 char 2차원 배열로 분해
    // map을 숫자로 구현(P = 1, O = 0, X = -1),
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // p개수 구하기
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

    // p개수만큼 bfs돌림
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
    ,{"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"}ㅌ
    ,{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}
    ,{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };

    cout << solution(places);
}

