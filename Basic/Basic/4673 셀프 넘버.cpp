#include<iostream>
#include<vector>
using namespace std;

#define N 10000 // �迭 ũ��
bool arr[N]; // selfNumber���� �ƴ���

// ���� ���� ����� �Լ�
int unSelfNum(int n) {
	
	int sum = n; // �ڱ� �ڽ��� ����
	
	while (1) {
		if (n == 0) break; // 0�� �Ǹ� break
		sum += n % 10; // 1�� �ڸ��� ���ϰ�
		n /= 10; // ���ڸ��� ����
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);

	//1~10000������ ������ ������ selfNumber�� �ƴ� ���� true�� ����
	for (int i = 1; i < N; i++) {
		// �̰� ������ ������ outOfBounds. 
		// unSelfNum(9999)�� 10000�� �Ѵµ� �װ� �迭�� ������� �� ���� �����ε�
		if(unSelfNum(i) < N)
			arr[unSelfNum(i)] = true;
	}
	// selfNumber�� �ƴ� ���� false�� �ش��ϴ� i�� ���
	for (int i = 1; i < N; i++) {
		if (!arr[i]) cout << i << '\n';
	}
	 
}