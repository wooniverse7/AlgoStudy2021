#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {
	// string ���� �ܾ� ĸ���ϱ�
	string str = "hi, Inha Univ.";
	string capture = str.substr(4, 4);
	cout << capture << endl; // Inha

	char cstyle[3];
	string cppstyle;

	// ������� ���� �� �ְ�. �����ڴ� ����
	cin.getline(cstyle, 3); // cin��ü�� ��� �޼ҵ�(�Լ�)
	cin.clear(); // �� �Է¿��� �߻��� �� �ִ� ������ ó���� ���� �Է��� �ް� ����.
	getline(cin, cppstyle); // �Ϲ��Լ�(string�� ����)


} 