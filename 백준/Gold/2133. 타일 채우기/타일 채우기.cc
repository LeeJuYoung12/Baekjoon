#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, dp[31] = { 1, 0, 3 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	for (int i = 4; i <= n; i += 2) {
		dp[i] += dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += 2 * dp[j];
		}
	}
	cout << dp[n] << "\n";
}
