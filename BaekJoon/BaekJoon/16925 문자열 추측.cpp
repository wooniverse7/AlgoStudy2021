#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

// ũ�� �������� ����
bool comp(string a, string b) {
	return a.size() < b.size();
}

// ���ڿ� ���� �ε��� ã�� �迭
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
	sort(pres.begin(), pres.end(), comp); //�������� ����

	// ������ ���ڿ��� ���� �� �ִ� �ĺ���
	vector<string> cands;
	cands.push_back(pres[0] + pres[pres.size() - 2]);
	cands.push_back(pres[0] + pres[pres.size() - 1]);
	cands.push_back(pres[1] + pres[pres.size() - 2]);
	cands.push_back(pres[1] + pres[pres.size() - 1]);


}