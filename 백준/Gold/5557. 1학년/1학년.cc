#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

long long N, A[104], dp[104][24];

long long go(int idx, int sum) {
    if (sum < 0 || sum>20) return 0;
    if (idx == N - 1) {
        return (sum == A[idx]) ? 1 : 0;
    }
    long long& ret = dp[idx][sum];
    if (ret != -1) return ret;
    ret = 0;
    return ret = go(idx + 1, sum + A[idx]) + go(idx + 1, sum - A[idx]);
}
//8 3 2 4 (4

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << go(1, A[0]) << "\n";
}