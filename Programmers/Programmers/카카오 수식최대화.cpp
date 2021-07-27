#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

long long calculate(vector<long long> num, vector<char> op, vector<char> rank) {
	for (auto x : rank) { // ������ ����
		for (int i = 0; i < op.size(); i++) { // ������ ����
			if (op[i] == x) { // ������ �켱������ ���� ��
				// cur=���� ������
				// num[cur], num[cur+1]�� pop
				// �� �� ���� �� ����� num[cur]�� push
				vector<long long>::iterator it = num.begin() + i;

				long long one = *it;
				long long two = *(it + 1);
				num.erase(it, it + 2);

				long long rst = 0;
				if (x == '*')
					rst = one * two;
				else if (x == '-')
					rst = one - two;
				else
					rst = one + two;

				it = num.begin() + i; // �ι� �� ����
				num.insert(it, rst); // num�迭 ù ��° ����

				vector<char>::iterator ct = op.begin() + i; // ���� ������
				op.erase(ct);
				i--;

			}
		}

	}
	return abs(num[0]);
}

long long solution(string expression) {
	long long answer = 0;
	char str[101]; // �ӽ� ��Ʈ��
	vector<char> op;
	vector<long long> num;

	strcpy(str, expression.c_str());  // string�� C string ptr��
	char* ptr = strtok(str, "+-*"); // �����ȣ���� ��Ŀ������

	// ���� �Է�
	while (ptr != NULL) { // �ڸ� ���ڿ��� ������ ���� ������
		num.push_back(atoi(ptr));
		ptr = strtok(NULL, "+-*");
	}
	// ���� ��ȣ �Է�
	for (auto i : expression) {
		if (!(i >= '0' && i <= '9')) op.push_back(i);
	}

	vector<char> rank{ '*', '+', '-' };

	do {
		long long max = calculate(num, op, rank);
		if (max > answer) answer = max;
	} while (next_permutation(rank.begin(), rank.end()));

	return answer;
}

int main() {
	string expression = "100-200*300-500+20";
	cout << solution(expression);
}
	