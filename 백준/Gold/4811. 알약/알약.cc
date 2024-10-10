#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 1e9
using namespace std;

long long N, dp[34][34];


long long go(long long w, long long h) {
    
    if (w < 0 || h < 0) {
        return 0;
    }
    
    if (w == 0 && h == 0) {
        return 0;
    }
        
    long long& ret = dp[w][h];
    if (dp[w][h] != 0) return dp[w][h];

    return ret = go(w - 1, h + 1) + go(w, h - 1);  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    dp[1][0] = 1, dp[0][1] = 1;

    while (1) {
        cin >> N;
        if (N == 0) break;
        cout << go(N, 0)<<"\n";
    }

}