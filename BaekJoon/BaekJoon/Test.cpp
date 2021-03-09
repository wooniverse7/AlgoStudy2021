#include<iostream>
#include<string>
#include<queue>

using namespace std;

#define MAX 101

typedef struct {
	int y, x;
}Dir;

Dir movDir[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX];
int cnt[MAX][MAX];

void bfs(Dir d) {
	queue<Dir> q;
	cnt[d.y][d.x] = 1;
	visited[d.y][d.x] = true;

	q.push(d);
	while (!q.empty()) {
		Dir cd = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Dir nd;
			nd.y = cd.y + movDir[i].y;
			nd.x = cd.x + movDir[i].x;

			if (nd.y >= 0 && nd.y < N && nd.x >= 0 && nd.x < M
				&& board[nd.y][nd.x] == 1 && !visited[nd.y][nd.x]) {
				
				//for (int i = 0; i < N; i++) {
				//	for (int j = 0; j < M; j++) {
				//		cout << visited[i][j];
				//	}
				//	cout << '\n';
				//}
				
				cnt[nd.y][nd.x] = cnt[cd.y][cd.x] + 1;
				visited[nd.y][nd.x] = true;

				q.push(nd);
			}
		}
	}


}

int main() {
	cin >> N >> M;
	string narr;
	for (int i = 0; i < N; i++) {
		cin >> narr;
		for (int j = 0; j < M; j++) {
			board[i][j] = narr[j] - '0';
		}
	}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << board[i][j];
	//	}
	//	cout << '\n';
	//}

	Dir start = { 0,0 };
	//start.y = 0;
	//start.x = 0;
	bfs(start);7

	cout << cnt[N - 1][M - 1];

}