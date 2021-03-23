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
		m1[name]++; // 순차적으로 map에 string만 입력, 그 인덱스 snd에 1삽입
	}
	for (int i = 0; i < m; i++) {
		cin >> name;
		m1[name]++; // 중복 입력된 string은 그 인덱스의 snd에 1을 더해 2가됨, 다른 방법으로 증가는 못시키는듯
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
//		if (Map.count(input))	// 해당 이름이 이미 있으면
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