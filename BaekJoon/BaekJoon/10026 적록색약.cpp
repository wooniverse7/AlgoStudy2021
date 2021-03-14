#include<iostream>
#include<cstring>

using namespace std;

#define MAX 101

typedef struct {
	int y, x;
}dir;

dir moveDir[4] = { {1,0},{-1,0},{0,1},{0,-1} };

char board[MAX][MAX];
bool visited[MAX][MAX];
int n, cnt, cnt2;
char color[4] = { 'R','G', 'B' };
char color2[3] = { 'R', 'B' };

void dfs1(dir cp, char clr) {
	visited[cp.y][cp.x] = true;

	dir np;
	for (int i = 0; i < 4; i++) {
		np.y = cp.y + moveDir[i].y;
		np.x = cp.x + moveDir[i].x;

		if (np.y >= 0 && np.y < n && np.x >= 0 && np.x < n) { // 범위 주의
			if (board[np.y][np.x] == clr && !visited[np.y][np.x]) {
				visited[np.y][np.x] = true;

				dfs1(np, clr);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> board[y][x];
		}
	}

	//dfs1
	for (int c = 0; c < 3; c++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (board[y][x] == color[c] && !visited[y][x]) {
					dir start = { y,x }; // 0,0 고정 X

					dfs1(start, color[c]);
					cnt++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		memset(visited[i], false, sizeof(visited[i]));
	}

	// G -> R
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (board[y][x] == 'G')
				board[y][x] = 'R';
		}
	}

	//dfs2
	for (int c = 0; c < 2; c++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (board[y][x] == color2[c] && !visited[y][x]) {
					dir start = { y,x };

					dfs1(start, color2[c]);
					cnt2++;
				}
			}
		}
	}

	cout << cnt << " " << cnt2;
}