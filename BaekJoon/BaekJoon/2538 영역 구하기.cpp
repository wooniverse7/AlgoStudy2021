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
	int y, x; // 메모리 구조상 y, x순으로 하는게 효율적이다.
}Dir;

Dir moveDir[4] = { {1,0}, {-1, 0}, {0, 1}, {0, -1} }; // 구조체 배열
// y : 아래, 위, x :오른쪽, 왼쪽

void DFS(int y, int x) {
	visited[y][x] = true; 
	cnt++; // 빈 칸 크기 체크

	// 아래, 위, 오른쪽, 왼쪽 순으로 인접 칸 탐색
	for (int i = 0; i < 4; i++) {
		int nY = y + moveDir[i].y;
		int nX = y + moveDir[i].x;

		if (0 <= nY && nY < M && 0 <= nX && nX < N) // 그래프 N*M 안
			if (graph[nY][nX] == 0 && !visited[nY][nX]) // 다음칸이 비었고 방문 안했을 때
				DFS(nX, nY); // 한 칸 움직인 후 재귀
	}
}

int main() {
	cin >> M >> N >> K; 

	// 판과 사각형 만들기
	for (int i = 0; i < K; i++) // 사각형 개수
	{ 
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// 좌하단 꼭지점부터 우상단 꼭지점까지. y,x순이라 y가 바깥쪽
		// 좌표와 인덱스 차이를 인지할 것
		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				graph[y][x] = 1; // 사각형들을 방문 못하도록 처리
	}
	
	vector<int> result; // 빈 공간 개수, 각 크기

	// 빈 칸 개수와 넓이 구하기
	for(int y = 0; y < M; y++)
		for(int x = 0; x < N; x++)
			if (graph[y][x] == 0 && !visited[y][x]) // 빈 칸을 찾으면
			{
				cnt = 0; // 초기화

				DFS(y, x);
				result.push_back(cnt); // 빈 칸 크기 삽입
			}

	cout << result.size() << '\n';

	sort(result.begin(), result.end());

	for (auto i : result) {
		cout << i << " ";
	}
	cout << '\n';

}