#include<iostream>
using namespace std;

typedef int Elem;
struct Node {
	Elem elem;
	Node* prev;
	Node* next;
};

class NodeList {
private:
	Node* header;	// != head. 첫 번째 노드를 가르키는 포인터
	Node* trailer;	// != tail. 마지막 노드를 가르킴
	int n; // 아이템 개수
public:
	// iterator 선언을 이곳에 삽입(중첩)
	class Iterator {
	private:
		Node* v; // 노드 포인터
		Iterator(Node* u)
		{v = u;} // 노드로부터 생성
	public:
		// 연산자 오버로딩. 객2 공부.
		Elem& operator*() { return v->elem; } // 원소 참조, *는 포인터가 아니고 디레퍼런스 연산자
		// 위치 비교
		bool operator==(const Iterator& p) const
		{
			return v == p.v;
		}
		bool operator!=(const Iterator& p) const
		{
			return v != p.v;
		}
		// 다음 위치 이동
		Iterator& operator++()
		{
			v = v->next; return *this;
		} 
		// 이전 위치 이동
		Iterator& operator--() 	
		{
			v = v->prev; return *this;
		}
		friend class NodeList;
	};
public:
	NodeList() {
		n = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	~NodeList() {
		while (!empty()) {
			removeFront();
		}
	}

	// 리스트 크기
	int size() const { return n; }
	//빈 리스트
	bool empty() { return (n == 0); }

	// 시작 위치
	Iterator begin() const 
	{ return Iterator(header->next); }
	//맨 앞 원소
	int frontNode() {
		return header->next->elem;
	}
	// 마지막 위치 바로 다음
	Iterator end() const {
		return Iterator(trailer);
	};
	//맨 뒤 원소
	int backNode() {
		return trailer->prev->elem;
	}

	// ------   add   ------
	// b노드 앞에 a노드 추가
	// 포인터 node b 필요
	//void add(Node* b, const int& num) {
	void add(const Iterator& p, const Elem& e) {
		Node* w = p.v; // p 노드
		Node* u = w->prev; // p 앞노드
		Node* v = new Node; // 삽입할 새 노드

		v->elem = e;
		v->next = w; w->prev = v; // v를 w 앞에 연결. v - w
		v->prev = u; u->next = v; // v를 u 뒤에 연결  u - v
		n++;
	}
	// 첫번째 노드 앞에 추가
	void addFront(const Elem& e) {
		add(begin(), e);
	}
	// 마지막 노드로 추가
	void addBack(const Elem& e) {
		add(end(), e);
	}

	// -------   remove   -------
	// 사이의 b노드 삭제. a->b->c => a->c
	// 앞 노드의 next와 뒷 노드의 prev만 잇고 해당 노드를 삭제하면 끝.
	void remove(const Iterator& p) { // p 삭제
		Node* v = p.v; // 삭제될 노드
		Node* w = v->next; // 뒷 노드
		Node* u = v->prev; // 앞 노드
		u->next = w; w->prev = u; // 앞, 뒷노드 연결
		delete v;
		n--;
	}
	// 앞에서 삭제. 헤더 -> a -> b ==> 헤더 -> b
	void removeFront() {
		remove(begin());
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
			int deleteValue = node->elem;
			delete node;
			return deleteValue;
		}
	}*/
	// 마지막노드 삭제
	void removeBack() {
		remove(--end());
	}

	// --- print ---
	void print() {

		cout << header->next->elem << endl;

	}
	//첫번째 노드 출력
	int printFront() {
		if (!empty())
			return -1;
		else
			return header->next->elem;
	}
	int printBack() {
		if (!empty())
			return -1;
		else
			return trailer->prev->elem;
	}
	void printAll() {
		Node* temp = header->next;
		while (temp != trailer) {
			cout << temp->elem << " ";
			temp = temp->next;
		}
		cout << '\n';
	}

	// *원하는 원소의 위치 출력
	// 중복 데이터 X일 때
	int findNum(int n) {
		Node* temp = header->next;
		int i = 0;
		while (temp->elem == n) {

		}
	}
};

int main() {
	NodeList NodeList;

	NodeList.addFront(1);
	NodeList.addFront(2);
	NodeList.addFront(3);
	NodeList.addFront(4);
	NodeList.printAll();
	NodeList.addBack(5);
	NodeList.addBack(6);
	NodeList.addBack(7);
	NodeList.addBack(8);
	NodeList.printAll();
	//cout << NodeList.findNum(12) << endl;
	NodeList.removeFront();
	NodeList.removeFront();
	NodeList.removeFront();
	NodeList.printAll();
	cout << NodeList.empty() << endl;
	NodeList.removeBack();
	NodeList.removeBack();
	NodeList.removeBack();
	NodeList.printAll();

}

// Iterator를 쓰는 이유
// 경계 검사 때문?
// 라이브러리의 방식대로 자료구조를 할 수 있다. 효과적으로 동작.