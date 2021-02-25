//#include<iostream>
//#include<string>
//
//using namespace std;

//char alpha[27] { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', '\o' }; // a ~ z : 26개
//
//int main() {
//	int rst[26]; // 결과값
//	fill_n(rst, 26, -1);
//
//	string s;
//	cin >> s;
//
//	for (int i = 0; i < s.size(); i++) {
//		for (int j = 0; j < 26; j++) {
//			if (s[i] == alpha[j] && rst[j] == -1) // rst에 한 번도 입력안된것을 조건에 추가
//				rst[j] = i;
//		}
//	}
//
//	for (int i = 0; i < 26; i++) {
//		cout << rst[i] << " ";
//	}
//}
#include<iostream>
#include<string>

using namespace std;

int main() {
	string word;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	int rst[26];
	fill_n(rst, 26, -1);

	cin >> word;

	for (int i = 0; i < alpha.size(); i++) {
		if (word.find(alpha[i]) == string::npos) // 없으면 -1을 출력
			cout << -1 << " ";
		else {
			// find는 해당 원소를 찾으면 그 원소의 idx를 반환한다
			cout << word.find(alpha[i]) << " ";
		}
	}
}