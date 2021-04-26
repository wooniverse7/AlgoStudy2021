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

// 방법을 찾을려고만 하지 말고 만들어보자.
// 계속 증가하는 것의 특징이 뭔지.