#include<iostream>

using namespace std;

int a[9];
int as, ds;
int main() {
	for (int i = 0; i < 8; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 7; i++)
	{
		if (a[i] < a[i + 1])
			as++;
		if (a[i] > a[i + 1])
			ds++;
	}
	if (as == 7)
		cout << "ascending" << '\n';
	else if (ds == 7)
		cout << "descending" << '\n';
	else
		cout << "mixed" << '\n';

}

// ����� ã������ ���� ���� ������.
// ��� �����ϴ� ���� Ư¡�� ����.