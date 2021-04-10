//훨씬 쉽게 가능. 수정 필요.
#include<iostream>
#include<vector>
using namespace std;

vector<int> d;
vector<int> dd;
vector<int> hd;

void decimal(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10; //1234의 4+ -> 123의 3+
		n /= 10; // 123 -> 12 -> 1 -> 0
	}
	d.push_back(sum);
}

void duoDec(int n) {
	int sum = 0;

	while (n) {
		sum += n % 12;
		n /= 12;
	}
	dd.push_back(sum);
}

void hexaDec(int n) {
	int sum = 0;

	while (n) {
		sum += n % 16;
		n /= 16;
	}
	hd.push_back(sum);
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);

	for (int i = 1000; i <= 9999; i++) {
		decimal(i);
		duoDec(i);
		hexaDec(i);
		if (d[i-1000] == dd[i-1000] && d[i-1000] == hd[i-1000]) {
			cout << i << '\n';
		}
	}

}