#include<iostream>

using namespace std;

int a[1003];
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i+1 < n && a[i] == a[i + 1])
			continue;
		cout << a[i] << '\n';
	}
}