// DFS, ���
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 101

int graph[MAX][MAX]; // ��
bool visited[MAX][MAX];

int M, N, K;
int cnt; // ��ĭ ũ��

typedef struct {
	int y, x; // �޸� ������ y, x������ �ϴ°� ȿ����
}Dir;

Dir moveDir[4] = { {1,0}, {-1, 0}, {0, 1}, {0, -1} }; // ����ü �迭
// y : �Ʒ�, ��, x :������, ����

void DFS(int y, int x) {
	visited[y][x] = true; 
	cnt++; // �� ĭ ũ��

	// �Ʒ�, ��, ������, ���� ������ ���� ĭ Ž��
	for (int i = 0; i < 4; i++) {
		int nY = y + moveDir[i].y;
		int nX = x + moveDir[i].x;

		if (0 <= nY && nY < M && 0 <= nX && nX < N) // ���� ������ �׷��� N*M ��
			if (graph[nY][nX] == 0 && !visited[nY][nX]) // ����ĭ�� ����� �湮 ������ ��
				DFS(nY, nX); // �� ĭ ������ �� ���
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> M >> N >> K;

	// �ǰ� �簢�� �����
	for (int i = 0; i < K; i++) // �簢�� ����
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// ���ϴ� ���������� ���� ����������. y,x���̶� y�� �ٱ���. ���Ϲ���.
		// ��ǥ�� �ε��� ���̸� ������ ��
		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				graph[y][x] = 1; // �簢������ �湮 ���ϵ��� ó��
	}

	//// ���
	//cout << '\n';
	//for(int i = 0; i < M; i++) {
	//	for (int j = 0; j < N; j++)
	//		cout << graph[i][j];
	//	cout << '\n';
	//}
	//cout << '\n';


	vector<int> result; // �� ���� ����, �� ���� ũ��

	// �� ĭ ������ ���� ���ϱ�
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (graph[y][x] == 0 && !visited[y][x]) // �� ĭ�� ã����
			{
				cnt = 0; // �ʱ�ȭ

				DFS(y, x);
				result.push_back(cnt); // �� ĭ ũ�� ����
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
//	while (!s.empty()) { // �� ������ �� ������ �� ��ȸ�ϸ� ������ ��
//		Point cp = s.top(); // current point
//		s.pop(); //
//		for (int i = 0; i < 4; i++) {
//			Point np; // next point
//			np.y = cp.y + movePoint[i].y;
//			np.x = cp.x + movePoint[i].x;
//			// Ž������ ���� �� ������ ã�� ������ Ž��
//			if (np.y >= 0 && np.y < M && np.x >= 0 && np.x < N
//				&& map[np.y][np.x] == 0 && !visited[np.y][np.x]) {
//				s.push(cp);
//				s.push(np);
//				visited[np.y][np.x] = true;
//				cnt++;
//				break;
//				// ã���� ũ�⸦ 1�ø��� ���� ������ push�Ѵ�
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