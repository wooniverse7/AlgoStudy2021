#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int K, ind = 0;
int build[1026];
vector<int> stage[12];
struct Node {
    int num;
    Node* left;
    Node* right;
    int stage; // 층, 높이
};

void makeTree(Node* nn, int dep) { //newNode, 깊이

    nn->num = 0;
    nn->stage = dep;

    if (dep == K) return; // 깊이가 최대깊이와 같다면 리턴

    Node* lf = new Node; // left. 왼쪽 자식
    Node* rt = new Node; // right. 오른쪽 자식
    nn->left = lf;
    nn->right = rt;

    // 자식 노드를 만들면서 깊이에 1을 추가시켜줌
    // 그리고 깊이가 k가 될 떄 까지 자식노드에서 makeTree함수를 재귀로 반복한다.
    makeTree(lf, dep + 1); 
    makeTree(rt, dep + 1);
}
// 트리를 만든 다음에 각 노드에 순서대로 num을 입력한다.
// 중위 순회 순으로. 전위순회면 입력부분이 첫번째. 후외는 세번째.
void insertNum(Node* node, int dep) {
    if (dep > K) return; // 깊이 dep이 더 크면 끝낸다. external node이기 때문에.

    insertNum(node->left, dep + 1); // 왼쪽 자식에 깊이 +1
    node->num = build[ind++]; // build배열에 인덱스를 하나씩 증가시키면서 입력받은 num을 입력
    insertNum(node->right, dep + 1);
    // 재귀는 스택이다. 재귀함수를 하나씩 쌓으면서 마지막에 pop할때 그 함수부터 시작한다.
    // 그래서 순서가 pop한 함수 밑에서 부터 시작한다
}
// 위와 유사한데 전위, 중위, 후위 순회에 따라 배치를 달리 하면됨.
// 전위 순회대로 출력형식을 위해 각 노드에 깊이를 입력해준다. 
void getStage(Node* node, int dep) {
    if (dep > K) return;

    stage[dep].push_back(node->num); // 각 층마다 노드의 num을 push_back함
    // 자식 노드에게 재귀적으로 함수 적용
    getStage(node->left, dep + 1);  // 왼쪽 자식에게 층 별로 num을 삽입하면서 깊이를 1증가시킴
    getStage(node->right, dep + 1);
}

Node* root; // struct에 변수를 생성하지 않고 여기서 만듬.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for (int i = 0; i < pow(2, K) - 1; i++) { // 2의 k제곱 -1
        cin >> build[i];
    }

    root = new Node;
    // 아래 세 줄의 기능. root, 1을 넣는 이유
    makeTree(root, 1);
    insertNum(root, 1);
    getStage(root, 1);

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < stage[i].size(); j++) {
            cout << stage[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}