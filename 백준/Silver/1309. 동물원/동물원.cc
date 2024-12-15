#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, dp[100004][3], ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= 100000; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	ret = (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
	cout << ret << "\n";
}
