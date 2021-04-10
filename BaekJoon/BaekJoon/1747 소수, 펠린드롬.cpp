#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
	
vector<int> pr;
vector<int> pd;

void prime(int n) {
	if (n < 2) return;
	int a = (int)sqrt(n);
	for (int i = 2; i <= a; i++) {
		if (n % i == 0) return;
	}
	pr.push_back(n);
}

void palindrome(int b) {
	string st = to_string(b);
	int pdLength = st.length();
	pdLength--;
	for (int i = 0; i <= pdLength; i++) {
		if (st[i] != st[pdLength - i])
			return;
	}
	pd.push_back(b);

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 1005000; i++) { // 범위 주의
		prime(i);
	}

	//// 소수 출력
	//for (int i = 0; i < pr.size(); i++) {
	//	cout << pr[i] << " ";
	//}

	for (int i = 0; i < pr.size(); i++) {
		palindrome(pr[i]);
	}
	//// 소수&팰린드롬 수 출력 
	//for (int i = 0; i < pd.size(); i++) {
	//	cout << pd[i] << " ";
	//}

	int min = 2000000; // 범위 주의
	for (int i = 0; i < pd.size(); i++) {
		if (n <= pd[i] && min > pd[i]) {
			min = pd[i];
		}
	}
	cout << min;
}