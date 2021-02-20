//Map container 구현

// 키와 값을 쌍으로 갖는 구조체
#include<iostream>
#include<map>

template<typename K, typename V>
class Entry { // (키, 값) 쌍
publid:
	Entry(const K& k = K(), const V& v = V())
		: _key(k), _value(v) {}
	const K& key() const { return _key; } // 키를 반환
	const V& value() const { return _value; } // 값 반환
	void setKey(const K& k) { _key = k; } // 키 수정
	void setValue(const V& v) { _value = v; } // 값 수정
private:
	K _key;   // 키
	V _value; // 값
};

// Map container
template<typename K, typename V>
class Map {
public:
	class Entry;
	class Iterator;

	int size
};