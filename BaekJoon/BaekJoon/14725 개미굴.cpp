#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

struct Node {
	// key, value값을 정렬하기 위해
	map<string, Node*> child;
	map<string, Node*>::iterator iter;
	void insertFood(vector<string> v, int idx) {
		if (idx == v.size()) return; // 인덱스가 벡터 크기와 같으면 더 이상 경로가 없다.
		string food = v[idx];
		iter = child.find(food); // 맵 전체에 처음으로 발견하는 key값의 iter를 반환. 없으면 end 리턴
		// 해당 층수에 같은 경로가 있다면 다음 경로로 이동
		if (iter != child.end()) // end가 아니라면 해당 층수의 같은 값이 있다는 것.
			iter->second->insertFood(v, idx + 1); // second에 value 삽입, idx 1 증가
		// 해당 층수에 같은 경로 X :iter에 child.end() return. 새로운 노드를 만들어서 Map에 저장
		// 다음 경로를 Map에 insert
		else {
			Node* n = new Node;
			child.insert({ food, n }); // map에 새로운 노드 insert. 굴을 팜 = 자식 생성
			n->insertFood(v, idx + 1); // 새로운 노드에 키값. 굴에 입력(재귀)
		}
	}
	void print(int idx) { // idx값을 받아서 print
		if (child.empty()) return; // 층이 비었으면 리턴
		for (auto it = child.begin(); it != child.end(); it++) {
			for (int i = 0; i < idx; i++) // 층수 표시
				cout << "--";
			cout << it->first << '\n'; // key값 string..?
			// 조상 노드가 같다면 층 별 같은 먹이는 없기 때문..?
			it->second->print(idx + 1); // value값 dfs
				
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
		vector<string> v;
		for (int j = 0; j < K; j++) {
			cin >> food;
			v.push_back(food);
		}
		root->insertFood(v, 0); // 로봇마다 새로 idx가 0인 벡터 입력
	}
	root->print(0);

}