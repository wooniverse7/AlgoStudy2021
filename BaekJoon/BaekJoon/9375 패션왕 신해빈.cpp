#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {

	int T, N; // �׽�Ʈ��, �ǻ��
	int rst; // ���
	string clth, key;

	map<string, int> mp; // < �ǻ� ����, �ش��ϴ� �ǻ� �� >
	pair<map<string, int>::iterator, bool> ck; // �̹� �ִ���

	cin >> T;
	while (T--) {
		mp.clear();
		rst = 1;
		cin >> N;
		while (N--) {
			cin >> clth >> key;
			//ck = mp.insert(pair<string, int>(key, 1)); 
			//// map�� �̹� key�� ������ (�ߺ�key�� iter, false=0), ������ (insert�� key�� iter, true=1)�� ����
			//if (!ck.second) // ck�� false�̸� �̹� �ߺ��� key�� �ִ�
			//	mp[key]++; // �ش� key�� int���� +1���ش�
			// �ߺ�Ű Ȯ�� �ʿ� X
			mp[key] += 1;
		}
		for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
			rst = rst * (iter->second + 1); // iter�� ����Ű�� map�� snd��(int), ���°�� 1 �߰�
		}
		cout << rst - 1 << '\n'; // ��δ� ���� ��� -1
	}

}


//pr = m.insert(pair <string, int>(key, 1));
// map�� insert�� �� ���ϰ����� pair���� ������. 
// ���� : < insert�� elem�� iter, true >, �ߺ��� key�� �������� ���� ��
// ���� : < �ߺ��� elem�� iter, flase >, �ߺ��� key�� ������ ��