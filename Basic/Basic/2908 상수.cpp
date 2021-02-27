#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());


	for (int i = 0; i < 3; i++) {
		if (a[i] > b[i]) {
			cout << a;
			break;
		}
		else if (a[i] == b[i])
			continue;
		else {
			cout << b;
			break;
		}
	}
}
