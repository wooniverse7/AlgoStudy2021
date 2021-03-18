// a,b,c의 원판이 옮겨지는 흐름을 파악할 것 
#include<iostream>

using namespace std;

int N;

void hanoi(int n, int a, int b, int c) { // n 1 2 3
	if (n == 1)
		cout << a << " " << c << '\n';
	else {
		// n-1개를 3번을 통해 2번째로 옮기고, 1번 n번 원판을 3번 장대로 옮긴 후,
		hanoi(n - 1, a, c, b);
		cout << a << " " << c << '\n';
		// 2번에 있는 n-1개 원판을 1번 장대를 거쳐 3번 장대로 옮긴다.
		hanoi(n - 1, b, a, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	cin >> N;

	cout << (1 << N) - 1 << '\n'; // 2의 n승 - 1

	// N개, n번 장대 
	hanoi(N, 1, 2, 3);

}

//// 출력값에 맞춰가면서 거꾸로 start, to, pass 순서 맞춰보기
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
//		// n-1개를 2번째로 옮긴후
//		hanoi(n - 1, start, pass, to);
//		cout << start << " " << to << '\n';
//		// n번째 원판을 3번째로 옮기고 
//		hanoi(n - 1, pass, to, start);
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cout.tie(NULL);
//	cin >> N;
//
//	cout << (1<<N) - 1 << '\n'; // 2의 n승 - 1
//
//	// N개, n번 장대 
//	hanoi(N, 1, 3, 2);
//
//}