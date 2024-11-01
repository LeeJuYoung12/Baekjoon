#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#define INF 987654321
using namespace std;

int n, arr[10004], dp[10004], ret = -INF;

int go(int idx) {
    if (idx >= n) {
        return 0;
    }

    int& ret = dp[idx];
    if (ret != -1) return ret;
    
    return ret = max(go(idx + 1), max(go(idx + 3) + arr[idx] + arr[idx+1], go(idx+2)+arr[idx]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << go(0) << "\n";
}