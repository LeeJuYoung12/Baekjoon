#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, arr[44], ret, temp, dp[44];

int go(int idx) {
    if (idx >= N-1) {
        return 1;
    }
    if(arr[idx]) return go(idx + 1);
    if (dp[idx] != -1) return dp[idx];
    int& ret = dp[idx];
    ret = 0;

    if (!arr[idx+1]) {
        ret += (go(idx + 1) + go(idx + 2));
    }
    else {
        ret += go(idx + 1);
    }

    return ret;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(dp, -1, sizeof(dp));
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        temp--;
        arr[temp] = 1;
    }
    cout << go(0) << "\n";

}
