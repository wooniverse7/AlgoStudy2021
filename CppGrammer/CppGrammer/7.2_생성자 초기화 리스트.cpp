// Git 확인
#include<iostream>
using namespace std;

class NeedConstructor {
public:
	// 주의 : class내의 const 변수나 &변수는 초기화 리스트를 이용해 초기화해주어야 한다.
	const int max;
	int& ref;
	int temp;

	NeedConstructor();
	NeedConstructor(int cnt, int& number);
};

NeedConstructor::NeedConstructor() 
	: max(100), ref(temp){
	temp = 10;
	//max = 100; // 생성자가 생성한 후는 const값 변경 불가
	//ref temp; // 선언 시 초기화 필요
	// 초기화 리스트로 생성전에 미리 정해주자.
}
NeedConstructor::NeedConstructor(int cnt, int& number)
	: max(cnt), ref(number) { // const변수와 레퍼런스 변수에 값을 던져줌
	temp = 10;
	
}

int main() {
	NeedConstructor cr;

	//cr.max = 1000; // const값은 이미 생성후에는 변경 불가.
	//cr.ref = cr.temp;
	cout << cr.max << endl;
	cout << cr.ref << endl;

	int num = 400;
	NeedConstructor cr1(500, num); // 레퍼런스 변수는 변수만 받을 수 있다.
	cout << cr1.max << endl;
	cout << cr1.ref << endl;
}