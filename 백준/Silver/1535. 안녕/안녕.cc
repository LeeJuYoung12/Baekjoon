#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;

int N, L[24], J[24], dp[104];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N;
    for (int i = 0; i < N; i++) cin >> L[i];
    for (int i = 0; i < N; i++) cin >> J[i];

    for (int i = 0; i < N; i++) {
        for (int j = 100; j > L[i]; j--) {
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }
    cout << dp[100] << "\n";
}
