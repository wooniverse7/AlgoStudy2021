#include<iostream>
#include<vector>
using namespace std;

#define N 10000 // 배열 크기
bool arr[N]; // selfNumber인지 아닌지

// 다음 수를 만드는 함수
int unSelfNum(int n) {
	
	int sum = n; // 자기 자신을 더함
	
	while (1) {
		if (n == 0) break; // 0이 되면 break
		sum += n % 10; // 1의 자리씩 더하고
		n /= 10; // 한자리씩 없애
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);

	//1~10000까지의 수에서 생성된 selfNumber가 아닌 수에 true를 해줌
	for (int i = 1; i < N; i++) {
		// 이걸 해주지 않으면 outOfBounds. 
		// unSelfNum(9999)는 10000이 넘는데 그걸 배열에 집어넣을 수 없기 때문인듯
		if(unSelfNum(i) < N)
			arr[unSelfNum(i)] = true;
	}
	// selfNumber가 아닌 수인 false에 해당하는 i값 출력
	for (int i = 1; i < N; i++) {
		if (!arr[i]) cout << i << '\n';
	}
	 
}