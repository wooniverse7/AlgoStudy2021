#include<iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	// �ð� ���̱�
	int t;
	int min = 1000003, max = -1000003; 
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n <= min) min = n;
		if (n >= max) max = n;
	}
	cout << min << " " << max;
}