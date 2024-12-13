#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int M, N, arr[504][504], dp[504][504], ret;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int go(int y, int x) {
    if (y == M - 1 && x == N - 1) return 1;
    
    int& ret = dp[y][x];
    if (ret != -1) return ret;

    ret = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= M || nx >= N ) continue;
        if (arr[y][x] <= arr[ny][nx]) continue;
        ret += go(ny, nx);
    }

    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
   
    cout << go(0, 0) << "\n";
}
