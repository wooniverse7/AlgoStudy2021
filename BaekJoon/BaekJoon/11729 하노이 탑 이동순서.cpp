// a,b,c�� ������ �Ű����� �帧�� �ľ��� �� 
#include<iostream>

using namespace std;

int N;

void hanoi(int n, int a, int b, int c) { // n 1 2 3
	if (n == 1)
		cout << a << " " << c << '\n';
	else {
		// n-1���� 3���� ���� 2��°�� �ű��, 1�� n�� ������ 3�� ���� �ű� ��,
		hanoi(n - 1, a, c, b);
		cout << a << " " << c << '\n';
		// 2���� �ִ� n-1�� ������ 1�� ��븦 ���� 3�� ���� �ű��.
		hanoi(n - 1, b, a, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	cin >> N;

	cout << (1 << N) - 1 << '\n'; // 2�� n�� - 1

	// N��, n�� ��� 
	hanoi(N, 1, 2, 3);

}

//// ��°��� ���簡�鼭 �Ųٷ� start, to, pass ���� ���纸��
//#include<iostream>
//
//using namespace std;
//
//int N;
//
//void hanoi(int n, int start, int to, int pass) { // n 1 3 2
//	if (n == 1)
//		cout << start << " " << to << '\n';
//	else {
//		// n-1���� 2��°�� �ű���
//		hanoi(n - 1, start, pass, to);
//		cout << start << " " << to << '\n';
//		// n��° ������ 3��°�� �ű�� 
//		hanoi(n - 1, pass, to, start);
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cout.tie(NULL);
//	cin >> N;
//
//	cout << (1<<N) - 1 << '\n'; // 2�� n�� - 1
//
//	// N��, n�� ��� 
//	hanoi(N, 1, 3, 2);
//
//}