//#include<iostream>
//#include<string>
//#include<map>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//
//	int n;
//	map<string, bool> mp;
//	vector<string> v;
//
//	cin >> n;
//	while (n--) {
//		string name, cmd;
//		cin >> name >> cmd;
//		if (mp.find(name) != mp.end()) // 맵에 이미 있을 때
//		{
//			if (cmd == "enter") {
//				mp[name] = true; // name에 해당하는 value를 true로 갱신
//			}
//			else {
//				mp[name] = false;
//			}
//
//			continue; // if문 안에 있더라도 바로 다음 while문으로 돌아감. 반복문을 내에서 작동. 아래 코드 생략
//		}
//
//		// 없으면 그냥 삽입
//		v.push_back(name);
//		mp[name] = true;
//	}
//
//	sort(v.begin(), v.end(), greater<string>()); // 내림차순
//
//	for (int i = 0; i < v.size(); i++) {
//		if (mp[v[i]] == true) { // vector v에서 각 이름에 해당하는 map mp의 value가 true이면
//			cout << v[i] << '\n';
//		}
//	}
//	
//}

#include<iostream>
#include<set>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	set<string, greater<string>> comp;
	int n;
	cin >> n;
	while (n--) {
		string name, cmd;
		cin >> name >> cmd;
		if (cmd == "enter")
			comp.insert(name);
		else
			comp.erase(name);
	}
	
	for (auto& it : comp)
		cout << it << '\n';
}