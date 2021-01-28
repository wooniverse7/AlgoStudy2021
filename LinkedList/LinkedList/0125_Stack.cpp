#include<iostream>
#include<stack>
using namespace std;

//#define CAP 10001
//int size[CAP];

template<typename E>
class Stack {
	enum {CAP = 10001}; // 디폴트 스택 용량
private:
	E* S; // 스택 원소 배열
	int capacity; // 스택 용량
	int t; // top 원소의 인덱스
public:
	// 디폴트 생성자
	Stack() {};
	// 매개변수 생성자
	Stack(int CAP):S(new E[CAP]), capacity(CAP), t(-1) {

	}
	// 스택 원소 개수
	int size() {
		return t + 1; // top인덱스에 +1 해서 출력
	}
	// 비었는지 확인
	bool empty() {
		return t < 0;
	}
	// top 원소 리턴
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
	//객체 생성 에러
	Stack<int> A(10001); // 초기화 필요?
	int n; // 명령어 수
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
			//변화된 값을 저장해야함
			cout << A.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << A.empty() << '\n';
		}
		//마지막 명령문은 else if로만 해야하는가.
		else if (cmd == "top") {
			cout << A.top() << '\n';
		}

	}
}