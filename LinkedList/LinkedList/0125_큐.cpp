#include<iostream>
#include<string>
using namespace std;

int que[10001];
int f = 0, r = 0; // front, rear
//int cursor = -1;

bool empty() {
	return f == r;
}

// push
void push(int num) {
	que[r] = num;
	r++;
}
// pop
void pop() {
	if (f == r) {
		cout << "-1" << '\n';
	}
	else {
		cout << que[f] << '\n';
		que[f] = 0;
		f++;
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
		return que[r-1]; // 2개 삽입 = queue[1]
	}
}

int main() {
	int t, n;
	string cmd;
	cin >> t;
	while (t--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> n;
			push(n);
		}
		else if (cmd == "pop") {
			pop();
		}
		else if (cmd == "size") {
			// 배열 마지막 - 배열 시작
			cout << r-f << '\n';
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

// O(1) time