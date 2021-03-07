#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	int y, x;
}Point;

Point moveP[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int board[21][21];
int visited[21][21];

int N; // 판의 크기
int baby, fish;

int bfs(Point p) {
	queue<Point> q;
	q.push(p);
	visited[p.y][p.x] = true;

	while (q.empty()) {
		Point cp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Point np;
			np.y = p.y + moveP[i].y;
			np.x = p.x + moveP[i].x;

			if (np.y > 0 && np.y <= N && np.x > 0 && np.x <= N) {
				if (){}
			}
		}
	}
}
int main() {

}