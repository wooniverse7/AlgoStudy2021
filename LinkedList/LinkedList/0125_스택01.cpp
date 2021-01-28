#include<iostream>
#include<string>
using namespace std;

int stack[10001];
int t = -1; // 아무것도 없을 때 0이 아닌 이유 : 원소가 아닌 인덱스이기 때문.

// empty
bool empty() {
	return t == -1;
	//비어있으면 1, 아니면 0
}
// push
void push(int n) {
	stack[t+1] = n; // -1+1을 하여 첫 번째부터 push
	t++;
}
// pop
void pop() {
	// 비었을 때
	if (t == -1) {
		cout << "-1" << '\n';
	}
	else {
		cout << stack[t] << '\n';
		stack[t--] = 0; // 탑의 원소를 0으로 초기화해주고 후위연산
	}
}
void top() {
	if (t == -1) {
		cout << "-1" << '\n';
	}
	else {
		cout << stack[t] << '\n';
	}
}

int main() {
	int n; // 명령어 수
	int data; // push(data)
	string cmd;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> data;
			push(data);
		}
		else if (cmd == "pop") {
			pop();
		}
		else if (cmd == "size") {
			//변화된 값을 저장해야함
			cout << t + 1 << '\n';
		}
		else if (cmd == "empty") {
			cout << empty() << '\n';
		}
		//마지막 명령문은 else if로만 해야하는가.
		else if (cmd == "top") {
			top();
		}

	}
}
