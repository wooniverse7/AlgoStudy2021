#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> abcV;
set<pair<char, int>> abcN;

bool comp(const string& a, const string& b) {
	if (a.size() == b.size()) // �ܾ� ���� ������ ������(��������)
		return a < b; // ���ĺ� ũ�� �� ���� abcd... 
	
	return a.size() > b.size(); // ���� ��� ������(if�� �� �ʿ� X)
		
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

	////���� ���
	//for (int i = 0; i < abcV.size(); i++) {
	//	cout << abcV[i] << " ";
	//}


}