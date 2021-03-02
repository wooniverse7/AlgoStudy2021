// BFS(Queue)
#include<iostream>
#include<queue>
#include<string>


using namespace std;

#define MAX 101
int board[MAX][MAX];
bool visited[MAX][MAX];
int cnt[MAX][MAX]; // 최단 길이를 해당 좌표에 도착했을 때 그 좌표의 값을 출력해야한다.
// 그냥 cnt하면 전체 칸의 넓이 구해짐(영역 구하기)

int N, M;

typedef struct {
	int y, x;
}Point;

Point movPnt[4] = { {1,0},{-1,0},{0,1},{0,-1} };

void bfs(Point p) {
	queue<Point> q;
	cnt[p.y][p.x] = 1;
	visited[p.y][p.x] = true;

	q.push(p);
	while (!q.empty()) {
		Point cp = q.front();
		q.pop();
		
		//if (cp.y == N  - 1 && cp.x == M-1) return cnt;

		for (int i = 0; i < 4; i++) {
			Point np;
			np.y = cp.y + movPnt[i].y;
			np.x = cp.x + movPnt[i].x;

			if (np.y >= 0 && np.y < N && np.x >= 0 && np.x < M
				&& board[np.y][np.x] == 1 && !visited[np.y][np.x]) 
			{	
				visited[np.y][np.x] = true;
				cnt[np.y][np.x] = cnt[cp.y][cp.x] + 1; // 배열의 좌표에 길이값을 넣어야 한다

				// 경로 추적 해보기
				cout << "cp(y,x)/cnt : " << cp.y <<","<< cp.x << "/" << cnt[cp.y][cp.x];
				cout << " -> np(y,x)/cnt : " << np.y << "," << np.x << "/" << cnt[np.y][np.x] << '\n';
				
				q.push(np);

			}
		}
	}
}

int main() {
	cin >> N >> M; // y, x
	string narr;
	
	//붙여서 입력
	for (int y = 0; y < N; y++) {
		cin >> narr;
		for (int x = 0; x < M; x++) {
			board[y][x] = narr[x] - '0';
		}
	}
	
	Point start = { 0, 0 };
	bfs(start);
	cout << cnt[N-1][M-1];

}

//// DFS로 풀기. 시간초과
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//#define MAX 101
//int board[MAX][MAX];
//bool visited[MAX][MAX];
//int Min = 10001; // dfs로 최단 경로 구할때는 좌표에 저장된 값이 아닌 좌표까지 타고간 노드의 개수로 하는 듯.
//
//int N, M;
//
//typedef struct {
//	int y, x;
//}Point;
//
//Point movPnt[4] = { {1,0},{-1,0},{0,1},{0,-1} };
//
//void dfs(Point p, int depth) {
//
//	if (p.y < 0 || p.y >= N || p.x < 0 || p.x >= M) return; // ** 뒤로 돌아가 다른 경로로 갈 수 있게 return해서 방문체크 무효화해주기
//
//	// ** 최종지점 도착 한것 중 가장 작은 값을 구함 **
//	if (p.y == N - 1 && p.x == M - 1) {
//		if (depth < Min)
//			Min = depth;
//		return;
//	}
//
//	//visited[p.y][p.x] = true;
//
//	for (int i = 0; i < 4; i++) {
//		Point np;
//		np.y = p.y + movPnt[i].y;
//		np.x = p.x + movPnt[i].x;
//
//		//if (p.y >= 0 && p.y < N && p.x >= 0 && p.x < M) return;
//		if (board[np.y][np.x] == 1 && !visited[np.y][np.x])
//		{
//
//			visited[np.y][np.x] = true;
//
//			// 경로 트랙킹
//			//cout << "cp(y,x) : " << p.y << "," << p.x ;
//			//cout << " -> np(y,x)/Min : " << np.y << "," << np.x << "/" << Min << '\n';
//
//			dfs(np, depth + 1);
//			visited[np.y][np.x] = false; // ** 다시 돌아갈 수 있도록 방문처리를 무효화 해야한다 **
//				// 끝나는 것은 오로지 모든 경우의 수를 돌았을 경우
//
//		}
//	}
//}
//
//int main() {
//	cin >> N >> M; // y, x
//	string narr;
//
//	//붙여서 입력
//	for (int y = 0; y < N; y++) {
//		cin >> narr;
//		for (int x = 0; x < M; x++) {
//			board[y][x] = narr[x] - '0';
//		}
//	}
//
//	Point start = { 0, 0 };
//	dfs(start, 1);
//
//	cout << Min;
//
//}