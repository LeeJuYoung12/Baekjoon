#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, ret, a, b, dp[104][100004];
vector<pair<int, int>> walk, bike;

int go(int idx,int t) {
    if (idx == N) {
        return 0;
    }

    int& ret = dp[idx][t];
    if (ret) return ret;
    ret = -1e6;
    if (t + walk[idx].first <= K) ret = max(ret, go(idx + 1, t + walk[idx].first) + walk[idx].second);
    if (t + bike[idx].first <= K) ret = max(ret, go(idx + 1, t + bike[idx].first) + bike[idx].second);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        walk.push_back({ a, b });
        cin >> a >> b;
        bike.push_back({ a, b });
    }

    cout << go(0, 0) << "\n";
}