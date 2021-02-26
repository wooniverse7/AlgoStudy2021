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
	int y, x; // �޸� ������ y, x������ �ϴ°� ȿ�����̴�.
}Dir;

Dir moveDir[4] = { {1,0}, {-1, 0}, {0, 1}, {0, -1} }; // ����ü �迭
// y : �Ʒ�, ��, x :������, ����

void DFS(int y, int x) {
	visited[y][x] = true; 
	cnt++; // �� ĭ ũ�� üũ

	// �Ʒ�, ��, ������, ���� ������ ���� ĭ Ž��
	for (int i = 0; i < 4; i++) {
		int nY = y + moveDir[i].y;
		int nX = y + moveDir[i].x;

		if (0 <= nY && nY < M && 0 <= nX && nX < N) // �׷��� N*M ��
			if (graph[nY][nX] == 0 && !visited[nY][nX]) // ����ĭ�� ����� �湮 ������ ��
				DFS(nX, nY); // �� ĭ ������ �� ���
	}
}

int main() {
	cin >> M >> N >> K; 

	// �ǰ� �簢�� �����
	for (int i = 0; i < K; i++) // �簢�� ����
	{ 
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// ���ϴ� ���������� ���� ����������. y,x���̶� y�� �ٱ���
		// ��ǥ�� �ε��� ���̸� ������ ��
		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				graph[y][x] = 1; // �簢������ �湮 ���ϵ��� ó��
	}
	
	vector<int> result; // �� ���� ����, �� ũ��

	// �� ĭ ������ ���� ���ϱ�
	for(int y = 0; y < M; y++)
		for(int x = 0; x < N; x++)
			if (graph[y][x] == 0 && !visited[y][x]) // �� ĭ�� ã����
			{
				cnt = 0; // �ʱ�ȭ

				DFS(y, x);
				result.push_back(cnt); // �� ĭ ũ�� ����
			}

	cout << result.size() << '\n';

	sort(result.begin(), result.end());

	for (auto i : result) {
		cout << i << " ";
	}
	cout << '\n';

}