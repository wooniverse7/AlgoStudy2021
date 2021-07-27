#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;


string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lf = 10, rt = 12; // *과 #의 키패드 위치
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0) numbers[i] = 11; // 거리 계산을 위해
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            lf = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            rt = numbers[i];
        }
        else {
            //원리가 뭐지
            int lf_dist = abs(lf - numbers[i]);
            int rt_dist = abs(rt - numbers[i]);

            // 키패드 거리 차이를 수의 차이에서 3으로 나눈 몫은 열의 차이, 3으로 나눈 나머지는 행의 차이를 더해서 구함
            // 열의 개수가 3개라서 row값이 1증가할 때마다, 키패드의 값은 3씩 증가.
            // 따라서 누른 키패드의 번호/3이 해당 키패드의 row 값이 된다는 것을 알 수 있다.
            // 3, 6, 9일 경우 몫이 1, 2, 3이긴 하지만 그 경우는 무조건 오른손이라서 예외 처리를 따로 안해줘도 되는듯
            int lf_cnt = lf_dist / 3 + lf_dist % 3; // '/'는 행, '%'는 열
            int rt_cnt = rt_dist / 3 + rt_dist % 3;

            if (lf_cnt < rt_cnt) {//왼쪽 거리가 더 짧으면
                lf = numbers[i];
                answer += 'L';
            }
            else if (lf_cnt > rt_cnt) {
                rt = numbers[i];
                answer += 'R';
            }
            else {
                if (hand == "left") {
                    lf = numbers[i];
                    answer += 'L';
                }
                else {
                    rt = numbers[i];
                    answer += 'R';
                }
            }
        }
    }
    return answer;
}