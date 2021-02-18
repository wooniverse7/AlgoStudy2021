// priorityQ, ������������ ����
#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> minHeap; // �������� ����
	// <�ڷ���, ����ü, ����>
	int n;
	int x;
	
	cin >> n;
	while (n--) {
		cin >> x; // ���꿡 ���� ����
		if (x == 0) {
			if (minHeap.empty()) {
				cout << "0" << '\n';
			}
			else {
				cout << minHeap.top() << '\n'; // �迭 �� ��
				minHeap.pop();
			}
		}
		else { // x�� 0�� �ƴ� ��
			minHeap.push(x);
		}
		
	}
}