#include<iostream>
using namespace std;

int first; // ó����
int A;
int B; // A 10�� �ڸ� + 1�� �ڸ�
int newA = 123; // A������ �ڸ� * 10 + B ������ �ڸ�. 
				//0�̸� �ٷ� ���������� ������ 100�̻��� ���� �ʱ�ȭ.
int cycle = 0;

int main() {

	cin >> first; // 26
	A = first;
	while (first != newA) {
		B = A / 10 + A % 10; // 08
		newA = (A % 10) * 10 + B % 10; // 68
		A = newA;

		cycle++;
	}

	cout << cycle;
}