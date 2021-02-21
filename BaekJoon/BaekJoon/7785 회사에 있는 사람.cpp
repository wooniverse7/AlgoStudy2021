#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//
//	int n;
//	map<string, bool> mp; // 이름, 출입
//	vector<string> v; // 이름
//
//	cin >> n;
//	while (n--) {
//		string name, cmd;
//		cin >> name >> cmd;
//		if (mp.find(name) != mp.end()) // 맵에 이미 있으면 해당 iter를 리턴
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
//		// 해당 이름이 없으면 end를 리턴. 배열에 입력.
//		v.push_back(name);
//		mp[name] = true; // map에도 (name, true) 입력
//	}
//
//	sort(v.begin(), v.end(), greater<string>()); // 내림차순, 사전 순의 역순
//
//	for (int i = 0; i < v.size(); i++) {
//		if (mp[v[i]] == true) { // vector v에서 각 이름에 해당하는 map mp의 value가 true이면
//			cout << v[i] << '\n';
//		}
//	}
//}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	map<string, bool> mp; // 이름, 출입
	vector<string> v; // 이름

	cin >> n;
	while (n--) {
		string name, cmd;
		cin >> name >> cmd;
		if (mp.find(name) != mp.end()) // 맵에 이미 있으면 해당 iter를 리턴
		{
			if (cmd == "enter") {
				mp[name] = true; // name에 해당하는 value를 true로 갱신
			}
			else {
				mp[name] = false;
			}

			continue; // if문 안에 있더라도 바로 다음 while문으로 돌아감. 반복문을 내에서 작동. 아래 코드 생략
		}

		// 해당 이름이 없으면 end를 리턴. 배열에 입력.
		v.push_back(name);
		mp[name] = true; // map에도 (name, true) 입력
	}

	sort(v.begin(), v.end(), greater<string>()); // 내림차순, 사전 순의 역순

	for (int i = 0; i < v.size(); i++) {
		if (mp[v[i]] == true) { // vector v에서 각 이름에 해당하는 map mp의 value가 true이면
			cout << v[i] << '\n';
		}
	}
}

//#include<iostream>
//#include<set>
//#include<string>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	
//	set<string, greater<string>> cmp; // 오름차순
//	int n;
//	cin >> n;
//	while (n--) {
//		string name, cmd;
//		cin >> name >> cmd;
//		if (cmd == "enter")
//			cmp.insert(name);
//		else
//			cmp.erase(name);
//	}
//	
//	for (const auto& it : cmp) 
//		cout << it << '\n';
//
//// it는 반복된 배열 요소에 대한 참조이므로 값이 복사되지 않음.
//// &가 없으면 값이 복사되 비용 불필요한 발생
//}