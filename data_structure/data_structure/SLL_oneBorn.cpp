//SLL����

#include<iostream>
using namespace std;

struct Node {
	int number;//����� ������
	Node *next;//���� ����� �ּ�
};

class SLL {
	//private�� ������ ���, public�� ��� �Լ�
private:
	Node* head;//�� �� ����� �ּҰ�
public:
	//�ʱ�ȭ ����Ʈ : SLL():head(NULL)
	SLL() {//������ �ʱ�ȭ
		head = new Node;
		head->number = 0;//�� head������ �����Ͱ� ����
		head->next = NULL;
	}
	//���� ������
	~SLL() {//�Ҹ��� �۵�
			//for�� �ȵǴ� ����
			//int i = 0;���� �����ϴ°� ������ ���Ҷ��� ��ü ũ�⸦ ���� ����.
			//����Ʈ�� ���� ���� ���ؾߵǰ� ������ Ư������ �ָ��ϴ�.
		while (!empty()) {
			remove();
		}
	}
	//��� ����
	void insert(int number) {
		//��带 �����ϱ� ���� ���� ������ ��� ����
		Node *newNode = new Node;
		//newNode�� ��� �� �Է�
		newNode->number = number;
		//1. ����Ʈ�� ����� �� 2. ��尡 �ϳ��� ���� ��
		//if (empty()) {
		//	newNode->next = NULL; // == newNode->next = head->next;
		//	head->next = newNode;
		//}
		//else {
		//	//��� : ù��° ��带 ����ؼ� ����Ŵ
		//	newNode->next = head->next;
		//	//������Ʈ
		//	head->next = newNode;
		//}

		// - empty�϶��� �ƴ� �� ���� ǥ������ �� �� �ִ� ���� -
		// �� ������ �� newNode->next = NULL�ε� �̶� head->next�� ���̱� ������ 
		// ������� �ʾ��� ���� ���� ǥ������ �� �� �ִ�.
		// ��� ���� �� ������Ʈ
		newNode->next = head->next;
		head->next = newNode;
	}
	//ù ��° ��� ����
	int remove() {
		//���� ù�� ° ��� ����
		Node* node;
		node = head->next;
		//1. �� ����Ʈ 2. ��� 1�� 3. ������
		//�� ����Ʈ
		if (empty()) {
			return -1;
		}
		//��� 1��
		//else if (head->next->next == NULL) {
		//// head->next�� null�̰� head�� next, next�� null�̴� ����.
		//// head->next->next�� head->next�� ����.
		//head->next = head->next->next; // �ι�° ��带 ù��° ���� ����
		//delete node;
		//}
		//��� ������
		else
		{
			//1�� �϶��� head�� next�� next, next�� ���� ������ ���� �ڵ尡 �ȴ�.
			head->next = head->next->next;
			//������ �� ����
			int deleteValue = node->number;
			//������ ��������
			delete node;
			//cout << "������ ��: ";
			return deleteValue;//������ ����

		}
	}
	//ù��° ��� ���
	int print() {
		//head�� next�� ������ �ְ� number���� ���⶧���� 
		//���� ���(ù�� °)�� number�� ���
		return head->next->number;

		//0���϶� ����
	}

	//int printAll() {
	//	Node* Pointer;
	//while (!(Pointer->next == NULL)) {
	//		
	//	}
	//}

	//����Ʈ ������� �Ǻ�
	bool empty() {
		//head�� ���� ��尡 ������ NULL
		if (head->next == NULL)
			return true;
		else
			return false;
		//���� ����
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
	cout << sll.print() << endl;
	sll.insert(5);
	sll.insert(6);
	sll.insert(7);
	cout << sll.printAll() << endl;
	cout << sll.remove() << endl;
	cout << sll.remove() << endl;
	cout << sll.remove() << endl;
	cout << sll.remove() << endl;
	cout << sll.empty() << endl;


}

//1��11�ϱ���
//���� �Լ����ٰ� ���α׷� �����
//�ڵ� ������ �� ��ɾ��� ���� ���� �� �ְ�

//i�Է� ���� �� insert�� �ְ�
//insert 5
//delete
//���� ����, �Ⱥ��� ����