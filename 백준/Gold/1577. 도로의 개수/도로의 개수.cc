#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

long long N, M, K, a, b, c, d, dp[104][104];
int dy[] = { 0, 1 };
int dx[] = { 1, 0 };
vector<pair<int,int>> v[104][104];

long long go(int y, int x) {
    if (y == N && x == M) return 1;
    
    long long& ret = dp[y][x];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < 2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny <0 || nx <0 || ny > N || nx > M) continue;

        bool isBlock = false;
        for (auto it : v[y][x]) {
            if (it == make_pair(ny, nx)) {
                isBlock = true;
                break;
            }
        }
        if (isBlock) continue;
        ret += go(ny, nx);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c >> d;
        v[a][b].push_back({ c,d });
        v[c][d].push_back({ a, b });
    }
    cout<<go(0, 0);
}
