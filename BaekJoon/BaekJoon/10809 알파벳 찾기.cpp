#include<iostream>
#include<string>
#include<vector>

using namespace std;

string words;
string alphas = "abcdefghijklmnopqrstuvwxyz" ;

int main() {
	cin >> words;

	for (int i = 0; i < alphas.size(); i++) {
		if (words.find(alphas[i]) == string::npos)// 같은 알파벳은 제일 처음 나오는 알파벳 한 번만 찾기 때문에 중복된거는 탐지되지 않는다.
			cout << -1 << " ";
		else {
			cout << words.find(alphas[i]) << " ";
		}
	}

}