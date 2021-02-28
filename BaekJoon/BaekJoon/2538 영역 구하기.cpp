// DFS, 재귀
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 101

int graph[MAX][MAX]; // 판
bool visited[MAX][MAX];

int M, N, K;
int cnt; // 빈칸 크기

typedef struct {
	int y, x; // 메모리 구조상 y, x순으로 하는게 효율적
}Dir;

Dir moveDir[4] = { {1,0}, {-1, 0}, {0, 1}, {0, -1} }; // 구조체 배열
// y : 아래, 위, x :오른쪽, 왼쪽

void DFS(int y, int x) {
	visited[y][x] = true; 
	cnt++; // 빈 칸 크기

	// 아래, 위, 오른쪽, 왼쪽 순으로 인접 칸 탐색
	for (int i = 0; i < 4; i++) {
		int nY = y + moveDir[i].y;
		int nX = x + moveDir[i].x;

		if (0 <= nY && nY < M && 0 <= nX && nX < N) // 다음 방향이 그래프 N*M 안
			if (graph[nY][nX] == 0 && !visited[nY][nX]) // 다음칸이 비었고 방문 안했을 때
				DFS(nY, nX); // 한 칸 움직인 후 재귀
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> M >> N >> K;

	// 판과 사각형 만들기
	for (int i = 0; i < K; i++) // 사각형 개수
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// 좌하단 꼭지점부터 우상단 꼭지점까지. y,x순이라 y가 바깥쪽. 상하반전.
		// 좌표와 인덱스 차이를 인지할 것
		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				graph[y][x] = 1; // 사각형들을 방문 못하도록 처리
	}

	//// 출력
	//cout << '\n';
	//for(int i = 0; i < M; i++) {
	//	for (int j = 0; j < N; j++)
	//		cout << graph[i][j];
	//	cout << '\n';
	//}
	//cout << '\n';


	vector<int> result; // 빈 공간 개수, 각 공간 크기

	// 빈 칸 개수와 넓이 구하기
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (graph[y][x] == 0 && !visited[y][x]) // 빈 칸을 찾으면
			{
				cnt = 0; // 초기화

				DFS(y, x);
				result.push_back(cnt); // 빈 칸 크기 삽입
			}
		}
	}


	cout << result.size() << '\n';

	sort(result.begin(), result.end());

	for (auto i : result) {
		cout << i << " ";
	}

}

//// DFS, Stack
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<stack>
//
//using namespace std;
//
//#define MAX 101
//
//int map[MAX][MAX];
//bool visited[MAX][MAX];
//int cnt;
//int M, N, K;
//
//typedef struct {
//	int y, x;
//}Point;
//
//Point movePoint[4] = { {1,0}, {-1,0}, {0, 1}, {0, -1} };
//
//
//
//int dfs(Point t) {
//	stack<Point> s;
//	s.push(t);
//	visited[t.y][t.x] = true;
//	while (!s.empty()) { // 들어간 점에서 빈 공간을 다 순회하면 스택이 빔
//		Point cp = s.top(); // current point
//		s.pop(); //
//		for (int i = 0; i < 4; i++) {
//			Point np; // next point
//			np.y = cp.y + movePoint[i].y;
//			np.x = cp.x + movePoint[i].x;
//			// 탐색하지 않은 빈 공간을 찾을 때까지 탐색
//			if (np.y >= 0 && np.y < M && np.x >= 0 && np.x < N
//				&& map[np.y][np.x] == 0 && !visited[np.y][np.x]) {
//				s.push(cp);
//				s.push(np);
//				visited[np.y][np.x] = true;
//				cnt++;
//				break;
//				// 찾으면 크기를 1늘리고 다음 공간을 push한다
//			}
//		}
//	}
//
//	return cnt;
//}
//
//int main() {
//	vector<int> rst;
//
//	cin >> M >> N >> K;
//	for (int i = 0; i < K; i++) {
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		for (int y = y1; y < y2; y++)
//			for (int x = x1; x < x2; x++)
//				map[y][x] = 1;
//	}
//
//	for (int y = 0; y < M; y++) {
//		for (int x = 0; x < N; x++) {
//			if (map[y][x] == 0 && !visited[y][x])
//			{
//				cnt = 1;
//				Point tmp;
//				tmp.y = y;
//				tmp.x = x;
//				dfs(tmp);
//				rst.push_back(cnt);
//				//rst.push_back(dfs(tmp));
//			}
//		}
//	}
//
//	cout << rst.size() << '\n';
//	sort(rst.begin(), rst.end());
//	for (auto i : rst)
//		cout << i << " ";
//	cout << '\n';
//
//}