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
    int stage; // ��, ����
};

void makeTree(Node* nn, int dep) { //newNode, ����

    nn->num = 0;
    nn->stage = dep;

    if (dep == K) return; // ���̰� �ִ���̿� ���ٸ� ����

    Node* lf = new Node; // left. ���� �ڽ�
    Node* rt = new Node; // right. ������ �ڽ�
    nn->left = lf;
    nn->right = rt;

    // �ڽ� ��带 ����鼭 ���̿� 1�� �߰�������
    // �׸��� ���̰� k�� �� �� ���� �ڽĳ�忡�� makeTree�Լ��� ��ͷ� �ݺ��Ѵ�.
    makeTree(lf, dep + 1); 
    makeTree(rt, dep + 1);
}
// Ʈ���� ���� ������ �� ��忡 ������� num�� �Է��Ѵ�.
// ���� ��ȸ ������. ������ȸ�� �Էºκ��� ù��°. �Ŀܴ� ����°.
void insertNum(Node* node, int dep) {
    if (dep > K) return; // ���� dep�� �� ũ�� ������. external node�̱� ������.

    insertNum(node->left, dep + 1); // ���� �ڽĿ� ���� +1
    node->num = build[ind++]; // build�迭�� �ε����� �ϳ��� ������Ű�鼭 �Է¹��� num�� �Է�
    insertNum(node->right, dep + 1);
    // ��ʹ� �����̴�. ����Լ��� �ϳ��� �����鼭 �������� pop�Ҷ� �� �Լ����� �����Ѵ�.
    // �׷��� ������ pop�� �Լ� �ؿ��� ���� �����Ѵ�
}
// ���� �����ѵ� ����, ����, ���� ��ȸ�� ���� ��ġ�� �޸� �ϸ��.
// ���� ��ȸ��� ��������� ���� �� ��忡 ���̸� �Է����ش�. 
void getStage(Node* node, int dep) {
    if (dep > K) return;

    stage[dep].push_back(node->num); // �� ������ ����� num�� push_back��
    // �ڽ� ��忡�� ��������� �Լ� ����
    getStage(node->left, dep + 1);  // ���� �ڽĿ��� �� ���� num�� �����ϸ鼭 ���̸� 1������Ŵ
    getStage(node->right, dep + 1);
}

Node* root; // struct�� ������ �������� �ʰ� ���⼭ ����.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for (int i = 0; i < pow(2, K) - 1; i++) { // 2�� k���� -1
        cin >> build[i];
    }

    root = new Node;
    // �Ʒ� �� ���� ���. root, 1�� �ִ� ����
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