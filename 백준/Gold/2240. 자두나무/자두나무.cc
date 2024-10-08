#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;


int T, W, ret, arr[1004], dp[1004][2][34];

int go(int idx, int tree, int cnt) {
    if (cnt < 0) return -1e9;
    if (idx == T) {
        return 0;
    }

    int& ret = dp[idx][tree][cnt];
    if (~ret) return ret;
     
    return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == arr[idx] - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T >> W;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }
    cout << max(go(0, 1, W - 1), go(0, 0, W)) << "\n";
}   
