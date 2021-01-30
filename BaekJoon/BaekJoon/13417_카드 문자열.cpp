// ��, ���ڿ�
#include<iostream>
#include<deque>
#include<string>
using namespace std;

char card[1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	deque<char> dq;

	int t, N;

	cin >> t;
	while (t--) {
		string result; // �Ź� �����ϰ� ���� �ʱ�ȭ. �ٸ� �����?
		
		cin >> N; // ī�� ��
		for (int i = 0; i < N; i++) {
			cin >> card[i];
		}
		dq.push_front(card[0]);
		
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
		cout << result << '\n'; // result �ʱ�ȭ �ʼ�

		dq.clear();	// deque �ʱ�ȭ
		//memset(card, '0', N + 1); // char �迭 �ʱ�ȭ
		//card[N + 1] = '\0'; // ù��° ���Ҹ� �ʱ�ȭ��. ����
		
	}
}