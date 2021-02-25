#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string Sentence;
	getline(cin, Sentence);
	int cnt = 1;

	for (int i = 0; i < Sentence.size(); i++) {
		if (i == 0 || i == Sentence.size()-1) // 사이즈는 1부터, 배열은 0부터 시작한다.
			if (Sentence[i] == 32 || Sentence[Sentence.size()-1] == 32)
				continue;
		if (Sentence[i] == 32)
			cnt++;
	}
	// 빈 문자일 때 예외처리
	if (Sentence == " ")
		cout << "0";
	else
		cout << cnt;
	
}