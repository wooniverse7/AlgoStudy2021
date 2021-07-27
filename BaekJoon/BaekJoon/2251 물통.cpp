#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;

#define MAX 201

int A, B, C;
bool chk[MAX][MAX][MAX];

//vector<int> bfs() {
//	queue<pair<pair<int, int>, int>> q; //a, b, c
//	q.push(make_pair(make_pair(0, 0), 0));
//	vector<int> rst;
//
//	while (!q.empty()) {
//		int a = q.front().first.first;
//		int b = q.front().first.second;
//		int c = q.front().second;
//		q.pop();
//
//		if (chk[a][b][c]) continue;
//
//		chk[a][b][c] = true;
//
//		if (a == 0) rst.push_back(c); // 조건 충족
//
//		// a->b
//		if (a + b > B)
//			q.push(make_pair(make_pair(a + b - B, B), c));
//		else
//			q.push(make_pair(make_pair(0, a+b), c));
//
//		// a->c
//		if(a+c > C)
//			q.push(make_pair(make_pair(a + b - C, b), C));
//		else
//			q.push(make_pair(make_pair(0, b), a + c));
//
//
//	}
//}
//
//int main() {
//	cin >> A >> B >> C;
//
//	vector<int> rst = bfs();
//
//	sort(rst.begin(), rst.end());
//	for (int i = 0; i < rst.size(); i++) {
//		cout << rst[i] << endl;
//	}
//
//	
//}

set<int> s;

void dfs(int a, int b, int c) {
	if(chk[a][b][c])

}

