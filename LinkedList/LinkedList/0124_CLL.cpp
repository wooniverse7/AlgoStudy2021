#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class CLL {
private:
	//Node* front;
	//Node* back;
	Node* cursor; // 커서
public:
	CLL() : cursor(NULL){
		//front = new Node;
		//back = new Node;
		//this->cursor = front;
		//cursor->next = back;
	}
	~CLL() {

	}

	// 커서를 다음 노드로 움직임.
	void advance() {
		cursor = cursor->next;
	}

	// 커서 다음 노드에 추가
	void add(const int& num) {
		Node* mid = new Node;
		mid->data = num;
		// 빈 리스트일 때 커서는 추가된 노드를 가르킨다.
		if (cursor == NULL) {
			mid->next = mid;
			cursor = mid;
		}
		else {
			mid->next = cursor->next;
			cursor->next = mid;
			cursor = mid; // ** 커서 입력순 업데이트 **
		}
	}

	// 커서 다음 노드 삭제
	int remove() {
		Node* mid = cursor->next;
		int old = mid->data; // 삭제한 노드 출력

		if (cursor == NULL) {
			return -1;
		}
		else {
			cursor->next = mid->next; // 커서를 다음다음 노드에 연결
			delete mid; // 제일 마지막
			cout << old << " 삭제" << endl;
		}
	}
	
	// 빈 리스트 확인
	bool empty() {
		//시작지점이 비었으면
		return cursor == NULL;
	}

	// 커서 다음의 원소
	const int& front(){
		return cursor->next->data;
	}

	// 현재 커서 위치의 원소
	const int& back(){
		return cursor->data;
	}

	// 전체 출력 에러
	void printAll() {
		Node* location = new Node;
		location = this->cursor;
		cursor = cursor->next; // ** 수정 **
		while (cursor != location) {
			cout << cursor->data << " ";
			cursor = cursor->next;
		}
		cout << cursor->data;
		cout << endl;
	}
};

int main() {
	CLL c;

	c.add(1);
	c.add(2);
	c.add(3);
	c.add(4);
 	c.add(5);
	c.printAll();
	c.advance();
	c.printAll();
	c.remove();
	c.remove();
	c.remove();
	c.printAll();

}
// 
// [c54321]
// [5c4321] -> [c 5 4 3 2 1]
//  c
// [5 4 3 2 1]