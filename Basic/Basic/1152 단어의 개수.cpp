#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string Sentence;
	getline(cin, Sentence);
	int cnt = 1;

	for (int i = 0; i < Sentence.size(); i++) {
		if (i == 0 || i == Sentence.size()-1) // ������� 1����, �迭�� 0���� �����Ѵ�.
			if (Sentence[i] == 32 || Sentence[Sentence.size()-1] == 32)
				continue;
		if (Sentence[i] == 32)
			cnt++;
	}
	// �� ������ �� ����ó��
	if (Sentence == " ")
		cout << "0";
	else
		cout << cnt;
	
}