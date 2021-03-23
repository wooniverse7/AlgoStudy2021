#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

map<string, int> m1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	string name;
	vector<string> v1;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> name;
		m1[name]++; // ���������� map�� string�� �Է�, �� �ε��� snd�� 1����
	}
	for (int i = 0; i < m; i++) {
		cin >> name;
		m1[name]++; // �ߺ� �Էµ� string�� �� �ε����� snd�� 1�� ���� 2����, �ٸ� ������� ������ ����Ű�µ�
	}

	for (auto it : m1) {
		if (it.second == 2) {
			v1.push_back(it.first);
		}
	}

	sort(v1.begin(), v1.end());

	cout << v1.size() << '\n';
	for (auto it : v1) {
		cout << it << '\n';
	}

}

//#include <iostream>
//#include <string>
//#include <map>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int N, M;
//string input;
//map<string, int> Map;
//vector<string> res;
//
//int main()
//{
//	cin >> N >> M;
//	while (N--)
//	{
//		cin >> input;
//		Map.insert({ input, 1 });
//	}
//
//	while (M--)
//	{
//		cin >> input;
//		if (Map.count(input))	// �ش� �̸��� �̹� ������
//		{
//			res.push_back(input);
//		}
//	}
//
//	sort(res.begin(), res.end());
//
//	cout << res.size() << '\n';
//
//	for (size_t i = 0; i < res.size(); i++)
//	{
//		cout << res[i] << '\n';
//	}
//	return 0;
//
//}