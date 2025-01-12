#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#define INF 987654321
using namespace std;

int N, M, ret = INF;
char arr[14][14];
pair<int, int> red, blue;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

int move(int dir) {
    int by = blue.first;
    int bx = blue.second;
    while (arr[by + dy[dir]][bx + dx[dir]] == '.') {
        by += dy[dir];
        bx += dx[dir];
    }

    if (arr[by + dy[dir]][bx + dx[dir]] == 'O') return -1;

    int ry = red.first;
    int rx = red.second;
    while (arr[ry + dy[dir]][rx + dx[dir]] == '.') {
        ry += dy[dir];
        rx += dx[dir];
    }

    if (arr[ry + dy[dir]][rx + dx[dir]] == 'O') return 1;

    if (ry == by && rx == bx) {
        if (dir == 0) {
            red.first < blue.first ? by++ : ry++;
        }
        else if (dir == 1) {
            red.second < blue.second ? bx++ : rx++;
        }
        else if (dir == 2) {
            red.first < blue.first ? ry-- : by--;
        }
        else if (dir == 3) {
            red.second < blue.second ? rx-- : bx--;
        }
    }
    red = { ry, rx };
    blue = { by, bx };

    return 0;
}

void go(int idx) {
    if (idx > 10) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ry = red.first, rx = red.second;
        int by = blue.first, bx = blue.second;
        int result = move(i);
        if (result == 0) {
            go(idx + 1);
        }
        else if (result == 1) {
            ret = min(ret, idx);
        }
        red = { ry, rx };
        blue = { by, bx };
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'R') {
                red = { i,j };
                arr[i][j] = '.';
            }
            else if (arr[i][j] == 'B') {
                blue = { i,j };
                arr[i][j] = '.';
            }
        }
    }

    go(1);
    cout << (ret == INF ? -1 : ret) << '\n';
}