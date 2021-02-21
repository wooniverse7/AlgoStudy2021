#include<iostream>
using namespace std;

int first; // 처음값
int A;
int B; // A 10의 자리 + 1의 자리
int newA = 123; // A오른쪽 자리 * 10 + B 오른쪽 자리. 
				//0이면 바로 빠져나오기 때문에 100이상의 수로 초기화.
int cycle = 0;

int main() {

	cin >> first; // 26
	A = first;
	while (first != newA) {
		B = A / 10 + A % 10; // 08
		newA = (A % 10) * 10 + B % 10; // 68
		A = newA;

		cycle++;
	}

	cout << cycle;
}