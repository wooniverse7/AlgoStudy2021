// 백준 9375 패션왕 신해빈을 풀면서
// https://yonmy.com/archives/9
// https://hack-gogumang.tistory.com/360

#include <iostream>
#include <map>

using namespace std;

int main() {

    map <string, int> m;
    pair<map<string, int>::iterator, bool > pr;

    pr = m.insert(pair<string, int>("abc", 1));
    // map에 insert할 때 리턴값으로 pair값을 돌려줌. 
    // 성공 : < insert된 elem의 iter, true >, 중복된 key가 존재하지 않을 때
    // 실패 : < 중복된 elem의 iter, flase >, 중복된 key가 존재할 때

    cout << pr.second << '\n';
    // cout << pr.first << '\n'; // 반복자라 출력 X

    pr = m.insert({ "mango", 0 });
    cout << pr.second << '\n'; // 1, 삽입이 성공됐다는 것을 출력
    cout << pr.first->second << '\n'; // 말그대로 map에 삽입 된 0을 출력. first(첫번 째)는 pair의 iterator 
    cout << pr.first->first << '\n'; // mango. pair의 iter가 가르키는 map의 first(두번 째)

    // map의 key값에 후위연산자를 붙이면 key에 해당하는 int값이 변화된다.
    m["mango"]++;
    cout << m["mango"] << endl;
    m["mango"]++;
    cout << m["mango"] << endl;

}