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

	////up�� ������ �Ϸ簡 ����. down�� �����Ѵ�.
	//n = (top - up) / (up - down) + 1;

	//if ((top - up) % (up - down) == 0) {
	//	cout << n;
	//}
	//else{
	//	// �������� ������ 1�� �����ش�.
	//	cout << n+1;
	//}

	cout << (top - down - 1) / (up - down) + 1;
	// int�� ������ ���� ������ ������ �̿�
	// �̸� 1�� ���� (top-down)%(up-down)�� �������� ���°��� �ְԸ��� �� ������ +1
	// ���� ������ �ִ� �͵��� up-down >= 1�̱� ������ ����X
	// �׷��� �� -1�� ���� ��ü�� ������ +1�� �ϸ� �ȴ�.
}