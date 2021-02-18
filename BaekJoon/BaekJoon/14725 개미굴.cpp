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
	// Node 구조체 안에 있어야 root node에 작동 가능
	void insertFood(vector<string> v, int idx) {
		if (idx == v.size()) return; // 인덱스가 벡터 크기와 같으면 더 이상 경로가 없다.
		string food = v[idx];
		iter = child.find(food); // 맵 전체에 처음으로 발견하는 iter에 food값을 반환. 없으면 end 리턴
		// 해당 층수에 같은 경로가 있다면 다음 경로로 이동
		if (iter != child.end()) // end가 아니라면 해당 층수의 같은 값(food)이 있다는 것.
			iter->second->insertFood(v, idx + 1); // second에 value 삽입, idx 1 증가
			//iter->second->insertFood(v, idx + 1); // second에 재귀 돌리기, idx 1 증가
			// second에 재귀를 돌리는 이유? second는 포인터값이다. 그래서 재귀를 돌릴 수 있다.
			// second가 없으면 아예 재귀를 돌릴 수 없다. 노드 구조를 만들기 위해서니 Node*인 second에 넣어야 한다.

		// 해당 층수에 같은 경로 X :iter에 child.end() return. 새로운 노드를 만들어서 Map에 저장
		// 다음 경로를 Map에 insert
		else {
			Node* n = new Node;
			child.insert({ food, n }); // map에 새로운 노드와 값 insert = 굴을 팜 = 자식 생성 (삽입)
			n->insertFood(v, idx + 1); // 새로운 노드에 키값. 굴에 입력 (재귀)
		}
	}
	void print(int idx) { // idx값을 받아서 print
		if (child.empty()) return; // 층이 비었으면 리턴
		for (auto it = child.begin(); it != child.end(); it++) {
			for (int i = 0; i < idx; i++) // 층수 표시
				cout << "--";
			cout << it->first << '\n'; // key값 string..?
			// 조상 노드가 같다면 층 별 같은 먹이는 없기 때문
			it->second->print(idx + 1); // it의 second는 node ptr이기 때문에 이것으로 재귀를 돌려야한다
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
		vector<string> v; // 한 로봇이 가진 데이터 배열
		for (int j = 0; j < K; j++) {
			cin >> food;
			v.push_back(food);
		}
		root->insertFood(v, 0); // 로봇마다 새로 idx가 0인 벡터 입력
	}
	root->print(0);
}