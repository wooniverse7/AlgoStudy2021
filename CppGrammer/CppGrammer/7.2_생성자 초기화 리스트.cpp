// Git Ȯ��
#include<iostream>
using namespace std;

class NeedConstructor {
public:
	// ���� : class���� const ������ &������ �ʱ�ȭ ����Ʈ�� �̿��� �ʱ�ȭ���־�� �Ѵ�.
	const int max;
	int& ref;
	int temp;

	NeedConstructor();
	NeedConstructor(int cnt, int& number);
};

NeedConstructor::NeedConstructor() 
	: max(100), ref(temp){
	temp = 10;
	//max = 100; // �����ڰ� ������ �Ĵ� const�� ���� �Ұ�
	//ref temp; // ���� �� �ʱ�ȭ �ʿ�
	// �ʱ�ȭ ����Ʈ�� �������� �̸� ��������.
}
NeedConstructor::NeedConstructor(int cnt, int& number)
	: max(cnt), ref(number) { // const������ ���۷��� ������ ���� ������
	temp = 10;
	
}

int main() {
	NeedConstructor cr;

	//cr.max = 1000; // const���� �̹� �����Ŀ��� ���� �Ұ�.
	//cr.ref = cr.temp;
	cout << cr.max << endl;
	cout << cr.ref << endl;

	int num = 400;
	NeedConstructor cr1(500, num); // ���۷��� ������ ������ ���� �� �ִ�.
	cout << cr1.max << endl;
	cout << cr1.ref << endl;
}