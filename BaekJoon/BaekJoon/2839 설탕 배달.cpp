//for���� ����� 5���� ä���ְ� �ȵǸ� 3�ϳ� �״��� �ϳ��� �ϴ� ������ ¥����
#include<iostream>

using namespace std;

int main() {
	int a;
	cin >> a;

	if (a == 4 || a == 7) {
		cout << -1;
		return 0;
	}

	if (a % 5 == 0) {
		cout << a / 5;
	}
	else if (a % 5 == 1) {
		cout << a / 5 + 1;
	}
	else if (a % 5 == 2) {
		cout << a / 5 + 2;
	}
	else if (a % 5 == 3) {
		cout << a / 5 + 1;
	}
	else if(a % 5 == 4) {
		cout << a / 5 + 2;
	}

}