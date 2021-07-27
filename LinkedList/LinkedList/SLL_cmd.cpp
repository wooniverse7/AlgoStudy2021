//SLL����
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
	//��� ����
	void insert(int data) {
		Node *newNode = new Node;
		newNode->number = data;

		// *** �ٽ� �����ϱ�(�׸� ���鼭) ***
		// ó�� �ƹ��͵� ���� ��忡�� �� ��带 �����
		// ù ��° ��带 �ι�° ���� �о new��带 ù ��° ��忡 �ְ� '����'�� �����ش�.
		//'����'���� �ִ� ���� �ٽ�
		// ��� - �� ù��� -> ��� - �� ��� - �� ù���
		newNode->next = head->next;
		//newNode->next = NULL; �ϸ� ������ �ȵ�
		head->next = newNode;
		
		
	}
	//��� ����
	int remove() {
		Node *node;  //���� ��� ����Ŵ
		node = head->next;
		if (empty()) {
			return -1;
		}
		else//(head->next->next == NULL)
		{
			
			head->next = head->next->next;
			int deleteValue = node->number; // ���� ��� ����ϱ� ���ؼ�
			delete node;

		
			return deleteValue;
		}
	}
	//��� ���
	int print() {
		if (empty()) {
			return -1;
		}
		else
			return head->next->number;
	}
	//����Ʈ ������� �Ǻ�
	bool empty() {
		return head->next == NULL;
	}

	int size() const {
		int size = 0;

		if (!this->head) return size;

		Node* current = head->next;
		while (current) {
			current = current->next;
			size++;
		}
		return size;
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
		else if (cmd == "size") {
			cout << sll.size() << endl;
		}
		else
			cout << "�˸��� �Է��� ���ּ���" << endl;
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
