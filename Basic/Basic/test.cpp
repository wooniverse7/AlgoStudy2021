#include<iostream>
#include<string>
using namespace std;

int main() {
	int a = 12345;
	string st = to_string(a);
	cout << st.length();
}