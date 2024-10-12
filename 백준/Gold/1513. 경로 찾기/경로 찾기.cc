#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M, a, b, C, dp[54][54][54][54], gameRoom[54][54], mod = 1000007;

int go(int y, int x, int cnt, int prev) {
    if (y < 0 || x < 0 || y >= N || x >= M) return 0;

    if (y == N - 1 && x == M - 1) {
        if (cnt == 0 && gameRoom[y][x] == 0) return 1;
        if (cnt == 1 && gameRoom[y][x] > prev)return 1;
        return 0;
    }

    int& ret = dp[y][x][cnt][prev];
    if (ret != -1) return ret;
    ret = 0;
    if (gameRoom[y][x] == 0) {
        ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod;
    }
    else if (gameRoom[y][x] > prev) {
        ret = (go(y + 1, x, cnt-1, gameRoom[y][x]) + go(y, x + 1, cnt-1, gameRoom[y][x])) % mod;
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> N >> M >> C;

    for (int i = 1; i <= C; i++) {
        cin >> a >> b;
        a--, b--;
        gameRoom[a][b] = i;
    }
    

    for (int i = 0; i <= C; i++) {
        
        cout << go(0, 0, i, 0) << " ";
    }
    
}