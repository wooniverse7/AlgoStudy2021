#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int K, ind = 0;
int build[1026]; // �� �ǹ��� ��ȣ
vector<int> stage[12]; // �� ���� ���� �ǹ���ȣ�� �ٿ���(2���� �迭)
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

    // ó���� ������ ������� ����� ���°� ���´�.
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
// �ε����� ������ȸ�� �Է�(���� ���� ����)
void insertNum(Node* node, int dep) {
    if (dep > K) return; // ���� depth�� �� ũ�� ����. external node�̱� ������.

    insertNum(node->left, dep + 1); // ���� �ڽĿ� ���� +1. root->left, dep+1
    node->num = build[ind++]; // build�迭�� �ε����� �ϳ��� ������Ű�鼭 �Է¹��� num�� �Է�
    insertNum(node->right, dep + 1);
    // ��ʹ� �����̴�. ����Լ��� �ϳ��� �����鼭 �������� pop�Ҷ� �� �Լ����� �����Ѵ�.
    // �׷��� ������ pop�� �Լ� �ؿ��� ���� �����Ѵ�
}
// ���� �����ѵ� ����, ����, ���� ��ȸ�� ���� ��ġ�� �޸� �ϸ��.
// ���� ��ȸ��� ��������� ���� �� ���̺��� ����� num�� �Է����ش�. 
// ���� ��� X. �� ���� ����������
void getStage(Node* node, int dep) {
    if (dep > K) return;

    stage[dep].push_back(node->num); // �� ������ ����� num�� push_back�� ( 2���� �迭 ���� )
    // root->num�� stage[1]�� (2�� �迭��) ����
    // root->left->num�� stage[2]�� ����
    // ... ��ͷ� �ݺ�

    // �ڽ� ��忡�� ��������� �Լ� ����
    getStage(node->left, dep + 1); // ���� �ڽĿ��� �� ���� num�� �����ϸ鼭 ���̸� 1������Ŵ
    getStage(node->right, dep + 1);
}

Node* root; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for (int i = 0; i < pow(2, K) - 1; i++) { // 2�� k���� -1
        cin >> build[i];
    }

    root = new Node;
    // �Ʒ� �� ���� ���.
    // 1.Ʈ�� ���¸� ����� 2.�� ��忡 num�� �Է��ϰ� 3.������Ŀ� �°� 2���� �迭 �����
    // root, 1�� �ִ� ���� : tree����� ����. ó�� Ʈ���� ���� ���� root���� ����. root�� ���� 1
    makeTree(root, 1);
    insertNum(root, 1);
    getStage(root, 1);

    for (int i = 1; i <= K; i++) { // �ִ� �� ������. ���̴� 1���Ͷ� i=1.
        for (int j = 0; j < stage[i].size(); j++) { // �� �� ��庰 ����. �� stage ũ�⸸ŭ
            cout << stage[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}