#include<iostream>
using namespace std;

int main() {
	int a = 10;
	int* ap = &a;
	int b = a; // 그저 값만 복사

	b = 5; //
	cout << a << endl;
}