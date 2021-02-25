// ���� 9375 �мǿ� ���غ��� Ǯ�鼭
// https://yonmy.com/archives/9
// https://hack-gogumang.tistory.com/360

#include <iostream>
#include <map>

using namespace std;

int main() {

    map <string, int> m;
    pair<map<string, int>::iterator, bool > pr;

    pr = m.insert(pair<string, int>("abc", 1));
    // map�� insert�� �� ���ϰ����� pair���� ������. 
    // ���� : < insert�� elem�� iter, true >, �ߺ��� key�� �������� ���� ��
    // ���� : < �ߺ��� elem�� iter, flase >, �ߺ��� key�� ������ ��

    cout << pr.second << '\n';
    // cout << pr.first << '\n'; // �ݺ��ڶ� ��� X

    pr = m.insert({ "mango", 0 });
    cout << pr.second << '\n'; // 1, ������ �����ƴٴ� ���� ���
    cout << pr.first->second << '\n'; // ���״�� map�� ���� �� 0�� ���. first(ù�� °)�� pair�� iterator 
    cout << pr.first->first << '\n'; // mango. pair�� iter�� ����Ű�� map�� first(�ι� °)

    // map�� key���� ���������ڸ� ���̸� key�� �ش��ϴ� int���� ��ȭ�ȴ�.
    m["mango"]++;
    cout << m["mango"] << endl;
    m["mango"]++;
    cout << m["mango"] << endl;

}