#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> croatian = { "dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
int idx;

int main() {
	string abc;
	cin >> abc;

	for (int i = 0; i < croatian.size(); i++) {
		while (1) {
			idx = abc.find(croatian[i]); // find함수는 스스로 끝까지 탐색한다. 성공시 해당 문자열의 처음 문자 idx반환
			if (idx == string::npos) // 더이상 없는 경우 0을 반환해서 탈출
				break;
			abc.replace(idx, croatian[i].length(), "#"); 
		}
	}

	//cout << abc << '\n';
	cout << abc.size() << '\n';

}