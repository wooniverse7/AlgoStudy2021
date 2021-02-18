#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

struct Node {
	// key, value���� �����ϱ� ����
	map<string, Node*> child;
	map<string, Node*>::iterator iter;
	// Node ����ü �ȿ� �־�� root node�� �۵� ����
	void insertFood(vector<string> v, int idx) {
		if (idx == v.size()) return; // �ε����� ���� ũ��� ������ �� �̻� ��ΰ� ����.
		string food = v[idx];
		iter = child.find(food); // �� ��ü�� ó������ �߰��ϴ� iter�� food���� ��ȯ. ������ end ����
		// �ش� ������ ���� ��ΰ� �ִٸ� ���� ��η� �̵�
		if (iter != child.end()) // end�� �ƴ϶�� �ش� ������ ���� ��(food)�� �ִٴ� ��.
			iter->second->insertFood(v, idx + 1); // second�� value ����, idx 1 ����
			//iter->second->insertFood(v, idx + 1); // second�� ��� ������, idx 1 ����
			// second�� ��͸� ������ ����? second�� �����Ͱ��̴�. �׷��� ��͸� ���� �� �ִ�.
			// second�� ������ �ƿ� ��͸� ���� �� ����. ��� ������ ����� ���ؼ��� Node*�� second�� �־�� �Ѵ�.

		// �ش� ������ ���� ��� X :iter�� child.end() return. ���ο� ��带 ���� Map�� ����
		// ���� ��θ� Map�� insert
		else {
			Node* n = new Node;
			child.insert({ food, n }); // map�� ���ο� ���� �� insert = ���� �� = �ڽ� ���� (����)
			n->insertFood(v, idx + 1); // ���ο� ��忡 Ű��. ���� �Է� (���)
		}
	}
	void print(int idx) { // idx���� �޾Ƽ� print
		if (child.empty()) return; // ���� ������� ����
		for (auto it = child.begin(); it != child.end(); it++) {
			for (int i = 0; i < idx; i++) // ���� ǥ��
				cout << "--";
			cout << it->first << '\n'; // key�� string..?
			// ���� ��尡 ���ٸ� �� �� ���� ���̴� ���� ����
			it->second->print(idx + 1); // it�� second�� node ptr�̱� ������ �̰����� ��͸� �������Ѵ�
			}
		}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Node* root = new Node;
	int N, K;
	string food;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		vector<string> v; // �� �κ��� ���� ������ �迭
		for (int j = 0; j < K; j++) {
			cin >> food;
			v.push_back(food);
		}
		root->insertFood(v, 0); // �κ����� ���� idx�� 0�� ���� �Է�
	}
	root->print(0);
}