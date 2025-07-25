#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define INF 1e9
using namespace std;

long long N, a, b, T, arr[24],  dp[24][24][24];

long long go(int idx, int a, int b) {
	if (idx == T) {
		return 0;
	}

	long long& ret = dp[idx][a][b];
	if (ret != -1) return ret;
	long long first = abs(a - arr[idx]) + go(idx + 1, arr[idx], b);
	long long second = abs(b - arr[idx]) + go(idx + 1, a, arr[idx]);
	return ret = min(first, second);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cin >> a >> b;
	cin >> T;
	for(int i= 0;i<T;i++){
		cin >> arr[i];
	}

	cout<<go(0, a, b)<<'\n';
}
