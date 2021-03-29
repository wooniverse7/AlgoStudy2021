#include<iostream>
#include<queue>
#include<string>
using namespace std;

#define MAX 1001
int N, M;
int board[MAX][MAX];
int visited[MAX][MAX][2]; // y, x, ���մ� Ƚ��(0 = ��ȸX, 1) + cnt���� ����

typedef struct {
	int y, x;
}Point;

Point nxtPnt[4] = { {1,0},{-1, 0},{0,1}, {0,-1} };


int bfs(Point s) {
	queue<pair<Point, int>> q; // ������, ���ձ� ��/��
	visited[1][1][1] = 1;
	q.push({ s, 1 }); // ������, �� ���� �� �ִ� Ƚ��

	while (!q.empty()) {
		Point cp = q.front().first;
		int block = q.front().second; // �� ���� �� �ִ� Ƚ��
		q.pop();

		if (cp.y == N && cp.x == M) {
			return visited[cp.y][cp.x][block]; // �������� ������ ��� �����Ͽ� ���
		}

		for (int i = 0; i < 4; i++) {
			Point np;
			np.y = cp.y + nxtPnt[i].y;
			np.x = cp.x + nxtPnt[i].x;

			//in boundary
			if (np.y >= 1 && np.y <= N && np.x >= 1 && np.x <= M) {
				// ���� �ְ� ���� �� ���� ��
				if (board[np.y][np.x] == 1 && block)
				{
					
					visited[np.y][np.x][block-1] = visited[cp.y][cp.x][block] + 1; // [block-1]�� �� cnt�� �������
					q.push({ np, block - 1 });
				}
				// ���� ���� �湮���� ���� ��
				if (board[np.y][np.x] == 0 && visited[np.y][np.x][block] == 0) 
				{
					visited[np.y][np.x][block] = visited[cp.y][cp.x][block] + 1;
					q.push({ np,block });
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	
	for (int y = 1; y <= N; y++) {
		string a;
		cin >> a;
		for (int x = 1; x <= M; x++) {
			board[y][x] = a[x-1] - '0';
		}
	}
	//for (int y = 1; y <= N; y++) {
	//	for (int x = 1; x <= M; x++) {
	//		cout << board[y][x];
	//	}
	//	cout << '\n';
	//}
	
	Point start = { 1,1 };
	cout << bfs(start);
	
}