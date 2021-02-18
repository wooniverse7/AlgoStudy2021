// Break를 지우고 다른 함수를 삽입해야됨
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

int N, Q;
int ice[66][66]; //64 * 64 is max
bool chk[66][66];
bool melt[66][66];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int lefticesum = 0;
int side;
int maxIce = 0;
void rotate(int level) {
    //int ls = pow(2, level); //나눠지는 격자 한변 길이
    //leve 범위: 0~ 6

    int copy[66][66];
    memset(copy, 0, sizeof(copy));
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            copy[i][j] = ice[i][j];
        }
    }

    switch (level)
    {
    case 6:
        for (int i = 0; i < side; i += 64) {
            for (int j = 0; j < side; j += 64) {

                for (int k = i; k < i + 32; k++) {
                    for (int l = j; l < j + 32; l++) {
                        ice[k][l + 32] = copy[k][l];
                        ice[k + 32][l + 32] = copy[k][l + 32];
                        ice[k][l] = copy[k + 32][l];
                        ice[k + 32][l] = copy[k + 32][l + 32];
                    }
                }


            }
        }
        break;

    case 5:
        for (int i = 0; i < side; i += 32) {
            for (int j = 0; j < side; j += 32) {

                for (int k = i; k < i + 16; k++) {
                    for (int l = j; l < j + 16; l++) {
                        ice[k][l + 16] = copy[k][l];
                        ice[k + 16][l + 16] = copy[k][l + 16];
                        ice[k][l] = copy[k + 16][l];
                        ice[k + 16][l] = copy[k + 16][l + 16];
                    }
                }

            }
        }
        break;
    case 4:
        for (int i = 0; i < side; i += 16) {
            for (int j = 0; j < side; j += 16) {
                for (int k = i; k < i + 8; k++) {
                    for (int l = j; l < j + 8; l++) {
                        ice[k][l + 8] = copy[k][l];
                        ice[k + 8][l + 8] = copy[k][l + 8];
                        ice[k][l] = copy[k + 8][l];
                        ice[k + 8][l] = copy[k + 8][l + 8];
                    }
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i < side; i += 8) {
            for (int j = 0; j < side; j += 8) {

                for (int k = i; k < i + 4; k++) {
                    for (int l = j; l < j + 4; l++) {
                        ice[k][l + 4] = copy[k][l];
                        ice[k + 4][l + 4] = copy[k][l + 4];
                        ice[k][l] = copy[k + 4][l];
                        ice[k + 4][l] = copy[k + 4][l + 4];
                    }
                }

            }
        }
        break;
    case 2:
        for (int i = 0; i < side; i += 4) {
            for (int j = 0; j < side; j += 4) {

                for (int k = i; k < i + 2; k++) {
                    for (int l = j; l < j + 2; l++) {
                        ice[k][l + 2] = copy[k][l];
                        ice[k + 2][l + 2] = copy[k][l + 2];
                        ice[k][l] = copy[k + 2][l];
                        ice[k + 2][l] = copy[k + 2][l + 2];
                    }
                }

            }
        }
        break;
    case 1:
        for (int i = 0; i < side; i += 2) {
            for (int j = 0; j < side; j += 2) {
                ice[i][j + 1] = copy[i][j];
                ice[i + 1][j + 1] = copy[i][j + 1];
                ice[i][j] = copy[i + 1][j];
                ice[i + 1][j] = copy[i + 1][j + 1];
            }
        }
        break;
    }

}
void meltIce() {

    memset(melt, false, sizeof(melt));
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (!ice[i][j]) continue; //no ice-> continue;
            int chkcnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 && ny < 0 && nx >= side && ny >= side) continue;
                if (ice[nx][ny] > 0) chkcnt++; // No ice
            }
            if (chkcnt < 3)melt[i][j] = true;
        }
    }
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (melt[i][j]) ice[i][j]--;
        }
    }
}
int getMaxIce(pair<int, int> start) {
    queue<pair<int, int>> qu;
    int iceSize = 1;


    qu.push(start);
    chk[start.first][start.second] = true;
    while (!qu.empty()) {
        pair<int, int> node = qu.front();
        qu.pop();
        lefticesum += ice[node.first][node.second];
        for (int i = 0; i < 4; i++) {
            int nx = node.first + dx[i]; int ny = node.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= side || ny >= side) continue;
            if (!chk[nx][ny] && ice[nx][ny] != 0) {
                chk[nx][ny] = true;
                iceSize++;
                qu.push({ nx,ny });
            }
        }
    }

    return iceSize; //얼음 덩어리 크기 반환
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;

    side = pow(2, N);
    //int tt = 1;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cin >> ice[i][j];
            //ice[i][j] = tt++;
        }
    }
    while (Q--) {
        int level;
        cin >> level;

        //1. rotate depending on level value
        rotate(level);

        //2. melt the ice where there is no othere ice adjacent
        meltIce();
    }   
    //after all the moves 
    //1. sum of leftover ice vale (ice[i][j])
    //2. size of the biggest ice area left

    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (ice[i][j] && !chk[i][j]) {
                int tmpsize = getMaxIce({ i,j });
                if (maxIce < tmpsize) maxIce = tmpsize;
            }
        }
    }
    cout << lefticesum << "\n" << maxIce;

}