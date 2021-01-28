#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

class DLL {
private:
	Node* header;	// != head. 첫 번째 노드를 가르키는 포인터
	Node* trailer;	// != tail. 마지막 노드를 가르킴
public:
	DLL() {
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	~DLL() {
		while (!empty()) {
			removeFront();
		}	
	}

	//빈 리스트
	bool empty() {
		return header->next == trailer;
	}

	//맨 앞 원소
	int frontNode() {
		return header->next->data;
	}
	////const 두 번 사용 : 가르키는 주소와 그 값을 바꿀수 없다?
	////앞 const : 변수 상수
	////뒤의 const : 가르키는 값 못바꾸게
	//const int& front() const {
	//	return header->next->data;
	//}

	//맨 뒤 원소
	int backNode() {
		return trailer->prev->data;
	}

	// ------   add   ------
	// b노드 앞에 a노드 추가
	// 포인터 node b 필요
	// addFront와 addBack에 쓰기위해 래퍼런스 변수 이용?
	void add(Node* b, const int& num) {
		Node* a = new Node;
		a->data = num;

		a->next = b; // a->b
		a->prev = b->prev; // prev 업데이트
		//b->prev = a; 
		//a->prev->next = a;
		//b->prev = b->prev->next = a; // 원래 있던 b앞의 노드를 a에 연결(가능)
		a->prev->next = b->prev = a;// 가능
	}
	void addFront(const int& num) {
		// 첫번째 노드 앞에 추가
		add(header->next, num);
	}

	////첫번째 노드 앞에 추가
	//void addFront(const int& num) {
	//	Node *newNode = new Node;
	//	newNode->data = num;

	//	newNode->next = header->next; // 헤더가 가르키는 첫 번쨰 노드를 뉴 노드가 가르키게 업데이트
	//	header->next = newNode;
	//}
	//void addBack(const int& num) {
	//	// 마지막 노드로 추가
	//	add(trailer, num);
	//}
	void addBack(const int& num) {
		/*Node* lastNode = new Node;
		lastNode = trailer->prev;
		Node* newNode = new Node;
		newNode->data = num;

		newNode->prev = trailer->prev;
		newNode->next = trailer;
		lastNode->next = newNode;
		trailer->prev = newNode;*/
		Node *newNode = new Node;
		newNode->data = num;

		//연결 하나씩 상상하면서 해주면 됨
		newNode->prev = trailer->prev;
		trailer->prev = newNode;
		newNode->next = trailer;
		newNode->prev->next = newNode;
	}

	// -------   remove   -------
	// 사이의 b노드 삭제. a->b->c => a->c
	// 앞 노드의 next와 뒷 노드의 prev만 잇고 해당 노드를 삭제하면 끝.
	void remove(Node* b) {
		Node* a = b->prev;
		Node* c = b->next;

		a->next = c;
		c->prev = a;
		delete b;
	}
	// 앞에서 삭제. 헤더 -> a -> b ==> 헤더 -> b
	void removeFront() {
		/*if (empty()) {
			return -1;
		}*/
		remove(header->next);
	}
	/*int removeFront() {
		Node* node;
		node = header->next;
		if (empty()) {
			return -1;
		}
		else
		{
			header->next = header->next->next;
			int deleteValue = node->data;
			delete node;
			return deleteValue;
		}
	}*/
	// 뒤에서 삭제. 삭제할 노드만 입력
	void removeBack() {
		remove(trailer->prev);
	}
	//int removeBack() {

	//}


	// --- print ---
	//첫번째 노드 출력
	void print() {
		
		cout << header->next->data << endl;

		//0개일때 에러
	}
	int printFront() {
		if (!empty())
			return -1;
		else
			return header->next->data;
	}
	int printBack() {
		if (!empty())
			return -1;
		else
			return trailer->prev->data;
	}
	void printAll() {
		Node* temp = header->next;
		while (temp != trailer) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << '\n';
	}

	// 원하는 원소의 위치 출력
	int findNum(int n) {
		Node* temp = header->next;
		int i = 0;
		while (temp->data == n) {

		}
	}
};

int main() {
	DLL dll;

	dll.addFront(1);
	dll.addFront(2);
	dll.addFront(3);
	dll.addFront(4);
	dll.printAll();
	dll.addBack(5);
	dll.addBack(6);
	dll.addBack(7);
	dll.addBack(8);
	dll.printAll();
	cout << dll.findNum(12) << endl;
	dll.removeFront();
	dll.removeFront();
	dll.removeFront();
	dll.printAll();
	cout << dll.empty() << endl;
	dll.removeBack();
	dll.removeBack();
	dll.removeBack();
	dll.printAll();


	//const int& a = 10;
}