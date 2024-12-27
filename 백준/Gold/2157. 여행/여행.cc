#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, K, a, b, c, dp[304][304];
vector<pair<int, int>> adj[304];

int go(int idx, int cnt) {
    if (cnt < 0) return -INF;
    if (idx == N) {
        return 0;
    }

    int& ret = dp[idx][cnt];
    if (ret != -1) return ret;

    ret = -INF;

    for (auto it : adj[idx]) {
        ret = max(ret, go(it.second, cnt - 1) + it.first);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c;
        if (a < b) adj[a].push_back({ c, b });
    }
    cout<<go(1, M-1)<<'\n';
}
