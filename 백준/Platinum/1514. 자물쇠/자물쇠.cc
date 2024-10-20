#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

int N, a[104], b[104], dp[104][10][10][10][2];

int _mod(int x) {
    return (x < 0) ? x + 10 : x % 10;
}

int f(int pos, int x, int y, int z, int flag) {
    if (pos == N) return 0;
    int& ret = dp[pos][x][y][z][flag];
    if (ret != -1) return ret;
    if (_mod(x + a[pos]) == _mod(b[pos])) return ret = min(f(pos + 1, y, z, 0, 0), f(pos + 1, y, z, 0, 1));
    ret = INF;
    int _flag = flag ? 1 : -1;
    for (int i = 1; i <= 3; i++) {
        ret = min(ret, 1 + f(pos, _mod(x + i * _flag), y, z, flag));
        ret = min(ret, 1 + f(pos, _mod(x + i * _flag), _mod(y + i * _flag), z, flag));
        ret = min(ret, 1 + f(pos, _mod(x + i * _flag), _mod(y + i * _flag), _mod(z + i * _flag), flag));
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int i = 0; i < N; i++)scanf("%1d", &a[i]);
    for (int i = 0; i < N; i++)scanf("%1d", &b[i]);
    printf("%d\n", min(f(0, 0, 0, 0, 0), f(0, 0, 0, 0, 1)));

}

