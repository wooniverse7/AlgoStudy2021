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
		int wsize = word.size(); // for���� size()�� ���� a�ϳ��� �� out of range�� ���. �̸� ����� ��� ������ ������ �Ǽ� �ٷ� �Ѿ �� �ִ�.
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


// �ϳ��� �帧�� ��� �����ϴ� ���� �������� ���� �ȴ�.