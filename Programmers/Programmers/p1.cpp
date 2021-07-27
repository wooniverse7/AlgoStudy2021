#include <string>
#include <vector>
#include<iostream>
using namespace std;


int solution(string s) {
    int answer = 0;
    int numSize = s.length();
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            answer *= 10;
            answer += s[i] - '0';
        }
        //zero
        if (s[i] == 'z') {
            answer *= 10;
            i += 3;
        }
        //one
        else if (s[i] == 'o') {
            answer *= 10;
            answer += 1;
            i += 2;
        }
        else if (s[i] == 't') {
            //two
            if (s[i + 1] == 'w') {
                answer *= 10;
                answer += 2;
                i += 2;
            }
            // three
            else {
                answer *= 10;
                answer += 3;
                i += 4;
            }
        }
        else if(s[i] == 'f')
            // four
            if (s[i + 1] == 'o') {
                answer *= 10;
                answer += 4;
                i += 3;
            }// five
            else {
                answer *= 10;
                answer += 5;
                i += 3;
            }
        else if (s[i] == 's')
            // six
            if (s[i + 1] == 'i') {
                answer *= 10;
                answer += 6;
                i += 2;
            }// seven
            else {
                answer *= 10;
                answer += 7;
                i += 4;
            }
        else if (s[i] == 'e') { // eight
            answer *= 10;
            answer += 8;
            i += 4;
        }
        else if (s[i] == 'n') { // nine
            answer *= 10;
            answer += 9;
            i += 3;
        }
    }

    return answer;
}

int main() {
    //string s1 = "one4seveneight";
    //string s2 = "23four5six7";
    //string s3 = "2three45sixseven";
    //string s4 = "123";
    //string s5 = "zeroonetwothreefourfivesizeseveneightnine0123456789";
    //cout << solution(s1) << '\n';
    //cout << solution(s2) << '\n';
    //cout << solution(s3) << '\n';
    //cout << solution(s4) << '\n';
    //cout << solution(s5) << '\n';
    //string s0 = "zero";
    //string s1 = "one";
    //string s2 = "two";
    //string s3 = "three";
    //string s4 = "four";
    //string s5 = "five";
    //string s6 = "six";
    //string s7 = "seven";
    //string s8 = "eight";
    //string s9 = "nine";
    string s0 = "onetwothreefourfivesixseveneightninezero";
    string s1 = "1";
    string s2 = "2";
    string s3 = "3";
    string s4 = "4";
    string s5 = "5";
    string s6 = "6";
    string s7 = "7";
    string s8 = "8";
    string s9 = "9";
    cout << solution(s0) << '\n';
    cout << solution(s1) << '\n';
    cout << solution(s2) << '\n';
    cout << solution(s3) << '\n';
    cout << solution(s4) << '\n';
    cout << solution(s5) << '\n';
    cout << solution(s6) << '\n';
    cout << solution(s7) << '\n';
    cout << solution(s8) << '\n';
    cout << solution(s9) << '\n';

}