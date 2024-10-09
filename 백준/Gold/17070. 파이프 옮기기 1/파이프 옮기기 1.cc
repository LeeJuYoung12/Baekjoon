#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define INF 987654321
using namespace std;


int N, ret, arr[20][20], dp[20][20][3];

bool check(int y, int x, int d) {
    if (d == 0 || d == 2) {
        if (!arr[y][x]) return true;
    }
    else if (d == 1) {
        if (arr[y][x] == 0 && arr[y - 1][x] == 0 && arr[y][x - 1] == 0) return true;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][2][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if (check(i+1, j + 1, 1)) dp[i+1][j + 1][1] += dp[i][j][0];

            if (check(i+1, j, 2)) dp[i+1][j][2] += dp[i][j][2];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];

        }
    }
    ret = dp[N][N][0];
    ret += dp[N][N][1];
    ret += dp[N][N][2];

    cout << ret << "\n";
}   
