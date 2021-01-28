#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

class DLL {
private:
	Node* header;	// != head. ù ��° ��带 ����Ű�� ������
	Node* trailer;	// != tail. ������ ��带 ����Ŵ
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

	//�� ����Ʈ
	bool empty() {
		return header->next == trailer;
	}

	//�� �� ����
	int frontNode() {
		return header->next->data;
	}
	////const �� �� ��� : ����Ű�� �ּҿ� �� ���� �ٲܼ� ����?
	////�� const : ���� ���
	////���� const : ����Ű�� �� ���ٲٰ�
	//const int& front() const {
	//	return header->next->data;
	//}

	//�� �� ����
	int backNode() {
		return trailer->prev->data;
	}

	// ------   add   ------
	// b��� �տ� a��� �߰�
	// ������ node b �ʿ�
	// addFront�� addBack�� �������� ���۷��� ���� �̿�?
	void add(Node* b, const int& num) {
		Node* a = new Node;
		a->data = num;

		a->next = b; // a->b
		a->prev = b->prev; // prev ������Ʈ
		//b->prev = a; 
		//a->prev->next = a;
		//b->prev = b->prev->next = a; // ���� �ִ� b���� ��带 a�� ����(����)
		a->prev->next = b->prev = a;// ����
	}
	void addFront(const int& num) {
		// ù��° ��� �տ� �߰�
		add(header->next, num);
	}

	////ù��° ��� �տ� �߰�
	//void addFront(const int& num) {
	//	Node *newNode = new Node;
	//	newNode->data = num;

	//	newNode->next = header->next; // ����� ����Ű�� ù ���� ��带 �� ��尡 ����Ű�� ������Ʈ
	//	header->next = newNode;
	//}
	//void addBack(const int& num) {
	//	// ������ ���� �߰�
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

		//���� �ϳ��� ����ϸ鼭 ���ָ� ��
		newNode->prev = trailer->prev;
		trailer->prev = newNode;
		newNode->next = trailer;
		newNode->prev->next = newNode;
	}

	// -------   remove   -------
	// ������ b��� ����. a->b->c => a->c
	// �� ����� next�� �� ����� prev�� �հ� �ش� ��带 �����ϸ� ��.
	void remove(Node* b) {
		Node* a = b->prev;
		Node* c = b->next;

		a->next = c;
		c->prev = a;
		delete b;
	}
	// �տ��� ����. ��� -> a -> b ==> ��� -> b
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
	// �ڿ��� ����. ������ ��常 �Է�
	void removeBack() {
		remove(trailer->prev);
	}
	//int removeBack() {

	//}


	// --- print ---
	//ù��° ��� ���
	void print() {
		
		cout << header->next->data << endl;

		//0���϶� ����
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

	// ���ϴ� ������ ��ġ ���
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