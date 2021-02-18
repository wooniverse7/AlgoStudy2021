//Á¤¸®
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

string food;

struct Node {
	map<string, Node*> child;
	map<string, Node*>::iterator iter;
	void insertFood(vector<string> v, int idx) {
		if (idx == v.size()) return;

		food = v[idx];
		iter = child.find(food);
		if (iter != child.end()) {
			iter->second->insertFood(v, idx + 1);
		}
		else {
			Node* nu = new Node;
			child.insert({ food, nu });
			nu->insertFood(v, idx + 1);
		}
	}
	void print(int idx) {
		if (child.empty()) return;
		for (auto it = child.begin(); it != child.end(); it++) {
			for (int i = 0; i < idx; i++) {
				cout << "--";
			}
			cout << it->first << '\n';
			it->second->print(idx + 1);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	Node* root = new Node;
	cin >> N;
	while (N--) {
		cin >> K;
		vector<string> v;
		for (int i = 0; i < K; i++) {
			cin >> food;
			v.push_back(food);
		}
		root->insertFood(v, 0);
	}
	root->print(0);

}