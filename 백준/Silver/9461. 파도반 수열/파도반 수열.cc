#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
using namespace std;

long long dp[104], T, temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    for (int i = 9; i <= 100; i++) {
        dp[i] = dp[i - 5] + dp[i - 1];
    }

    cin >> T;
    while (T--) {
        cin >> temp;
        cout << dp[temp] << "\n";
    }
}