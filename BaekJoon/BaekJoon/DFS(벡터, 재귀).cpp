// vector�� ��͸� Ȱ���� dfs
#include<iostream>
#include<vector>
using namespace std;

int number = 7; // ��� ��
int c[7]; // �湮 üũ
vector<int> a[8]; // 7���� ��尡 ���� ������ ��带 ���� �� �ֵ���

void dfs(int x) {
	if (c[x]) return; // �湮�� �ߴٸ� c�� x idx�� ���� �����״� �湮�� �� üũ
	c[x] = true; // �湮 üũ
	cout << x << " ";
	for (int i = 0; i < a[x].size(); i++) { // ��� ������忡 ���ؼ�
		int y = a[x][i]; // vector a�� x idx�� �迭 i��° ��(���� ��� ��)�� y�� ����
		dfs(y); // ���, ����
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