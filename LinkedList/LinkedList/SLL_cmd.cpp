//SLL구현
#include<iostream>
#include<string>
using namespace std;

struct Node {
	int number;
	Node *next;
};

class SLL {
private:
	Node * head;
public:
	SLL() {
		head = new Node;
		head->next = NULL;
		head->number = 0;
	}
	~SLL() {
		while (!empty()) {
			remove();
		}
	}
	//헤드 삽입
	void insert(int data) {
		Node *newNode = new Node;
		newNode->number = data;

		// *** 다시 복습하기(그림 보면서) ***
		// 처음 아무것도 없는 노드에서 새 노드를 만들고
		// 첫 번째 노드를 두번째 노드로 밀어내 new노드를 첫 번째 노드에 넣고 '연결'을 시켜준다.
		//'연결'시켜 주는 것이 핵심
		// 헤드 - 구 첫노드 -> 헤드 - 새 노드 - 구 첫노드
		newNode->next = head->next;
		//newNode->next = NULL; 하면 연결이 안됨
		head->next = newNode;
	}
	//헤드 삭제
	int remove() {
		Node *node;  //지울 노드 가르킴
		node = head->next;
		if (empty()) {
			return -1;
		}
		else//(head->next->next == NULL)
		{
			head->next = head->next->next;
			int deleteValue = node->number;
			delete node;
			return deleteValue;
		}
	}
	//헤드 출력
	int print() {
		if (empty()) {
			return -1;
		}
		else
			return head->next->number;
	}
	//리스트 비었는지 판별
	bool empty() {
		return head->next == NULL;
	}
};

int main() {
	SLL sll;
	string cmd;
	int n;

	while (true) {
		cin >> cmd;
		if (cmd == "insert") {
			cin >> n;
			sll.insert(n);
		}
		else if (cmd == "remove") {
			cout << sll.remove() << endl;
			//cout << sll.print() << endl;
			//sll.remove();
		}
		else if (cmd == "print") {
			cout << sll.print() << endl;
		}
		else if (cmd == "empty") {
			cout << sll.empty() << endl;
		}
		else if (cmd == "quit") {
			break;
		}
		else
			cout << "알맞은 입력을 해주세요" << endl;
	}

	//cout << sll.print() << endl;

	/*sll.insert(5);
	cout << sll.empty() << endl;
	sll.insert(10);
	cout << sll.remove() << endl;
	sll.insert(6);
	sll.insert(7);
	cout << sll.print() << endl;*/
}
