// STL priority queue 이용
#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	priority_queue<int> maxHeap; // 기본 내림차순 정렬

	int n; // 입력 횟수
	int x; // 연산에 대한 정보
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0)
			if (maxHeap.empty()) // 비었다면 0 출력
				cout << "0" << '\n';
			else { // 아니라면 top 출력 후 pop
				cout << maxHeap.top() << '\n'; // 배열 맨 앞의 원소
				maxHeap.pop();
			}
		else { // x에 0이 아닌 수를 입력
			maxHeap.push(x); // 그 수를 priorityQ에 삽입
		}
	}
}