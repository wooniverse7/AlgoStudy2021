// 덱, 문자열
#include<iostream>
#include<deque>
#include<string>
using namespace std;

char card[1002];
string result; // 초기화를 위해 변수 scope를 while내로 한정

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	deque<char> dq;

	int t, N;

	cin >> t;
	while (t--) {
		
		cin >> N; // 카드 수
		for (int i = 0; i < N; i++) {
			cin >> card[i];
		}
		dq.push_front(card[0]); // 포인트
		
		for (int i = 1; i < N; i++) {
			if (dq.front() >= card[i])
			{
				dq.push_front(card[i]);
			}
			else {
				dq.push_back(card[i]);
			}
		}
		while (N--) {
			result += dq.front();
			dq.pop_front();
		}
		cout << result << '\n'; // result 초기화 필수

		dq.clear();	// deque 초기화
		result.clear(); // 초기화
		//memset(card, '0', N + 1); // char 배열 초기화
		//card[N + 1] = '\0'; // 첫번째 원소만 초기화됨. 이유
	}
	
}