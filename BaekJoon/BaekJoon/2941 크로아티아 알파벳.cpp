#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> croatian = { "dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
int idx;

int main() {
	string abc;
	cin >> abc;

	for (int i = 0; i < croatian.size(); i++) {
		while (1) {
			idx = abc.find(croatian[i]); // find�Լ��� ������ ������ Ž���Ѵ�. ������ �ش� ���ڿ��� ó�� ���� idx��ȯ
			if (idx == string::npos) // ���̻� ���� ��� 0�� ��ȯ�ؼ� Ż��
				break;
			abc.replace(idx, croatian[i].length(), "#"); 
		}
	}

	//cout << abc << '\n';
	cout << abc.size() << '\n';

}