#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;

int N, M1, M2, C, dp[10004];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (1) {
        scanf("%d %d.%d", &N, &M1, &M2);
        
        if (N == 0) break;
        int cost = M1 * 100 + M2;
        fill(dp, dp + 10004, 0);

        for (int i = 0; i < N; i++) {
            scanf("%d %d.%d", &C, &M1, &M2);
            int p = M1 * 100 + M2;
            for (int j = p; j <= cost; j++) {
                dp[j] = max(dp[j], dp[j - p] + C);
            }
        }

        cout << dp[cost]<<"\n";
    }
}
