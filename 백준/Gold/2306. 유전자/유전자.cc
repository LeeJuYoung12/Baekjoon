#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#define INF 987654321
using namespace std;

string input;
int dp[504][504];

int go(int l, int r) {
    if (l >= r) return 0;

    int& ret = dp[l][r];
    if (ret != -1) return ret;

    for (int k = l; k < r; k++) {
        ret = max(ret, go(l, k) + go(k+1, r));
    }

    if ((input[l] == 'a' && input[r] == 't') || (input[l] == 'g' && input[r] == 'c')) {
        ret = max(ret, go(l + 1, r - 1) + 2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> input;
    cout << go(0, input.length() - 1) << '\n';    
}
