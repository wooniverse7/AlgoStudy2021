#include<iostream>
#include<string>
using namespace std;

int stack[10001];
int t = -1; // �ƹ��͵� ���� �� 0�� �ƴ� ���� : ���Ұ� �ƴ� �ε����̱� ����.

// empty
bool empty() {
	return t == -1;
	//��������� 1, �ƴϸ� 0
}
// push
void push(int n) {
	stack[t+1] = n; // -1+1�� �Ͽ� ù ��°���� push
	t++;
}
// pop
void pop() {
	// ����� ��
	if (t == -1) {
		cout << "-1" << '\n';
	}
	else {
		cout << stack[t] << '\n';
		stack[t--] = 0; // ž�� ���Ҹ� 0���� �ʱ�ȭ���ְ� ��������
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
	int n; // ��ɾ� ��
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
			//��ȭ�� ���� �����ؾ���
			cout << t + 1 << '\n';
		}
		else if (cmd == "empty") {
			cout << empty() << '\n';
		}
		//������ ��ɹ��� else if�θ� �ؾ��ϴ°�.
		else if (cmd == "top") {
			top();
		}

	}
}
