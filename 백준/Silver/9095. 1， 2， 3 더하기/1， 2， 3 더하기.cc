#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define INF 1e9
using namespace std;

int T, N, dp[14];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	dp[0] = 1;
	for (int i = 1; i < 14; i++) {
		for (int j = 1; j < 4; j++) {
			if (i >= j) {
				dp[i] += dp[i - j];
			}
		}
	}


	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp[N]<<'\n';
	}
}
