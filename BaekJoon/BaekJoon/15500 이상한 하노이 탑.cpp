#include <iostream>
#include <stack>
#include <vector>
#include <bitset>
using namespace std;

stack<int> l1, l2;
bitset<12346> b1, b2;
vector<string> answer;
int cnt;
int N;

void find(int i) {
    int move;
    switch (i) {
    case 1:
        while ((move = l1.top()) < N)
        {
            l1.pop();
            l2.push(move);
            b1.reset(move);
            b2.set(move);
            answer.push_back("1 2\n");
            cnt++;
        }
        l1.pop();
        b1.reset(move);
        N--;
        answer.push_back("1 3\n");
        cnt++;
        break;
    case 2:
        while ((move = l2.top()) < N)
        {
            l2.pop();
            l1.push(move);
            b1.set(move);
            b2.reset(move);
            answer.push_back("2 1\n");
            cnt++;
        }
        l2.pop();
        b2.reset(move);
        N--;
        answer.push_back("2 3\n");
        cnt++;
        break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        l1.push(n);
        b1.set(n);
    }
    while (N > 0)
        if (b1[N])
            find(1);
        else if (b2[N])
            find(2);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        cout << answer[i];
}