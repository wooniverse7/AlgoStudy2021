#include<iostream>
using namespace std;

typedef int Elem; // 이식성, 수정효율성을 위해
class ArrayVector {
public:
	// 복사 생성자, 할당 연산자, 소멸자 구현
	ArrayVector(); // 생성자
	ArrayVector(const ArrayVector& v); // * 복사 생성자
	~ArrayVector(); // * 소멸자
	int size() const; // num of data
	bool empty() const; // is empty
	Elem& operator[](int i); // 인덱스에 있는 원소 참조
	Elem& at(int i);
	void erase(int i);
	void insert(int i, const Elem& e);
	void reserve(int N); // N개의 size 확보

private: // 멤버 데이터
	int capacity; // size of array
	int n; // num of data in vector
	Elem* A; // 원소를 저장하는 배열
};

// 기본 생성자 ( 원소를 추가하면 배열이 할당)
ArrayVector::ArrayVector()
	:capacity(0), n(0), A(NULL) {};
// *복사 생성자. 맞는지 확인. 어떻게
ArrayVector::ArrayVector(const ArrayVector& v)
	:capacity(v.capacity), n(v.n), A(v.A) {};
ArrayVector::~ArrayVector() 
{ if (A != NULL)	delete[] A; };

// 원소 개수 ( 변경 X )
int ArrayVector::size() const { return n; }

// is this array empty?
bool ArrayVector::empty() const
{ return size() == 0; }

// 인덱스 연산자 오버로딩 - 경계검사 수행?
Elem& ArrayVector::operator[](int i)
{ return A[i]; }

// 인덱스 원소 (안전)
Elem& ArrayVector::at(int i)
{
	if (i < 0 || i >= n)
		throw ("범위 밖의 원소입니다.");
	return A[i];
}

// 원소 삭제 ( i+1번째 원소부터 마지막 원소까지 한 칸씩 앞으로 )
void ArrayVector::erase(int i) {
	for (int j = i + 1; j < n; j++)
		A[j - 1] = A[j]; // i+1 부터 한 칸 앞으로 복사
	n--; // 원소 개수 감소
}

// N만큼 배열 크기 확장 ( insert시 사용 )
void ArrayVector::reserve(int N) {
	if (capacity >= N) return; // 공간이 남으면 그냥 리턴
	Elem* B = new Elem[N]; // 크기 N의 포인터 배열 동적 할당
	for (int j = 0; j < n; j++)
		B[j] = A[j]; // 새로운 배열에 복사
	if (A != NULL) delete[] A; // 기존 배열 삭제
	A = B; // B를 다시 새로운 A로 만듬
	capacity = N;
}

// index i에 e 원소 삽입
void ArrayVector::insert(int i, const Elem& e) {
	if (n >= capacity) // 오버플로우 확인
		reserve(max(1, 2 * capacity)); // 1과 2배중 큰 값으로(처음 삽입시 1)
	for (int j = n - 1; j >= i; j--) // i부터 n-1까지 한 칸씩 뒤로 이동
		A[j + i] = A[j];
	A[i] = e;
	n++; // 원소 개수 증가
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