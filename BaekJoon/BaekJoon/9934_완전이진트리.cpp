#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int k; // 최대 레벨
int idx = 0;
int build[1026];
vector<int> stage[12];

struct Node {
	int num;
	int lv; // level
	Node* left;
	Node* right;
};

void makeTree(Node* node, int dep) {

	node->num = 0;
	node->lv = dep;

	if (dep == k) return; // 깊이와 k가 같으면 더이상 노드를 만들지 않음

	// 처음에는 노드를 왼쪽, 오른쪽 연결시켜줘야 형태가 만들어짐
	Node* lf = new Node;
	Node* rt = new Node;
	node->left = lf;
	node->right = rt;

	makeTree(lf, dep + 1);
	makeTree(rt, dep + 1);

	//node->left = new Node;
	//node->right = new Node;
	//makeTree(node->left, dep + 1);
	//makeTree(node->right, dep + 1);

}
//중위 순회 고정
void insert(Node* node, int dep) {
	if (dep > k) return; // 해당 깊이 까지 데이터를 입력하기 위해 같은 값까지 들어갈 수 있게 해줌

	insert(node->left, dep + 1);
	node->num = build[idx++];
	//stage[dep].push_back(node->num); // 바로 입력해도됨
	insert(node->right, dep + 1);
}

// 중위순회에 바로 입렵해도 된다.
void getStage(Node* node, int dep) {
	if (dep > k) return;

	stage[dep].push_back(node->num);
	getStage(node->left, dep + 1);
	getStage(node->right, dep + 1);
}

int main() {

	cin >> k;
	for(int i = 0; i < pow(2,k)-1; i++){
		cin >> build[i];
	}
	Node* root = new Node;
	makeTree(root, 1);
	insert(root, 1);
	getStage(root, 1);

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < stage[i].size(); j++) {
			cout << stage[i][j] << " ";
		}
		cout << '\n';
	}
}