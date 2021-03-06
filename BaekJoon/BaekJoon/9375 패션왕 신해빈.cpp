#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {

	int T, N; // 테스트수, 의상수
	int rst; // 결과
	string clth, key;

	map<string, int> mp; // < 의상 종류, 해당하는 의상 수 >
	//pair<map<string, int>::iterator, bool> chk;
	// 반복자로 map 배열을 끝까지 돌면서 이미 있는지 체크해줄 pair 구조체
	
	cin >> T;
	while (T--) {
		mp.clear();
		rst = 1;
		cin >> N;
		while (N--) {
			cin >> clth >> key;
			//chk = mp.insert(pair<string, int>(key, 1)); 
			//// map에 이미 key가 있으면 (중복key의 iter(위치), false=0) 리턴, 
			//// 없으면 (insert된 key의 iter, true=1)를 리턴

			//if (!chk.second) // ck가 false이면 이미 중복된 key가 있다 (0을 제외하고 다 true)
			//	mp[key]++; // 해당 key의 int값을 +1해준다
			
			// 중복키 확인 필요 X
			mp[key] += 1;
		}
		for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
			rst = rst * (iter->second + 1); // iter가 가르키는 map의 snd값(int), 없는경우 1 추가
		}
		cout << rst - 1 << '\n'; // 모두다 없는 경우 -1
	}

}


//pr = m.insert(pair <string, int>(key, 1));
// map에 insert할 때 리턴값으로 pair값을 돌려줌. 
// 성공 : < insert된 elem의 iter, true >, 중복된 key가 존재하지 않을 때
// 실패 : < 중복된 elem의 iter, flase >, 중복된 key가 존재할 때

// map. 종류별로 몇 개가 있는지, 문자열에 키 값