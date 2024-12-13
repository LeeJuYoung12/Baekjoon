#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

long long N, K, dp[204][204];

long long go(int sum, int k) {
    if (sum > N) return 0;
    if (k == 0) {
        if (sum == N) return 1;
        else return 0;
    }

    long long& ret = dp[sum][k];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i <= N; i++) {
        ret += go(sum + i, k - 1) % 1000000000;
    }    
    return ret % 1000000000;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> N >> K;
    cout << go(0, K) << "\n";
}
