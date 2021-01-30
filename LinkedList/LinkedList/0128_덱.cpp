// 설정
// front 삭제시 배열 이동없이 front부분만 삭제
// 첫번 쨰 원소를 2번 째 칸으로 설정

#include<iostream>
#include<string>
using namespace std;

int que[10003];
int f = 1, r = 1; // front, rear. 처음에는 둘이 같다.

bool empty() {
	return f == r;
}

// push_front
// front삽입 때마다 사이즈만큼 한칸씩 뒤로 이동
void push_front(int num) {

	if ((r - f) == 0) {
	que[f] = num; // 배열 시작하는 칸에 삽입
	r++; // 사이즈 증가
	}
	else
	{
		// 뒤에서부터 size크기 만큼 뒤로 Shift
		for(int i = r; i > f; i--){
			que[i] = que[i-1];
		}
		que[f] = num; // 배열 시작하는 칸에 삽입
		r++; // 사이즈 증가
	}
}
// f=r=10000으로 시작해보기

// push_back
void push_back(int num) {
	que[r] = num;
	r++;
}

// pop_front
// 배열 이동없이 front부분만 삭제
void pop_front() {
	// 마이너스가 되었을 때 대비
	if ((r - f) < 1) {
		cout << "-1" << '\n';
	}
	else {
		cout << que[f] << '\n';
		que[f] = 0;
		f++;
	}
}
// pop_back
void pop_back() {
	if ((r - f) < 1) {
		cout << "-1" << '\n';
	}
	else {
		cout << que[r-1] << '\n';
		que[r-1] = 0;
		r--;
	}
}

// front
int front() {
	if (f == r) {
		return -1;
	}
	else {
		return que[f];
	}
}
// rear
int back() {
	if (f == r) {
		return -1;
	}
	else {
		return que[r - 1]; 
	}
}

int main() {
	int t, n;
	string cmd;
	cin >> t;
	while (t--) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> n;
			push_front(n);
		}
		if (cmd == "push_back") {
			cin >> n;
			push_back(n);
		}
		else if (cmd == "pop_front") {
			pop_front();
		}
		else if (cmd == "pop_back") {
			pop_back();
		}
		else if (cmd == "size") {
			// 배열 마지막 - 배열 시작
			cout << r - f << '\n';
		}
		else if (cmd == "empty") {
			cout << empty() << '\n';
		}
		else if (cmd == "front") {
			cout << front() << '\n';
		}
		else if (cmd == "back") {
			cout << back() << '\n';
		}
	}
}

// 시간, 공간 복잡도
// push_front의 shift로 인해 O(n) time -> 원래는 O(1)
// O(N) space

// 큐/덱 노드로 구현해보기