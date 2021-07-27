#include<iostream>

using namespace std;

int main() {
	int n, k;
	while(cin >> n >> k){
		int ans = 0, coupon = n, stamp = 0;
		while (coupon) {
			ans += coupon;
			stamp += coupon;
			coupon = 0;
			coupon = stamp / k;
			stamp %= k;
		}
		cout << ans << '\n';
	}
}
// 한 과정씩 머릿속이나 그림으로 그려가면서 구현을 하자. 
// 한번에 끝낼려고 하는게 제일 느리다.