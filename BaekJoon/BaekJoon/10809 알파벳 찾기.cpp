#include<iostream>
#include<string>
#include<vector>

using namespace std;

string words;
string alphas = "abcdefghijklmnopqrstuvwxyz" ;

int main() {
	cin >> words;

	for (int i = 0; i < alphas.size(); i++) {
		if (words.find(alphas[i]) == string::npos)// ���� ���ĺ��� ���� ó�� ������ ���ĺ� �� ���� ã�� ������ �ߺ��ȰŴ� Ž������ �ʴ´�.
			cout << -1 << " ";
		else {
			cout << words.find(alphas[i]) << " ";
		}
	}

}