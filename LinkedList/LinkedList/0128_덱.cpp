// ����
// front ������ �迭 �̵����� front�κи� ����
// ù�� �� ���Ҹ� 2�� ° ĭ���� ����

#include<iostream>
#include<string>
using namespace std;

int que[10003];
int f = 1, r = 1; // front, rear. ó������ ���� ����.

bool empty() {
	return f == r;
}

// push_front
// front���� ������ �����ŭ ��ĭ�� �ڷ� �̵�
void push_front(int num) {

	if ((r - f) == 0) {
	que[f] = num; // �迭 �����ϴ� ĭ�� ����
	r++; // ������ ����
	}
	else
	{
		// �ڿ������� sizeũ�� ��ŭ �ڷ� Shift
		for(int i = r; i > f; i--){
			que[i] = que[i-1];
		}
		que[f] = num; // �迭 �����ϴ� ĭ�� ����
		r++; // ������ ����
	}
}
// f=r=10000���� �����غ���

// push_back
void push_back(int num) {
	que[r] = num;
	r++;
}

// pop_front
// �迭 �̵����� front�κи� ����
void pop_front() {
	// ���̳ʽ��� �Ǿ��� �� ���
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
			// �迭 ������ - �迭 ����
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

// �ð�, ���� ���⵵
// push_front�� shift�� ���� O(n) time -> ������ O(1)
// O(N) space

// ť/�� ���� �����غ���