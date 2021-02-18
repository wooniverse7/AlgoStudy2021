// STL priority queue �̿�
#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	priority_queue<int> maxHeap; // �⺻ �������� ����

	int n; // �Է� Ƚ��
	int x; // ���꿡 ���� ����
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0)
			if (maxHeap.empty()) // ����ٸ� 0 ���
				cout << "0" << '\n';
			else { // �ƴ϶�� top ��� �� pop
				cout << maxHeap.top() << '\n'; // �迭 �� ���� ����
				maxHeap.pop();
			}
		else { // x�� 0�� �ƴ� ���� �Է�
			maxHeap.push(x); // �� ���� priorityQ�� ����
		}
	}
}