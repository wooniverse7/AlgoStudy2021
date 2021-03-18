#include<iostream>

using namespace std;
int n, narr;
int minn = 1000001;
int maxn = -1000001;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> narr;
		if (narr <= minn) {
			minn = narr;
		}
		if (narr >= maxn) {
			maxn = narr;
		}
	}
	cout << minn << " " << maxn;
}