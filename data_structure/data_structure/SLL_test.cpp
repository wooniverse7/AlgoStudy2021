#include<iostream>
using namespace std;

struct Node {
	int data = 0;
	Node* next = NULL;
};

class SLL {
private:
	Node * head = NULL;
public:
	SLL():head(NULL) {
	}
	~SLL() {
		while (!empty())
			remove();
	}
	int insert(int num) {
		Node* newNode = new Node;
		newNode->data = num;

		newNode->next = head->next; //
		head->next = newNode;
	}
	int remove() {

	}
	bool empty() {

	}
	int print(int num) {

	}
};

int main() {

	SLL sll;
}