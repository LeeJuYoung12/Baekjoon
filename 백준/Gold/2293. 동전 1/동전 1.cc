#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;

int N, K, dp[100004], temp;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        for (int j = temp; j <= K; j++) {
            dp[j] += (dp[j - temp]);
        }
    }
    cout << dp[K];
}
