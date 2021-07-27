#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

long long calculate(vector<long long> num, vector<char> op, vector<char> rank) {
	for (auto x : rank) { // 연산자 종류
		for (int i = 0; i < op.size(); i++) { // 연산자 개수
			if (op[i] == x) { // 연산자 우선순위에 맞을 때
				// cur=현재 연산자
				// num[cur], num[cur+1]을 pop
				// 두 수 연산 후 결과를 num[cur]에 push
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

				it = num.begin() + i; // 두번 쨰 수를
				num.insert(it, rst); // num배열 첫 번째 삽입

				vector<char>::iterator ct = op.begin() + i; // 다음 연산자
				op.erase(ct);
				i--;

			}
		}

	}
	return abs(num[0]);
}

long long solution(string expression) {
	long long answer = 0;
	char str[101]; // 임시 스트링
	vector<char> op;
	vector<long long> num;

	strcpy(str, expression.c_str());  // string을 C string ptr로
	char* ptr = strtok(str, "+-*"); // 연산기호기준 토커나이즈

	// 숫자 입력
	while (ptr != NULL) { // 자른 문자열이 나오지 않을 떄까지
		num.push_back(atoi(ptr));
		ptr = strtok(NULL, "+-*");
	}
	// 연산 기호 입력
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
	