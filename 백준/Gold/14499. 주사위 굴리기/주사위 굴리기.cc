#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#define INF 987654321
using namespace std;

int N, M, y, x, K, arr[24][24], dice[6], temp, upIdx = 1;
int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };
//   0
//4  1  5
//   2
//   3
void move(int dir) {
    int t = dice[1];

    if (dir == 0) {//동
        x++;
        dice[1] = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[5];
        dice[5] = t;
    }
    else if (dir == 1) {//서
        x--;
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = dice[4];
        dice[4] = t;
    }
    else if(dir == 2) {//북
        y--;
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = dice[0];
        dice[0] = t;
    }
    else if(dir == 3) {//남
        y++;
        dice[1] = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[2];
        dice[2] = t;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> y >> x >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < K; i++) {
        cin >> temp;
        temp--;
        int ny = y + dy[temp];
        int nx = x + dx[temp];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        move(temp);
        if (arr[y][x] == 0) {
            arr[y][x] = dice[3];
        }
        else {
            dice[3] = arr[y][x];
            arr[y][x] = 0;
        }
        cout << dice[1] << '\n';
    }
}
//   0
//4  1  5
//   2
//   3