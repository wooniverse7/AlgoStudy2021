#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string word;
int n[27];
int m[27];
string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {

	cin >> word;

	for (int i = 0; i < word.size(); i++) {
		if (word[i] >= 'a') {
			n[word[i] - 'a']++;
		}
		else {
			n[word[i] - 'A']++;
		}
	}

	for (int i = 0; i < 28; i++) {
		m[i] = n[i];
	}

	sort(n, n + 27, greater<int>());

	if (n[0] == n[1])
		cout << "?";
	else {
		for (int i = 0; i < 28; i++) {
			if (n[0] == m[i])
				cout << ABC[i];
		}
	}
}