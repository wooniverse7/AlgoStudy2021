#include<iostream>

using namespace std;

int main() {
	int up, down, top, n;

	cin >> up >> down >> top;

	// n������ ���̸� ���ؾ� ��
	//n = top / (up - down);
	//cout << n + 1;

	// �ð��ʰ�
	//int h = 0;
	//while (1) {
	//	h += up;
	//	if (top <= h) {
	//		cout << n;
	//		break;
	//	}
	//	h -= down;
	//	n++;
	//}

	n = (top - up) / (up - down) + 1;

	if ((top - up) % (up - down) == 0) {
		cout << n;
	}
	else{
		cout << n+1;
	}
	
}