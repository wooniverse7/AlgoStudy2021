// Ʈ��
#include<iostream>
#include<list>
using namespace std;

typedef int Elem;
struct Node {
	Elem elt; // element
	Node* par; // parent
	Node* left;
	Node* right;
	Node() : elt(), par(NULL), left(NULL), right(NULL) {} // ������
};

class LinkedBinaryTree {
public:
	// ���� Ʈ������ ��ġ�� �����ϴ� Ŭ����
	class Position {
	private:
		Node* v; // ��带 ����Ű�� ������
	public:
		Position(Node* _v = NULL) : v(_v) {} // ������
		Elem& operator*() // ���� ��ȯ
		{
			return v->elt;
		}
		Position left() const
		{
			return Position(v->left);
		}
		Position right() const
		{
			return Position(v->right);
		}
		Position parent() const
		{
			return Position(v->par);
		}
		bool isRoot() const
		{
			return v->par == NULL;
		} // ���̸� ��Ʈ, �����̸� �ڽĳ��
		bool isExtenal() const // �ܺ� �������. 
		{
			return v->left == NULL && v->right == NULL;
		} // �ڽĳ�� �� �� ������ �ܺγ��.
		friend class LinkedBinaryTree; // Ʈ�� ���� ����
	};
	typedef std::list<Position> PositionList; // ��ġ�� ����Ʈ ����
public:
	LinkedBinaryTree()
		: _root(NULL), n(0) {}

	int size() const // ����� ����
	{ return n; }

	bool empty() const // isEmpty?
	{
		return size() == 0;
	}

	Position root() const // ��Ʈ ���ϱ�
	{ return Position(_root); }

	PositionList position() const {// ��� ����Ʈ
		PositionList pl;
		preorder(_root, pl);
	}
	
	void addRoot() // �� Ʈ���� ��Ʈ �߰�
	{ _root = new Node; n = 1; }

	void expandExternal(const Position& p) {// �ܺγ�� Ȯ��
		Node* v = p.v;
		v->left = new Node;
		v->left->par = v; // v�� �θ���� ����
		v->right = new Node;
		v->right->par = v;
		n += 2; // ��尳�� 2�� ����
	}
	// p�� �θ����
	Position removeAboveExternal(const Position& p) {
		Node* w = p.v; Node* v = w->par; // p�� ��� v�� ���� �ڽ� w
		Node* sib = (w == v->left ? v->right : v->left);
		if (v == _root) { // ��Ʈ�� �ڽ��ΰ�
			_root = sib; // ������ ��Ʈ�� ����
			sib->par = NULL;
		}
		else {
			Node* gpar = v->par; // w�� ���θ�
			if (v == gpar->left) gpar->left = sib; // �θ� ������ ��ü
			else gpar->right = sib;
			sib->par = gpar;
		}
		delete w; delete v;
		n -= 2;
		return Position(sib);
	}
protected:
	// ���� �Լ�
	void preorder(Node* v, PositionList& pl) const { // ���� �����Լ�
		pl.push_back(Position(v)); // �� ��带 �߰�
		if (v->left != NULL)
			preorder(v->left, pl);
		if (v->right != NULL)
			preorder(v->right, pl);
	}
private:
	Node* _root; // ��Ʈ���� ������
	int n; // ����� ����
};

int main() {
	LinkedBinaryTree t;
	t.addRoot();
	t.expandExternal();
}