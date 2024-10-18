#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, W, dp[1004][1004];
pair<int, int> pos[1004];

int d(int a, int b) {
    return abs(pos[a].first - pos[b].first) + abs(pos[a].second - pos[b].second);
}

int getSum(int a, int b) {
    if (a == W + 1 || b == W + 1) return 0;
    if (dp[a][b]) return dp[a][b];
    int next = max(a, b) + 1;
    return dp[a][b] = min(getSum(a, next) + d(b, next), getSum(next, b) + d(a, next));  
}

void solve() {
    int a = 0, b = 1;
    for (int i = 2; i < W + 2; i++) {
        if (dp[i][b] + d(a, i) < dp[a][i] + d(b, i)) cout << 1 << "\n", a = i;
        else cout << 2 << "\n", b = i;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    cin >> W;
    
    pos[0].first = 1, pos[0].second = 1;
    pos[1].first = N, pos[1].second = N;

    for (int i = 2; i < W+2; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    cout << getSum(0, 1) << "\n";
    solve();
}