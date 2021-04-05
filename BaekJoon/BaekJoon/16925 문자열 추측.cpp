#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

// 크기 오름차순 정렬
bool comp(string a, string b) {
	return a.size() < b.size();
}

// 문자열 시작 인덱스 찾는 배열
vector<int> find(string a, string b) {

}

int main() {
	int n;
	cin >> n;
	vector<string> pres;
	for (int i = 0; i < 2 * n - 2; ++i) {
		string s;
		cin >> s;
		pres.push_back(s);
	}

	vector<string> cur(pres);
	sort(pres.begin(), pres.end(), comp); //오름차순 정렬

	// 온전한 문자열을 만들 수 있는 후보군
	vector<string> cands;
	cands.push_back(pres[0] + pres[pres.size() - 2]);
	cands.push_back(pres[0] + pres[pres.size() - 1]);
	cands.push_back(pres[1] + pres[pres.size() - 2]);
	cands.push_back(pres[1] + pres[pres.size() - 1]);


}