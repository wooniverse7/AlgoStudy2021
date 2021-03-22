// 출력값에 맞춰가면서 거꾸로 start, to, pass 순서 맞춰보기
#include<iostream>

using namespace std;

int N;

void hanoi(int n, int start, int to, int pass) { // n 1 3 2
	if (n == 1)
		cout << start << " " << to << '\n';
	else {
		// n-1개를 2번째로 옮긴후
		hanoi(n - 1, start, pass, to);
		cout << start << " " << to << '\n'; // = hanoi(1, start, to, pass);
		// n번째 원판을 3번째로 옮기고 
		hanoi(n - 1, pass, to, start);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	cin >> N;

	cout << (1<<N) - 1 << '\n'; // 2의 n승 - 1

	// N개, n번 장대 
	hanoi(N, 1, 3, 2); // from - to는 처음에 무조건 1, 3 이기 때문.

}

//https://www.youtube.com/watch?v=AogMbfRwguk&ab_channel=%EC%BD%94%EB%94%A9%EB%9E%A9CodingLab
//#include<iostream>
//
//using namespace std;
//
//int n;
//
//void hanoi(int n, int from, int to) {
//	int mid = 6 - from - to;
//
//	if (n == 1) {
//		cout << from << " " << to << '\n';
//		return;
//	}
//	else {
//		hanoi(n - 1, from, mid);
//		hanoi(1, from, to);
//		hanoi(n - 1, mid, to);
//	}
//
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	cin >> n;
//	cout << (1 << n) - 1 << '\n';
//	hanoi(n, 1, 3);
//}

//// a,b,c의 원판이 옮겨지는 흐름을 파악할 것 
//#include<iostream>
//
//using namespace std;
//
//int N;
//
//void hanoi(int n, int a, int b, int c) { // n 1 2 3
//	if (n == 1)// 2. 1번 n번 원판을 3번 장대로 옮긴 후,
//		cout << a << " " << c << '\n';
//	else {
//		// 1. n-1개를 3번을 통해 2번째로 옮기고, 
//		hanoi(n - 1, a, c, b);
//		cout << a << " " << c << '\n';
//		// 3. 2번에 있는 n-1개 원판을 1번 장대를 거쳐 3번 장대로 옮긴다.
//		hanoi(n - 1, b, a, c);
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cout.tie(NULL);
//	cin >> N;
//
//	cout << (1 << N) - 1 << '\n'; // 2의 n승 - 1
//
//	// N개, n번 장대 
//	hanoi(N, 1, 2, 3);
//
//}