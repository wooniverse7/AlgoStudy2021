// 트리
#include<iostream>
#include<list>
using namespace std;

typedef int Elem;
struct Node {
	Elem elt; // element
	Node* par; // parent
	Node* left;
	Node* right;
	Node() : elt(), par(NULL), left(NULL), right(NULL) {} // 생성자
};

class LinkedBinaryTree {
public:
	// 이진 트리에서 위치를 구현하는 클래스
	class Position {
	private:
		Node* v; // 노드를 가르키는 포인터
	public:
		Position(Node* _v = NULL) : v(_v) {} // 생성자
		Elem& operator*() // 원소 반환
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
		} // 참이면 루트, 거짓이면 자식노드
		bool isExtenal() const // 외부 노드인지. 
		{
			return v->left == NULL && v->right == NULL;
		} // 자식노드 둘 다 없으면 외부노드.
		friend class LinkedBinaryTree; // 트리 접근 가능
	};
	typedef std::list<Position> PositionList; // 위치의 리스트 별명
public:
	LinkedBinaryTree()
		: _root(NULL), n(0) {}

	int size() const // 노드의 개수
	{ return n; }

	bool empty() const // isEmpty?
	{
		return size() == 0;
	}

	Position root() const // 루트 구하기
	{ return Position(_root); }

	PositionList position() const {// 노드 리스트
		PositionList pl;
		preorder(_root, pl);
	}
	
	void addRoot() // 빈 트리에 루트 추가
	{ _root = new Node; n = 1; }

	void expandExternal(const Position& p) {// 외부노드 확장
		Node* v = p.v;
		v->left = new Node;
		v->left->par = v; // v를 부모노드로 만듬
		v->right = new Node;
		v->right->par = v;
		n += 2; // 노드개수 2개 증가
	}
	// p와 부모삭제
	Position removeAboveExternal(const Position& p) {
		Node* w = p.v; Node* v = w->par; // p의 노드 v와 그의 자식 w
		Node* sib = (w == v->left ? v->right : v->left);
		if (v == _root) { // 루트의 자식인가
			_root = sib; // 형제를 루트로 만듬
			sib->par = NULL;
		}
		else {
			Node* gpar = v->par; // w의 조부모
			if (v == gpar->left) gpar->left = sib; // 부모를 형제로 대체
			else gpar->right = sib;
			sib->par = gpar;
		}
		delete w; delete v;
		n -= 2;
		return Position(sib);
	}
protected:
	// 전위 함수
	void preorder(Node* v, PositionList& pl) const { // 전위 편의함수
		pl.push_back(Position(v)); // 이 노드를 추가
		if (v->left != NULL)
			preorder(v->left, pl);
		if (v->right != NULL)
			preorder(v->right, pl);
	}
private:
	Node* _root; // 루트로의 포인터
	int n; // 노드의 개수
};

int main() {
	LinkedBinaryTree t;
	t.addRoot();
	t.expandExternal();
}