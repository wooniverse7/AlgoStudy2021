#include<vector>
#include<iostream>
using namespace std;

long long int sum(vector<int>& a){
	long long ans = 0;
	for (const auto& i : a) // i 그 자체가 배열의 인덱스임. 
		// a[i]를 하면 i가 차례대로 커지는게 아니라 순서대로 탐색하면서 나온 값 i를 배열 a에 넣어서 그 위치의 값을 가져오게됨.
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