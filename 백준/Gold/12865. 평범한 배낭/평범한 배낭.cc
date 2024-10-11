#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;

int N, K, W[1004], V[1004], dp[100004], ret = -INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
        for (int j = K; j >= W[i]; j--) {
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
        }
    }
    cout << dp[K];

}
