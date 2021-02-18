// 힙을 배열로 구현(정적)

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100002
int heap[MAX];
int sz = 0; // 배열 크기

void swap(int* a, int* b) { // &는 안되고 pointer만 되는 이유 찾아보기. &로 구현해보기
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int num) {
	int idx = ++sz; // 삽입 때 마다 사이즈 먼저 1 증가

	while ((idx != 1) && (num > heap[idx / 2])) {// 첫 번째가 아니고 입력된 num이 현재 idx의 부모노드보다 클 때까지
		heap[idx] = heap[idx / 2]; // 
		idx /= 2;
	}
	heap[idx] = num;
}

int deleteHeap() {

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x; // 반복수, 정보가 담긴 수

	cin >> n;
	while (n--) {
		cin >> x;
		
	}


}