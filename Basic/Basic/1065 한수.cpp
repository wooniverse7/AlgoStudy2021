#include<iostream>
using namespace std;

bool arr[1001]; // �Ѽ����� �ƴ���
int cnt;

bool hansu(int n) {
	if (n < 100) return true;

	int ab = n / 100 - n % 100 / 10; //100�� �ڸ��� - 10�� �ڸ���
	int bc = n % 100 / 10 - n % 10; // 10�� �ڸ��� - 1�� �ڸ���
	if (ab == bc)
		return true;
	else
		return false;

}

int main() {
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		arr[i] = hansu(i);
		if (arr[i] == true) cnt++;
	}
	cout << cnt;
}