#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 1e9
using namespace std;

int T, W, arr[1004], dp[1004][2][34];

int go(int t, int tree, int w){
    
    if (w < 0) return -1e9;
    if (t > T) return 0;

    int& ret = dp[t][tree][w];
    if (ret != 0) return ret;

    return ret = max(go(t + 1, tree, w), go(t + 1, (tree + 1) % 2, w - 1)) + (tree == arr[t] - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T >> W;
    
    for (int i = 1; i <= T; i++) cin >> arr[i];

    cout << max(go(1, 0, W), go(1, 1, W - 1))<<"\n";
}