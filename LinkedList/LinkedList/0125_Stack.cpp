#include<iostream>
#include<stack>
using namespace std;

//#define CAP 10001
//int size[CAP];

template<typename E>
class Stack {
	enum {CAP = 10001}; // ����Ʈ ���� �뷮
private:
	E* S; // ���� ���� �迭
	int capacity; // ���� �뷮
	int t; // top ������ �ε���
public:
	// ����Ʈ ������
	Stack() {};
	// �Ű����� ������
	Stack(int CAP):S(new E[CAP]), capacity(CAP), t(-1) {

	}
	// ���� ���� ����
	int size() {
		return t + 1; // top�ε����� +1 �ؼ� ���
	}
	// ������� Ȯ��
	bool empty() {
		return t < 0;
	}
	// top ���� ����
	const E& top(){
		if (empty())
			return -1;
		else
			return S[t];
	}
	// push
	void push(const E& e) {
		S[++t] = e;
	}
	// pop
	int pop() {
		int top = t;
		if (empty()) {
			return -1;
		}
		else {
			t--;
			return top;
		}
	}

};

int main() {
	//��ü ���� ����
	Stack<int> A(10001); // �ʱ�ȭ �ʿ�?
	int n; // ��ɾ� ��
	int data; // push(data)
	string cmd;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> data;
			A.push(data);
		}
		else if (cmd == "pop") {
			A.pop();
		}
		else if (cmd == "size") {
			//��ȭ�� ���� �����ؾ���
			cout << A.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << A.empty() << '\n';
		}
		//������ ��ɹ��� else if�θ� �ؾ��ϴ°�.
		else if (cmd == "top") {
			cout << A.top() << '\n';
		}

	}
}