// vector와 재귀를 활용한 dfs
#include<iostream>
#include<vector>
using namespace std;

int number = 7; // 노드 수
int c[7]; // 방문 체크
vector<int> a[8]; // 7개의 노드가 각각 인접한 노드를 가질 수 있도록

void dfs(int x) {
	if (c[x]) return; // 방문을 했다면 c의 x idx에 값이 있을테니 방문한 것 체크
	c[x] = true; // 방문 체크
	cout << x << " ";
	for (int i = 0; i < a[x].size(); i++) { // 모든 인접노드에 대해서
		int y = a[x][i]; // vector a의 x idx의 배열 i번째 값(인접 노드 값)을 y에 삽입
		dfs(y); // 재귀, 스택
	}
}

int main() {

	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[4].push_back(8);
	a[8].push_back(4);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	dfs(1);

	return 0;
}