#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, T, P, dp[1500004];
vector<pair<int, int>> v;

int go(int idx) {
    if (idx > N + 1) return -INF;
    if (idx == N + 1) return 0;

    int& ret = dp[idx];
    if (ret != -1) return ret;

    return ret = max(go(idx + 1), go(idx + v[idx - 1].first) + v[idx - 1].second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T >> P;
        v.push_back({ T , P });
    }

    cout << go(1) << '\n';
}
