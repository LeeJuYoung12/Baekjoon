#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, K, T, a, b, cnt[304], plusCnt[304], dp[304][304];
vector<pair<int, int>> v;

int go(int idx, int num, int prev) {
    if (idx == v.size()) return 0;
    if (dp[idx][num]) return dp[idx][num];

    int cost = max(0, T - v[idx].second);
    int real_cost = (prev >= cost) ? 0 : cost - prev;  

    int& ret = dp[idx][num];
    if (num - real_cost >= 0) {
        return ret = max(go(idx + 1, num - real_cost, cost) + v[idx].first, go(idx + 1, num, 0));
    }
    else return ret = go(idx + 1, num, 0);
}
// 0 0 1 1 2 2 3 2 2 1 1
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K >> T;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        for (int j = a; j < b; j++) {
            cnt[j] = min(T, ++cnt[j]);
        }
    }

    int temp = cnt[1];
    int _count = 1;
    for (int i = 2; i <= N; i++) {
        if (temp != cnt[i]) {
            v.push_back({ _count, temp });
            _count = 0;
            temp = cnt[i];
        }
        _count++;
    }
    v.push_back({ _count, temp });

    cout << go(0, K, 0) << "\n";
}