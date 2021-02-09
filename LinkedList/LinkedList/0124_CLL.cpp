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
	Node* cursor; // Ŀ��
public:
	CLL() : cursor(NULL){
		//front = new Node;
		//back = new Node;
		//this->cursor = front;
		//cursor->next = back;
	}
	~CLL() {

	}

	// Ŀ���� ���� ���� ������.
	void advance() {
		cursor = cursor->next;
	}

	// Ŀ�� ���� ��忡 �߰�
	void add(const int& num) {
		Node* mid = new Node;
		mid->data = num;
		// �� ����Ʈ�� �� Ŀ���� �߰��� ��带 ����Ų��.
		if (cursor == NULL) {
			mid->next = mid;
			cursor = mid;
		}
		else {
			mid->next = cursor->next;
			cursor->next = mid;
			cursor = mid; // ** Ŀ�� �Է¼� ������Ʈ **
		}
	}

	// Ŀ�� ���� ��� ����
	int remove() {
		Node* mid = cursor->next;
		int old = mid->data; // ������ ��� ���

		if (cursor == NULL) {
			return -1;
		}
		else {
			cursor->next = mid->next; // Ŀ���� �������� ��忡 ����
			delete mid; // ���� ������
			cout << old << " ����" << endl;
		}
	}
	
	// �� ����Ʈ Ȯ��
	bool empty() {
		//���������� �������
		return cursor == NULL;
	}

	// Ŀ�� ������ ����
	const int& front(){
		return cursor->next->data;
	}

	// ���� Ŀ�� ��ġ�� ����
	const int& back(){
		return cursor->data;
	}

	// ��ü ��� ����
	void printAll() {
		Node* location = new Node;
		location = this->cursor;
		cursor = cursor->next; // ** ���� **
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