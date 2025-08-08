#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#define INF 1e9
using namespace std;

int N, K, X, arr[200004], paySum[200004], bonusPaySum[200004], l, r, ret = -1;

bool check(int l, int r) {

	int sum1 = bonusPaySum[l - 1];
	long long sum2 = paySum[N] - paySum[r];
	return (sum1 + sum2) >= K;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> N >> K >> X;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		paySum[i] = paySum[i - 1] + arr[i];
		bonusPaySum[i] = bonusPaySum[i - 1] + arr[i]*X;
	}
	l = 1, r = 1;
	while (r<=N) {
		if (check(l, r)) {
			ret = max(ret, r - l + 1);
			r++;
		}
		else {
			l++;
			if (l > r) r = l;
		}
	}	

	cout << ret << '\n';
}