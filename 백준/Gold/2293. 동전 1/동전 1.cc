#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321
using namespace std;

int n, k, temp, dp[10004], ret;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    dp[0] = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= k; j++) {
            dp[j] += dp[j - v[i]];
        }
    }
    cout << dp[k];
}

