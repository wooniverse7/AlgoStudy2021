// priorityQ, 오름차순으로 구현
#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> minHeap; // 오른차순 정렬
	// <자료형, 구조체, 정렬>
	int n;
	int x;
	
	cin >> n;
	while (n--) {
		cin >> x; // 연산에 대한 정보
		if (x == 0) {
			if (minHeap.empty()) {
				cout << "0" << '\n';
			}
			else {
				cout << minHeap.top() << '\n'; // 배열 맨 앞
				minHeap.pop();
			}
		}
		else { // x가 0이 아닐 때
			minHeap.push(x);
		}
		
	}
}