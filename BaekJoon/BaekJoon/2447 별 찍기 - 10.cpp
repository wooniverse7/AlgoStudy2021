// ��ǥ �ϳ��� �ľ��ϸ鼭 �� ��Ģ���� ã�Ƴ��� �����ϸ� �ȴ�.
// ó�� �ܰ���� �ϳ��� �ذ��س����� ���� �ݹ� Ǯ�� ���̴�.
#include<iostream>
#include<cmath>

using namespace std;

void rec(int i, int j, int n) {
	
	if ((i/n) % 3 == 1 && (j/n) % 3 == 1) {
		cout << " ";
	}
	else {
		// 9�� �� 4° �ٺ��� n�� 3���� ������ 
		if (n / 3 == 0)//���� 0�� �� 9�� ���� 3
			cout << "*";
		else
			rec(i, j, n / 3);
	}

}

int main() {
	int n;
	cin >> n;

	//int sqr = sqrt(n); //3 = 1, 9 = 2, 27 = 3
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rec(i, j, n);
		}
		cout << '\n';
	}
}