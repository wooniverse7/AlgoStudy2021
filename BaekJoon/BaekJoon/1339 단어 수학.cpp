#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> abcV;
set<pair<char, int>> abcN;

bool comp(const string& a, const string& b) {
	if (a.size() == b.size()) // 단어 길이 같으면 사전순(내림차순)
		return a < b; // 알파벳 크기 비교 리턴 abcd... 
	
	return a.size() > b.size(); // 길이 긴게 앞으로(if로 비교 필요 X)
		
}

int main() {
	string abc;
	int t;
	cin >> t;
	while (t--) {	
		cin >> abc;	
		abcV.push_back(abc);
	}

	sort(abcV.begin(), abcV.end(), comp);

	////벡터 출력
	//for (int i = 0; i < abcV.size(); i++) {
	//	cout << abcV[i] << " ";
	//}


}