//Map container ����

// Ű�� ���� ������ ���� ����ü
#include<iostream>
#include<map>

template<typename K, typename V>
class Entry { // (Ű, ��) ��
publid:
	Entry(const K& k = K(), const V& v = V())
		: _key(k), _value(v) {}
	const K& key() const { return _key; } // Ű�� ��ȯ
	const V& value() const { return _value; } // �� ��ȯ
	void setKey(const K& k) { _key = k; } // Ű ����
	void setValue(const V& v) { _value = v; } // �� ����
private:
	K _key;   // Ű
	V _value; // ��
};

// Map container
template<typename K, typename V>
class Map {
public:
	class Entry;
	class Iterator;

	int size
};