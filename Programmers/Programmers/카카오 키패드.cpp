#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;


string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lf = 10, rt = 12; // *�� #�� Ű�е� ��ġ
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0) numbers[i] = 11; // �Ÿ� ����� ����
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            lf = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            rt = numbers[i];
        }
        else {
            //������ ����
            int lf_dist = abs(lf - numbers[i]);
            int rt_dist = abs(rt - numbers[i]);

            // Ű�е� �Ÿ� ���̸� ���� ���̿��� 3���� ���� ���� ���� ����, 3���� ���� �������� ���� ���̸� ���ؼ� ����
            // ���� ������ 3���� row���� 1������ ������, Ű�е��� ���� 3�� ����.
            // ���� ���� Ű�е��� ��ȣ/3�� �ش� Ű�е��� row ���� �ȴٴ� ���� �� �� �ִ�.
            // 3, 6, 9�� ��� ���� 1, 2, 3�̱� ������ �� ���� ������ �������̶� ���� ó���� ���� �����൵ �Ǵµ�
            int lf_cnt = lf_dist / 3 + lf_dist % 3; // '/'�� ��, '%'�� ��
            int rt_cnt = rt_dist / 3 + rt_dist % 3;

            if (lf_cnt < rt_cnt) {//���� �Ÿ��� �� ª����
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