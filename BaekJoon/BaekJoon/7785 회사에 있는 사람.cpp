//#include<iostream>
//#include<string>
//#include<map>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//
//	int n;
//	map<string, bool> mp;
//	vector<string> v;
//
//	cin >> n;
//	while (n--) {
//		string name, cmd;
//		cin >> name >> cmd;
//		if (mp.find(name) != mp.end()) // �ʿ� �̹� ���� ��
//		{
//			if (cmd == "enter") {
//				mp[name] = true; // name�� �ش��ϴ� value�� true�� ����
//			}
//			else {
//				mp[name] = false;
//			}
//
//			continue; // if�� �ȿ� �ִ��� �ٷ� ���� while������ ���ư�. �ݺ����� ������ �۵�. �Ʒ� �ڵ� ����
//		}
//
//		// ������ �׳� ����
//		v.push_back(name);
//		mp[name] = true;
//	}
//
//	sort(v.begin(), v.end(), greater<string>()); // ��������
//
//	for (int i = 0; i < v.size(); i++) {
//		if (mp[v[i]] == true) { // vector v���� �� �̸��� �ش��ϴ� map mp�� value�� true�̸�
//			cout << v[i] << '\n';
//		}
//	}
//	
//}

#include<iostream>
#include<set>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	set<string, greater<string>> comp;
	int n;
	cin >> n;
	while (n--) {
		string name, cmd;
		cin >> name >> cmd;
		if (cmd == "enter")
			comp.insert(name);
		else
			comp.erase(name);
	}
	
	for (auto& it : comp)
		cout << it << '\n';
}