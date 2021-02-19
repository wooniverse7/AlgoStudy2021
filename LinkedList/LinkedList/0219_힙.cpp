#include<iostream>
#include<queue>
#include<vector>

using namespace std;
// �⺻������ max heap. ū ���� ��������
// ������ ��ȣ�� �ݴ�� �ٲپ� �������� ������ ����. ���� ���� ��������. minHeap

void heapSort(vector<int>& arr) {
	priority_queue<int> h; // �⺻������ ���� ū ���� ���� ���� ����(��������)
	// �켱���� ť�� �迭�� ���Ҹ� ���ʴ�� ���� ������
	for (int i = 0; i < arr.size(); i++) {
		h.push(-arr[i]); // arr�� ū ���� -�� �ٲ�� ���� ���� ���� ��. 2 6 4 -> -2 -4 -6
	}
	// ���� ���ӵ� ��� ���Ҹ� ���ʴ�� ������ ���
	while (!h.empty()) {
		cout << -h.top() << " "; // -2 -4 -6 -> 2 4 6 : ���� ���� ��������
		h.pop();
	}
}
int n;
vector<int> arr;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	heapSort(arr);
}