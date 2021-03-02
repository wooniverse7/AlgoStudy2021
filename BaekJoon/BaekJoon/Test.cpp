#include<iostream>
#include<string>

using namespace std;

#define MAX 101
int board[MAX][MAX];
bool visited[MAX][MAX];
int cnt[MAX][MAX]; // �ִ� ���̸� �ش� ��ǥ�� �������� �� �� ��ǥ�� ���� ����ؾ��Ѵ�.
// �׳� cnt�ϸ� ��ü ĭ�� ���� ������(���� ���ϱ�)
int dst;
int Min = 10001;

int N, M;

typedef struct {
	int y, x;
}Point;

Point movPnt[4] = { {1,0},{-1,0},{0,1},{0,-1} };

void dfs(Point p, int depth) {
	
	if (p.y < 0 || p.y >= N || p.x < 0 || p.x >= M) return; // ** �ڷ� ���ư� �ٸ� ��η� �� �� �ְ� return�ؼ� �湮üũ ��ȿȭ���ֱ�

	// ** �������� ���� �Ѱ� �� ���� ���� ���� ���� **
	if (p.y == N - 1 && p.x == M - 1) {
		if (depth < Min)
			Min = depth;
		return;
	}
	
	//visited[p.y][p.x] = true;

	for (int i = 0; i < 4; i++) {
		Point np;
		np.y = p.y + movPnt[i].y;
		np.x = p.x + movPnt[i].x;

	    //if (p.y >= 0 && p.y < N && p.x >= 0 && p.x < M) return;
		if(board[np.y][np.x] == 1 && !visited[np.y][np.x])
		{
			
			visited[np.y][np.x] = true;
			
			// ��� Ʈ��ŷ
			//cout << "cp(y,x) : " << p.y << "," << p.x ;
			//cout << " -> np(y,x)/Min : " << np.y << "," << np.x << "/" << Min << '\n';
			
			dfs(np, depth + 1);
			visited[np.y][np.x] = false; // ** �ٽ� ���ư� �� �ֵ��� �湮ó���� ��ȿȭ �ؾ��Ѵ�.
				// ������ ������ ��� ����� ���� ������ ���

		}
	}
}

int main() {
	cin >> N >> M; // y, x
	string narr;

	//�ٿ��� �Է�
	for (int y = 0; y < N; y++) {
		cin >> narr;
		for (int x = 0; x < M; x++) {
			board[y][x] = narr[x] - '0';
		}
	}

	Point start = { 0, 0 };
	dfs(start, 1);

	cout << Min;

}