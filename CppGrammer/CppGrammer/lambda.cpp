#include<iostream>
#include<functional>
using namespace std;

// �͸��Լ��̴�. �Լ���ü�� ����
// �Լ� �����Ϳ� �Լ���ü�� ������ ����
// ĸ�� ����� ���� �Լ� ���� ������ ������ �� �ִ�.
// & ��ȣ�� ���� �����Լ� �ȿ����� �ܺ� ������ ���� ���氡��(����)
// ��� ȣ�⵵ �����ϴ�.

int main() {
	// lambda Expression
	// [ĸ�ĺ�] (�Ű���������Ʈ)->����Ÿ��{�Լ��ٵ�}; // �͸� �Լ�

	[]()->void {};
	
	//�Ű����� ����Ʈ, ��ȣ, ���� Ÿ�� ��������
	[] {};

	[] {cout << "hi lambda" << endl; }; // ����� �ȵ�
	[] {cout << "hi lambda1" << endl; }(); // �ǳ� �Ұ�ȣ : ���� ǥ������ ��� ������Ѷ�

	// ������ ��Ƽ� ��� ����
	auto inha = [] {cout << "hi lambda2" << endl; };
	inha();

	// �� ���� ���� ���� ���
	auto sum = []() {return 5 + 10; };
	cout << sum() << endl;

	// ���� �����༭ �����ϴ� �Լ�
	auto inha1 = [](int a, int b) {return a + b; };
	cout << inha1(0, 1) << endl;

	// ȭ��ǥ�� �Ἥ. ����Ÿ�� ����ߵ�
	auto inha2 = [](int a, int b)-> int {return a + b; };
	cout << inha2(1, 1) << endl;

	// �Ű������� �ٷ� �����ֱ�
	auto inha3 = [](int a, int b)-> int {return a + b; }(1,2);
	cout << inha3 << endl;

	// �Ű����� Ÿ���� �޶� ĳ������ �ʿ��� ���. return Ÿ�Կ� ���� ���Ÿ�� ����.
	auto inha4 = [](float a, int b)-> int {return a + b; }; 
	cout << inha4(2.7f, 2) << endl; // 6
	// ������ float�� �ϸ� 6.5. ������ ū Ÿ������

	// [ĸ�ĺ�] : �����Լ� �ۿ��� �����ҷ��� ���� ����. ���⼭ ĸ���� ������ ���� �Լ� ������ ���� ����
	int a = 2, b = 3;
	auto inha5 = [a, b](float c, int d)-> int {
		return a + b + c + d; 
	};
	cout << inha5(3.5f, 2) << endl;

	// & ���ۻ��� ��ȣ�� �ٱ��� ������ �ٲ�
	int a1 = 1, b1 = 2;
	auto inha6 = [&a1, b1](float c, int d)-> int {
		a1 = 4;
		return a1 + b1 + c + d;
	};
	cout << "inha6 : " << inha6(3.5f, 4) << endl; // �Լ��� �۵����� ������ ���� �ٲ��� ����
	cout << a1 << endl;

	// & ���ۻ��� ��ȣ�� �ٱ��� "���" ������ ����(�ٲ� �� �ִ�)
	// [=] �� �ϸ� ��ü ������ ������ �ƴ� ��븸 ����
	int a2 = 1, b2 = 2;
	auto inha7 = [&](float c, int d)-> int {
		a2 = 4;
		b2 = -4;
		return a2 + b2 + c + d;
	};
	cout << "inha7 : " << inha7(3.5f, 4) << endl; // �Լ��� �۵����� ������ ���� �ٲ��� ����
	cout << "inha7 : " << typeid(inha).name() << endl; 
	cout << a2 << endl;

	// �Ʒ��� ���� ������ ���� ����. ���� �͸��Լ��� �ּҸ� ������ �ִ�(int �Ϲ� ������ �ƴ� ��ü).
	auto inha8 = [&](float c, int d)-> int {
		return a2 + b2 + c + d;
	}(1.9f, 2);
	cout << "inha8 : " << inha8 << endl; // �Լ��� �۵����� ������ ���� �ٲ��� ����
	cout << "inha8 : " << typeid(inha8).name() << endl;

	// ���ٿ��� ��͸� ���� �� �� autoŸ�����δ� �߷� �Ұ�. 
	// �ݵ�� �����Ϸ��� �ϴ� �Լ��� Ÿ���� ��õǾ�� �Ѵ�.
	// �ڽ��� ȣ���ϱ� ���� �ڽ��� ĸ��, functional stl�� �ʿ��ϴ�.
	// �ڱ��ڽ��� ȣ���ϱ� ���� ĸ�Ŀ� �ڽ��� �ְ�, ĸ�Ŀ� �ڽ��� �������� function ������ �ʿ�
	function<int(int)> fact = [&fact](int n) -> int {
		return n <= 1 ? 1 : n * fact(n - 1);
		//if (n <= 1)
		//	return 1;
		//else
		//	return n * fact(n - 1);
	};
	cout << "fact : " << fact(6) << endl;
	
}