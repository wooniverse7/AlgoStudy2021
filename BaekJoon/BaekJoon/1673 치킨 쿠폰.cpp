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
// �� ������ �Ӹ����̳� �׸����� �׷����鼭 ������ ����. 
// �ѹ��� �������� �ϴ°� ���� ������.