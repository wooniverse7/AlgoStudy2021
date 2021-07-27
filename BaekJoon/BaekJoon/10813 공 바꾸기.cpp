#include<iostream>

using namespace std;

int n, m;
int arr[102];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		swap(arr[a], arr[b]);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
}