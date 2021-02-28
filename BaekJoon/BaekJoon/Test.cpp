// DFS, Stack
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

#define MAX 101

int map[MAX][MAX];
bool visited[MAX][MAX];
int cnt;
int M, N, K;

typedef struct {
	int y, x;
}Point;

Point movePoint[4] = { {1,0}, {-1,0}, {0, 1}, {0, -1} };



int dfs(Point t) {
	stack<Point> s;
	s.push(t);
	visited[t.y][t.x] = true;
	while (!s.empty()) { // 들어간 점에서 빈 공간을 다 순회하면 스택이 빔
		Point cp = s.top(); // current point
		s.pop(); //
		for (int i = 0; i < 4; i++) {
			Point np; // next point
			np.y = cp.y + movePoint[i].y;
			np.x = cp.x + movePoint[i].x;
			// 탐색하지 않은 빈 공간을 찾을 때까지 탐색
			if (np.y >= 0 && np.y < M && np.x >= 0 && np.x < N
				&& map[np.y][np.x] == 0 && !visited[np.y][np.x]) {
				s.push(cp); 
				s.push(np);
				visited[np.y][np.x] = true;
				cnt++;
				break;
				// 찾으면 크기를 1늘리고 다음 공간을 push한다
			}
		}
	}

	return cnt;
}

int main() {
	vector<int> rst;

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				map[y][x] = 1;
	}

	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 0 && !visited[y][x])
			{
				cnt = 1;
				Point tmp;
				tmp.y = y;
				tmp.x = x;
				dfs(tmp);
				rst.push_back(cnt);
				//rst.push_back(dfs(tmp));
			}
		}
	}

	cout << rst.size() << '\n';
	sort(rst.begin(), rst.end());
	for (auto i : rst)
		cout << i << " ";
	cout << '\n';

}