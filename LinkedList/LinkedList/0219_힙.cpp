#include<iostream>
#include<queue>
#include<vector>

using namespace std;
// 기본적으로 max heap. 큰 값이 먼저나옴
// 원소의 부호를 반대로 바꾸어 오름차순 정렬을 수행. 작은 값이 먼저나옴. minHeap

void heapSort(vector<int>& arr) {
	priority_queue<int> h; // 기본적으로 가장 큰 값이 가장 먼저 나옴(내림차순)
	// 우선순위 큐에 배열의 원소를 차례대로 넣은 다음에
	for (int i = 0; i < arr.size(); i++) {
		h.push(-arr[i]); // arr의 큰 수가 -로 바뀌어 가장 작은 값이 됨. 2 6 4 -> -2 -4 -6
	}
	// 힙에 삽임된 모든 원소를 차례대로 꺼내어 출력
	while (!h.empty()) {
		cout << -h.top() << " "; // -2 -4 -6 -> 2 4 6 : 작은 값이 먼저나옴
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