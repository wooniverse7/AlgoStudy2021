// ���� �迭�� ����(����)

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100002
int heap[MAX];
int sz = 0; // �迭 ũ��

void swap(int* a, int* b) { // &�� �ȵǰ� pointer�� �Ǵ� ���� ã�ƺ���. &�� �����غ���
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int num) {
	int idx = ++sz; // ���� �� ���� ������ ���� 1 ����

	while ((idx != 1) && (num > heap[idx / 2])) {// ù ��°�� �ƴϰ� �Էµ� num�� ���� idx�� �θ��庸�� Ŭ ������
		heap[idx] = heap[idx / 2]; // 
		idx /= 2;
	}
	heap[idx] = num;
}

int deleteHeap() {

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x; // �ݺ���, ������ ��� ��

	cin >> n;
	while (n--) {
		cin >> x;
		
	}


}