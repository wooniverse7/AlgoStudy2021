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
	Node* header;	// != head. ù ��° ��带 ����Ű�� ������
	Node* trailer;	// != tail. ������ ��带 ����Ŵ
	int n; // ������ ����
public:
	// iterator ������ �̰��� ����(��ø)
	class Iterator {
	private:
		Node* v; // ��� ������
		Iterator(Node* u)
		{v = u;} // ���κ��� ����
	public:
		// ������ �����ε�. ��2 ����.
		Elem& operator*() { return v->elem; } // ���� ����, *�� �����Ͱ� �ƴϰ� ���۷��� ������
		// ��ġ ��
		bool operator==(const Iterator& p) const
		{
			return v == p.v;
		}
		bool operator!=(const Iterator& p) const
		{
			return v != p.v;
		}
		// ���� ��ġ �̵�
		Iterator& operator++()
		{
			v = v->next; return *this;
		} 
		// ���� ��ġ �̵�
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

	// ����Ʈ ũ��
	int size() const { return n; }
	//�� ����Ʈ
	bool empty() { return (n == 0); }

	// ���� ��ġ
	Iterator begin() const 
	{ return Iterator(header->next); }
	//�� �� ����
	int frontNode() {
		return header->next->elem;
	}
	// ������ ��ġ �ٷ� ����
	Iterator end() const {
		return Iterator(trailer);
	};
	//�� �� ����
	int backNode() {
		return trailer->prev->elem;
	}

	// ------   add   ------
	// b��� �տ� a��� �߰�
	// ������ node b �ʿ�
	//void add(Node* b, const int& num) {
	void add(const Iterator& p, const Elem& e) {
		Node* w = p.v; // p ���
		Node* u = w->prev; // p �ճ��
		Node* v = new Node; // ������ �� ���

		v->elem = e;
		v->next = w; w->prev = v; // v�� w �տ� ����. v - w
		v->prev = u; u->next = v; // v�� u �ڿ� ����  u - v
		n++;
	}
	// ù��° ��� �տ� �߰�
	void addFront(const Elem& e) {
		add(begin(), e);
	}
	// ������ ���� �߰�
	void addBack(const Elem& e) {
		add(end(), e);
	}

	// -------   remove   -------
	// ������ b��� ����. a->b->c => a->c
	// �� ����� next�� �� ����� prev�� �հ� �ش� ��带 �����ϸ� ��.
	void remove(const Iterator& p) { // p ����
		Node* v = p.v; // ������ ���
		Node* w = v->next; // �� ���
		Node* u = v->prev; // �� ���
		u->next = w; w->prev = u; // ��, �޳�� ����
		delete v;
		n--;
	}
	// �տ��� ����. ��� -> a -> b ==> ��� -> b
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
	// ��������� ����
	void removeBack() {
		remove(--end());
	}

	// --- print ---
	void print() {

		cout << header->next->elem << endl;

	}
	//ù��° ��� ���
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

	// *���ϴ� ������ ��ġ ���
	// �ߺ� ������ X�� ��
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

// Iterator�� ���� ����
// ��� �˻� ����?
// ���̺귯���� ��Ĵ�� �ڷᱸ���� �� �� �ִ�. ȿ�������� ����.