#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, arr[10004], temp, dp[10000][1000], ret;

int go(int idx, int s) {
    if (arr[idx] == 0 || idx > N) return INF;
    if (idx == N) return 0;

    int& ret = dp[idx][s];
    if (ret != -1) return ret;
    
    ret = INF;
    ret = min(ret, go(idx + (s + 1), s + 1) + 1);
    ret = min(ret, go(idx + (s), s) + 1);
    if (s - 1 > 0) ret = min(ret, go(idx + (s - 1), s - 1) + 1);
    
    return ret;
}
//3 0 0 0 0

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        arr[i] = 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> temp;
        arr[temp] = 0;
    }
    
    ret = go(2, 1);
    if (ret == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << ret + 1 << '\n';
    }
 
}
