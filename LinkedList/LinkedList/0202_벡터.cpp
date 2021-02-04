#include<iostream>
using namespace std;

typedef int Elem; // �̽ļ�, ����ȿ������ ����
class ArrayVector {
public:
	// ���� ������, �Ҵ� ������, �Ҹ��� ����
	ArrayVector(); // ������
	ArrayVector(const ArrayVector& v); // * ���� ������
	~ArrayVector(); // * �Ҹ���
	int size() const; // num of data
	bool empty() const; // is empty
	Elem& operator[](int i); // �ε����� �ִ� ���� ����
	Elem& at(int i);
	void erase(int i);
	void insert(int i, const Elem& e);
	void reserve(int N); // N���� size Ȯ��

private: // ��� ������
	int capacity; // size of array
	int n; // num of data in vector
	Elem* A; // ���Ҹ� �����ϴ� �迭
};

// �⺻ ������ ( ���Ҹ� �߰��ϸ� �迭�� �Ҵ�)
ArrayVector::ArrayVector()
	:capacity(0), n(0), A(NULL) {};
// *���� ������. �´��� Ȯ��. ���
ArrayVector::ArrayVector(const ArrayVector& v)
	:capacity(v.capacity), n(v.n), A(v.A) {};
ArrayVector::~ArrayVector() 
{ if (A != NULL)	delete[] A; };

// ���� ���� ( ���� X )
int ArrayVector::size() const { return n; }

// is this array empty?
bool ArrayVector::empty() const
{ return size() == 0; }

// �ε��� ������ �����ε� - ���˻� ����?
Elem& ArrayVector::operator[](int i)
{ return A[i]; }

// �ε��� ���� (����)
Elem& ArrayVector::at(int i)
{
	if (i < 0 || i >= n)
		throw ("���� ���� �����Դϴ�.");
	return A[i];
}

// ���� ���� ( i+1��° ���Һ��� ������ ���ұ��� �� ĭ�� ������ )
void ArrayVector::erase(int i) {
	for (int j = i + 1; j < n; j++)
		A[j - 1] = A[j]; // i+1 ���� �� ĭ ������ ����
	n--; // ���� ���� ����
}

// N��ŭ �迭 ũ�� Ȯ�� ( insert�� ��� )
void ArrayVector::reserve(int N) {
	if (capacity >= N) return; // ������ ������ �׳� ����
	Elem* B = new Elem[N]; // ũ�� N�� ������ �迭 ���� �Ҵ�
	for (int j = 0; j < n; j++)
		B[j] = A[j]; // ���ο� �迭�� ����
	if (A != NULL) delete[] A; // ���� �迭 ����
	A = B; // B�� �ٽ� ���ο� A�� ����
	capacity = N;
}

// index i�� e ���� ����
void ArrayVector::insert(int i, const Elem& e) {
	if (n >= capacity) // �����÷ο� Ȯ��
		reserve(max(1, 2 * capacity)); // 1�� 2���� ū ������(ó�� ���Խ� 1)
	for (int j = n - 1; j >= i; j--) // i���� n-1���� �� ĭ�� �ڷ� �̵�
		A[j + i] = A[j];
	A[i] = e;
	n++; // ���� ���� ����
}

int main() {
	ArrayVector v;
	v.insert(0, 1);
	v.insert(1, 2);
	v.insert(2, 3);
	v.insert(1, 5);
	cout << v.size() << endl;
	cout << v.at(1) << endl;
	v.erase(1);
	cout << v.size() << endl;
	cout << v.at(1) << endl;

}