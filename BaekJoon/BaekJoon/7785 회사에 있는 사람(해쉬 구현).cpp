#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std;
#define MOD 100009

// 노드
typedef struct node {
	char str[10]; // 이름을 담는 배열
	node* next;
	node* prev;
	node() { next = prev = NULL; } // 생성자 초기값
	node(char* s) { // 매개변수 생성자
		next = prev = NULL;
		int i;
		for (i = 0; s[i]; i++) // for문( 선언문/조건문/증가문 ) 구조
							// 가운데는 조건문이기 때문에 0이 되면 끝남. 즉 0이 될 떄 까지.
			str[i] = s[i];
		str[i] = 0;
	}
};

// 배열
typedef struct list {
	node* begin;
	node* end;
	list()
	{
		begin = end = NULL;
	}
};

// 해쉬
typedef struct myhash {
	list h[MOD]; // 해쉬 배열 생성
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
		for (int i = 0; a[i] || b[i]; i++) // 가운데는 조건문. 둘 중 하나만 0보다 큰 값으면 진행됨(둘 다 0이 되어야 종료)
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
		char name[10], mode[10]; // 이름, 출/퇴
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