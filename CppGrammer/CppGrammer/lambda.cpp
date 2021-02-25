#include<iostream>
#include<functional>
using namespace std;

// 익명함수이다. 함수객체를 생성
// 함수 포인터와 함수객체의 장점을 지님
// 캡쳐 기능을 통해 함수 밖의 변수에 접근할 수 있다.
// & 기호를 통해 람다함수 안에서도 외부 변수의 값을 변경가능(참조)
// 재귀 호출도 가능하다.

int main() {
	// lambda Expression
	// [캡쳐블럭] (매개변수리스트)->리턴타입{함수바디}; // 익명 함수

	[]()->void {};
	
	//매개변수 리스트, 기호, 리턴 타입 생략가능
	[] {};

	[] {cout << "hi lambda" << endl; }; // 출력은 안됨
	[] {cout << "hi lambda1" << endl; }(); // 맨끝 소괄호 : 람다 표현식을 즉시 실행시켜라

	// 변수에 담아서 출력 가능
	auto inha = [] {cout << "hi lambda2" << endl; };
	inha();

	// 두 수를 더한 값을 출력
	auto sum = []() {return 5 + 10; };
	cout << sum() << endl;

	// 값을 던져줘서 연산하는 함수
	auto inha1 = [](int a, int b) {return a + b; };
	cout << inha1(0, 1) << endl;

	// 화살표를 써서. 리턴타입 써줘야됨
	auto inha2 = [](int a, int b)-> int {return a + b; };
	cout << inha2(1, 1) << endl;

	// 매개변수를 바로 던져주기
	auto inha3 = [](int a, int b)-> int {return a + b; }(1,2);
	cout << inha3 << endl;

	// 매개변수 타입이 달라 캐스팅이 필요한 경우. return 타입에 따라 출력타입 결정.
	auto inha4 = [](float a, int b)-> int {return a + b; }; 
	cout << inha4(2.7f, 2) << endl; // 6
	// 리턴을 float로 하면 6.5. 없으면 큰 타입으로

	// [캡쳐블럭] : 람다함수 밖에서 참조할려는 변수 지정. 여기서 캡쳐한 변수는 람다 함수 내에서 접근 가능
	int a = 2, b = 3;
	auto inha5 = [a, b](float c, int d)-> int {
		return a + b + c + d; 
	};
	cout << inha5(3.5f, 2) << endl;

	// & 앤퍼샌드 기호로 바깥의 변수를 바꿈
	int a1 = 1, b1 = 2;
	auto inha6 = [&a1, b1](float c, int d)-> int {
		a1 = 4;
		return a1 + b1 + c + d;
	};
	cout << "inha6 : " << inha6(3.5f, 4) << endl; // 함수를 작동하지 않으면 값이 바뀌지 않음
	cout << a1 << endl;

	// & 앤퍼샌드 기호로 바깥의 "모든" 변수를 참조(바꿀 수 있다)
	// [=] 를 하면 전체 변수를 참조가 아닌 사용만 가능
	int a2 = 1, b2 = 2;
	auto inha7 = [&](float c, int d)-> int {
		a2 = 4;
		b2 = -4;
		return a2 + b2 + c + d;
	};
	cout << "inha7 : " << inha7(3.5f, 4) << endl; // 함수를 작동하지 않으면 값이 바뀌지 않음
	cout << "inha7 : " << typeid(inha).name() << endl; 
	cout << a2 << endl;

	// 아래는 값을 던져서 리턴 받음. 위는 익명함수의 주소만 가지고 있다(int 일반 변수가 아닌 객체).
	auto inha8 = [&](float c, int d)-> int {
		return a2 + b2 + c + d;
	}(1.9f, 2);
	cout << "inha8 : " << inha8 << endl; // 함수를 작동하지 않으면 값이 바뀌지 않음
	cout << "inha8 : " << typeid(inha8).name() << endl;

	// 람다에서 재귀를 구현 할 때 auto타입으로는 추론 불가. 
	// 반드시 대입하려고 하는 함수의 타입이 명시되어야 한다.
	// 자신을 호출하기 위해 자신을 캡쳐, functional stl이 필요하다.
	// 자기자신을 호출하기 위해 캡쳐에 자신을 넣고, 캡쳐에 자신을 쓰기위해 function 변수가 필요
	function<int(int)> fact = [&fact](int n) -> int {
		return n <= 1 ? 1 : n * fact(n - 1);
		//if (n <= 1)
		//	return 1;
		//else
		//	return n * fact(n - 1);
	};
	cout << "fact : " << fact(6) << endl;
	
}