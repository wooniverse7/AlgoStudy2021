#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std;
#define MOD 100009

// ���
typedef struct node {
	char str[10]; // �̸��� ��� �迭
	node* next;
	node* prev;
	node() { next = prev = NULL; } // ������ �ʱⰪ
	node(char* s) { // �Ű����� ������
		next = prev = NULL;
		int i;
		for (i = 0; s[i]; i++) // for��( ����/���ǹ�/������ ) ����
							// ����� ���ǹ��̱� ������ 0�� �Ǹ� ����. �� 0�� �� �� ����.
			str[i] = s[i];
		str[i] = 0;
	}
};

// �迭
typedef struct list {
	node* begin;
	node* end;
	list()
	{
		begin = end = NULL;
	}
};

// �ؽ�
typedef struct myhash {
	list h[MOD]; // �ؽ� �迭 ����
	int gethash(char* s) {
		int re = 0, k = 1;
		for (int i = 0; s[i]; i++) {
			re = (re + s[i] * k) % MOD;
			k = (k * 17) % MOD;
		}
		return re;
	}
	void insert(char* s) {
		int v = gethash(s);
		node* i = h[v].begin;
		node* newnode = new node(s);
		if (i == NULL) {
			h[v].begin = h[v].end = newnode;
		}
		else {
			while (i) {
				if (getcmp(i->str, s)) {
					delete newnode;
					return;
				}
			}
		}
	}
	bool getcmp(char* a, char* b) {
		for (int i = 0; a[i] || b[i]; i++) // ����� ���ǹ�. �� �� �ϳ��� 0���� ū ������ �����(�� �� 0�� �Ǿ�� ����)
			if (a[i] != b[i]) return false;
		return true;
	}
	void remove(char* s) {
		int v = gethash(s);
		node* i = h[v].begin;
		while (i) {
			if (getcmp(s, i->str)) {
				if (i == h[v].begin) {
					if (i->next == NULL) {
						h[v].begin = h[v].end = NULL;
					}
					else {
						h[v].begin = h[v].begin->next;
					}
				}
				else if (i == h[v].end) {
					h[v].end = h[v].end->prev;
					h[v].end->next = NULL;
				}
				else {
					i->next->prev = i->prev;
					i->prev->next = i->next;
				}
				delete i;
				return;
			}
			i = i->next;
		}
	}
};

int main() {
	myhash _hash;
	vector<string> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char name[10], mode[10]; // �̸�, ��/��
		cin >> name >> mode;
		if (mode[0] == 'e')
			_hash.insert(name);
		else
			_hash.remove(name);
	}
	for (int i = 0; i < MOD; i++) {
		node* tmp = _hash.h[i].begin;
		while (tmp) {
			s.push_back(tmp->str);
			tmp = tmp->next;
		}
	}
	sort(s.begin(), s.end(), greater<string>());
	
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << '\n';

	return 0;
}