#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;


bool key[26];//a~z exist?
//bool door[26]; //doors that i can aproach at the moment
char building[105][105];
vector<pair<int, int>> lockpos[26]; //position od the door-> have only the pos that I can approach RIGHT AWAY
queue<pair<int, int>> qu;
bool chkArr[105][105];
int CNT = 0;
int H, W;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void BFS() {
    while (!qu.empty()) {
        pair<int, int> pos = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if (nx<0 || ny<0 || nx> H + 1 || ny > W + 1) continue;
            if (building[nx][ny] == '*') continue;
            if (building[nx][ny] == '$' && !chkArr[nx][ny]) {
                //GO! & cnt++
                CNT++;
                building[nx][ny] = '.';
            }
            if (building[nx][ny] == '.' && !chkArr[nx][ny]) {
                //GO!
                qu.push({ nx,ny });
                chkArr[nx][ny] = true;
            }
            if (building[nx][ny] > 96 && building[nx][ny] < 123 && !chkArr[nx][ny]) {
                //처음보는 열쇠 있는자리!
                //소문자(겉면에)
                qu.push({ nx,ny });
                chkArr[nx][ny] = true;
                key[building[nx][ny] - 97] = true;
                building[nx][ny] = '.';

                //문 먼저 발견하고 이후에 그에 해당하는 키 찾ㅇ느 경우?
                for (int k = 0; k < lockpos[building[nx][ny] - 97].size(); k++) {
                    if (!chkArr[lockpos[building[nx][ny] - 97][k].first][lockpos[building[nx][ny] - 97][k].second]) {
                        qu.push(lockpos[building[nx][ny] - 97][k]);
                        chkArr[lockpos[building[nx][ny] - 97][k].first][lockpos[building[nx][ny] - 97][k].second] = true;
                        building[nx][ny] = '.';
                    }
                }
                lockpos[building[nx][ny] - 97].clear();

            }
            if (building[nx][ny] > 64 && building[nx][ny] < 91 && !chkArr[nx][ny]) {
                //아직 열리지 않은 문!
                if (key[building[nx][ny] - 65]) {
                    //ther IS a key to the door
                    qu.push({ nx,ny });
                    chkArr[nx][ny] = true;
                    building[nx][ny] = '.';
                }
                else {
                    //No key
                    lockpos[building[nx][ny] - 65].push_back({ nx,ny });
                }
            }

        }



    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        memset(building, '.', sizeof(building));
        string keys;
        cin >> H >> W;

        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                cin >> building[i][j];
            }
        }
        cin >> keys;
        if (keys != "0") {
            for (int i = 0; i < keys.length(); i++) {
                key[keys[i] - 97] = true;
            }
        }
        //####END OF INPUT####

        //
        qu.push({ 0,0 });
        BFS(); //탐색!

        cout << CNT << "\n";
        memset(chkArr, false, sizeof(chkArr));
        CNT = 0;
        memset(key, false, sizeof(key));

        for (int i = 0; i < 26; i++) {
            lockpos[i].clear();
        }
    }

    return 0;
}