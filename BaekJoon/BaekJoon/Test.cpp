#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

#define MAX 101
int board[MAX][MAX];
bool visited[MAX][MAX];
int M, N, K;
int cnt;

typedef struct {
	int y, x;
}Point;

Point movePoint[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int dfs(Point d) {
	stack<Point> s;
	s.push(d);
	visited[d.y][d.x] = true;

	while (!s.empty()) {
		Point cp = s.top();
		s.pop();

		for (int i = 0; i < 4; i++) {
			Point np;
			np.y = cp.y + movePoint[i].y;
			np.x = cp.x + movePoint[i].x;

			if (np.y >= 0 && np.y < M && np.x >= 0 && np.x < N
				&& board[np.y][np.x] == 0 && !visited[np.y][np.x]) {
				
				s.push(cp);
				s.push(np);

				cnt++;
				visited[np.y][np.x] = true;

				break;
			}
		}
	}
	return cnt;
}

int main() {

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				board[y][x] = 1;
	}

	vector<int> rst;

	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (board[y][x] == 0 && !visited[y][x]) {
				Point ent;
				ent.y = y;
				ent.x = x;
				cnt = 1;

				dfs(ent);
				rst.push_back(cnt);
			}
		}
	}

	cout << rst.size() << '\n';
	sort(rst.begin(), rst.end());

	for (auto i : rst)
		cout << i << " ";


}
