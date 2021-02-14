#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int K, ind = 0;
int build[1026]; // 각 건물에 번호
vector<int> stage[12]; // 각 깊이 별로 건물번호를 붙여줌(2차원 배열)
struct Node {
    int num;
    Node* left;
    Node* right;
    int stage; // 층, 깊이
};

void makeTree(Node* nn, int dep) { //newNode, 깊이

    nn->num = 0;
    nn->stage = dep;

    if (dep == K) return; // 깊이가 최대깊이와 같다면 리턴

    // 처음에 연결을 시켜줘야 제대로 형태가 나온다.
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
// 인덱스를 중위순회로 입력(여긴 순서 고정)
void insertNum(Node* node, int dep) {
    if (dep > K) return; // 깊이 depth가 더 크면 리턴. external node이기 때문에.

    insertNum(node->left, dep + 1); // 왼쪽 자식에 깊이 +1. root->left, dep+1
    node->num = build[ind++]; // build배열에 인덱스를 하나씩 증가시키면서 입력받은 num을 입력
    insertNum(node->right, dep + 1);
    // 재귀는 스택이다. 재귀함수를 하나씩 쌓으면서 마지막에 pop할때 그 함수부터 시작한다.
    // 그래서 순서가 pop한 함수 밑에서 부터 시작한다
}
// 위와 유사한데 전위, 중위, 후위 순회에 따라 배치를 달리 하면됨.
// 전위 순회대로 출력형식을 위해 각 깊이별로 노드의 num을 입력해준다. 
// 순서 상관 X. 각 값이 정해져있음
void getStage(Node* node, int dep) {
    if (dep > K) return;

    stage[dep].push_back(node->num); // 각 층마다 노드의 num을 push_back함 ( 2차원 배열 생성 )
    // root->num을 stage[1]에 (2중 배열로) 삽입
    // root->left->num을 stage[2]에 삽입
    // ... 재귀로 반복

    // 자식 노드에게 재귀적으로 함수 적용
    getStage(node->left, dep + 1); // 왼쪽 자식에게 층 별로 num을 삽입하면서 깊이를 1증가시킴
    getStage(node->right, dep + 1);
}

Node* root; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for (int i = 0; i < pow(2, K) - 1; i++) { // 2의 k제곱 -1
        cin >> build[i];
    }

    root = new Node;
    // 아래 세 줄의 기능.
    // 1.트리 형태를 만들고 2.각 노드에 num을 입력하고 3.출력형식에 맞게 2차원 배열 만들기
    // root, 1을 넣는 이유 : tree만드는 문법. 처음 트리를 만들 때는 root부터 시작. root는 깊이 1
    makeTree(root, 1);
    insertNum(root, 1);
    getStage(root, 1);

    for (int i = 1; i <= K; i++) { // 최대 층 까지만. 깊이는 1부터라서 i=1.
        for (int j = 0; j < stage[i].size(); j++) { // 층 별 노드별 숫자. 각 stage 크기만큼
            cout << stage[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}