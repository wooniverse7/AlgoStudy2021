// ���� ��ȣ�� ���� ���� ������ ���͸� ����
// ���ڿ��� ���� ���� �� ������ �켱���� ������ ��� ���� ���ΰ�
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
	vector<long long> newnums; // �ӽ�
	vector<char> ops;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] >= '0') {
			// now�� ���� ���� ����Ʈ�ϰ� ������ �ڸ��� ����
			now *= 10;
			now += expression[i] - '0';
		}
		else { // �����ȣ�� ������ nums�� ���ڸ� �� ����
			nums.push_back(now);
			now = 0;
			ops.push_back(expression[i]); // ops�� ������ ����
		}
	}
	nums.push_back(now); // ������ ���ڸ����� �����ȣ�� �ȳ����� ���� ó��
	vector<bool> check; 
	int nsize = (int)nums.size();
	// ���� ����� ���� �Էµ� nums�� ���� 
	check.resize(nsize, false);
	newnums.resize(nsize);
	do {
		memset(&check, 0, nsize);
		newnums.assign(nums.begin(), nums.end()); // nums�� newnums�� ����
		for (int i = 0; i < 3; i++) { // ������ ����(����, + - *)
			for (int j = 0; j < ops.size(); j++) { // �Էµ� ������ ����
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