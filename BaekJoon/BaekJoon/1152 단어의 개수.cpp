#include<iostream>
#include<string>

using namespace std;

int cnt;

int main() {
	string abc;
	getline(cin, abc); // ���� ���� ���ڿ� �Է¹ޱ�

	for (int i = 0; i < abc.size(); i++) {
		if (i == 0) {
			if (abc[i] == ' ')
				cnt--;
		}
		if (abc[i] == ' ')
		{
			if (abc[i + 1] == NULL)
				continue;
			else
				cnt++;
		}
	}

	cout << cnt+1;
}