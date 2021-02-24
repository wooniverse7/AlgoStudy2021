#include<vector>
#include<iostream>
using namespace std;

long long int sum(vector<int>& a){
	long long ans = 0;
	for (const auto& i : a) // i �� ��ü�� �迭�� �ε�����. 
		// a[i]�� �ϸ� i�� ���ʴ�� Ŀ���°� �ƴ϶� ������� Ž���ϸ鼭 ���� �� i�� �迭 a�� �־ �� ��ġ�� ���� �������Ե�.
		ans += i;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> m;
		a.push_back(m);
	}
	cout << sum(a);

}