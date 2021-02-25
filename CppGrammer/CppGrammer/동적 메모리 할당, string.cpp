#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {
	// string 내의 단어 캡쳐하기
	string str = "hi, Inha Univ.";
	string capture = str.substr(4, 4);
	cout << capture << endl; // Inha

	char cstyle[3];
	string cppstyle;

	// 띄어쓰기까지 받을 수 있게. 구분자는 엔터
	cin.getline(cstyle, 3); // cin객체의 멤버 메소드(함수)
	cin.clear(); // 위 입력에서 발생할 수 있는 에러를 처리해 다음 입력을 받게 해줌.
	getline(cin, cppstyle); // 일반함수(string에 속함)


} 