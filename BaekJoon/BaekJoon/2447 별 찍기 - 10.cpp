// 좌표 하나씩 파악하면서 그 규칙성을 찾아내어 구현하면 된다.
// 처음 단계부터 하나씩 해결해나가다 보면 금방 풀릴 것이다.
#include<iostream>
#include<cmath>

using namespace std;

void rec(int i, int j, int n) {
	
	if ((i/n) % 3 == 1 && (j/n) % 3 == 1) {
		cout << " ";
	}
	else {
		// 9일 떄 4째 줄부터 n을 3으로 나눠서 
		if (n / 3 == 0)//몫이 0일 떄 9는 몫이 3
			cout << "*";
		else
			rec(i, j, n / 3);
	}

}

int main() {
	int n;
	cin >> n;

	//int sqr = sqrt(n); //3 = 1, 9 = 2, 27 = 3
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rec(i, j, n);
		}
		cout << '\n';
	}
}