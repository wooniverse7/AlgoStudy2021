//SLL구현

#include<iostream>
using namespace std;

struct Node {
	int number; // 노드의 데이터
	Node *next; // 다음 노드의 주소
};

class SLL {
// private은 데이터 멤버, public은 멤버 함수
private:
	Node * head; // 맨 앞 노드의 주소값
public:
	//초기화 리스트 : SLL():head(NULL)
	SLL() {//생성자 초기화
		head = new Node;
		head->number = 0;//이 head에서는 데이터가 없다
		head->next = NULL;
	}
	//제일 마지막
	~SLL() {//소멸자 작동
			//for문 안되는 이유
			//int i = 0;으로 시작하는건 개수를 구할때나 전체 크기를 구할 때다.
			//리스트의 끝을 따로 구해야되고 시작을 특정짓기 애매하다.
		while (!empty()) {
			remove();
		}
	}
	//헤드 삽입
	void insert(int number) {
		//노드를 생성하기 위해 변수 생성후 노드 선언
		Node *newNode = new Node;
		//newNode에 노드 값 입력
		newNode->number = number;
		//1. 리스트가 비었을 때 2. 노드가 하나라도 있을 때
		//if (empty()) {
		//	newNode->next = NULL; // == newNode->next = head->next;
		//	head->next = newNode;
		//}
		//else {
		//	//헤드 : 첫번째 노드를 계속해서 가르킴
		//	newNode->next = head->next;
		//	//업데이트
		//	head->next = newNode;
		//}

		// - empty일때와 아닐 때 같은 표현으로 쓸 수 있는 이유 -
		// 빈 공간일 때 newNode->next = NULL인데 이때 head->next도 널이기 때문에 
		// 비어있지 않았을 때와 같은 표현으로 쓸 수 있다.
		// 노드 삽입 및 업데이트
		newNode->next = head->next;
		head->next = newNode;
	}
	//첫 번째 노드 삭제
	int remove() {
		//지울 첫번 째 노드 생성
		Node* node;
		node = head->next;
		//1. 빈 리스트 2. 노드 1개 3. 여러개
		//빈 리스트
		if (empty()) {
			return -1;
		}
		//노드 1개
		//else if (head->next->next == NULL) {
		//// head->next도 null이고 head의 next, next도 null이니 같다.
		//// head->next->next를 head->next로 갱신.
		//head->next = head->next->next; // 두번째 노드를 첫번째 노드로 갱신
		//delete node;
		//}
		//노드 여러개
		else
		{
			//1개 일때도 head의 next는 next, next와 같기 때문에 같은 코드가 된다.
			head->next = head->next->next;
			//삭제할 값 저장
			int deleteValue = node->number;
			//삭제는 마지막에
			delete node;
			//cout << "삭제한 값: ";
			return deleteValue;//삭제값 리턴

		}
	}
	//첫번째 노드 출력
	void print() {
		//head의 next만 가지고 있고 number값은 없기때문에 
		//다음 노드(첫번 째)의 number값 출력
		cout << head->next->number << endl;

		//0개일때 에러
	}

	void printAll() {
		Node* temp = head->next;
		while (temp != NULL) {
			cout << temp->number << " ";
			temp = temp->next;
		}
		cout << '\n';
	}

	//리스트 비었는지 판별
	bool empty() {
		//head의 다음 노드가 없으면 NULL
		if (head->next == NULL)
			return true;
		else
			return false;
		//같은 내용
		//return head->next == NULL;
	}

};

int main() {

	SLL sll;

	sll.insert(1);
	//cout << sll.empty() << endl;
	sll.insert(2);
	cout << sll.remove() << endl;
	sll.insert(3);
	sll.insert(4);
	sll.print();
	sll.insert(5);
	sll.insert(6);
	sll.insert(7);
	sll.printAll();
	cout << sll.remove() << endl;
	cout << sll.remove() << endl;
	cout << sll.remove() << endl;
	cout << sll.remove() << endl;
	cout << sll.empty() << endl;

	return 0;
}