#include<iostream>
#include<string>

using namespace std;
int cnt;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string word;
		cin >> word;
		int wsize = word.size(); // for문에 size()를 쓰면 a하나일 때 out of range가 뜬다. 미리 사이즈를 잡아 놓으면 음수가 되서 바로 넘어갈 수 있다.
		bool flag = true;

		for (int j = 0; j < wsize-2; j++) {
			if (word[j] != word[j + 1]) {
				for (int k = j+2; k < wsize; k++) {
					if (word[k] == word[j]) {
						flag = false;
						break;
					}
				}

			}
		}
		if(flag) cnt++;
	}

	cout << cnt;

}


// 하나씩 흐름을 잡아 구현하다 보면 생각보다 쉽게 된다.