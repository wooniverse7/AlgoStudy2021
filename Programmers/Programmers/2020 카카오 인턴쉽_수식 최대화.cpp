// 연산 기호와 수를 따로 저장할 벡터를 지정
// 문자열을 수로 받은 후 연산자 우선순위 조합을 어떻게 나눌 것인가
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

long long solution(string expression) {
	long long answer = 0;
	char op[3] = { '+','-','*' };
	sort(op, op + 3);
	long long now = 0;
	vector<long long> nums;
	vector<long long> newnums; // 임시
	vector<char> ops;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] >= '0') {
			// now의 기존 수를 쉬프트하고 마지막 자리에 삽입
			now *= 10;
			now += expression[i] - '0';
		}
		else { // 연산기호가 나오면 nums에 세자리 수 삽입
			nums.push_back(now);
			now = 0;
			ops.push_back(expression[i]); // ops에 연산자 삽입
		}
	}
	nums.push_back(now); // 마지막 세자리수는 연산기호가 안나오니 따로 처리
	vector<bool> check; 
	int nsize = (int)nums.size();
	// 벡터 사이즈를 최종 입력된 nums에 맞춤 
	check.resize(nsize, false);
	newnums.resize(nsize);
	do {
		memset(&check, 0, nsize);
		newnums.assign(nums.begin(), nums.end()); // nums를 newnums에 복사
		for (int i = 0; i < 3; i++) { // 연산자 종류(순열, + - *)
			for (int j = 0; j < ops.size(); j++) { // 입력된 연산자 개수
				if (ops[j] == op[i]) {
					for(int k = j; k >= 0; k--){
						if (!check[k]) break;
					}
					for (int t = j + 1; t < nums.size(); t++) {
						if (!check[t]) break;
					}
				}
			}
		}

	}
}