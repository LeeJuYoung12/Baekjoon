#include <iostream>
#include <cstring>
#include <algorithm>
#define INF -987654321
using namespace std;

int R, C, dp, visited[26], ret;
char arr[24][24];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void go(int y, int x, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        int next = (int)(arr[ny][nx] - 'A');
        if (!visited[next]) {
            visited[next] = 1;
            go(ny, nx, cnt + 1);
            visited[next] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    visited[(int)arr[0][0] - 'A'] = 1;
    go(0, 0, 1);
    cout << ret << "\n";
}
