#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, l, r, sum, arr[2000001], p, ret;
bool check[4000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	

	for (int i = 2; i <= N; i++) {
		if (check[i]) continue;
		for (int j = 2 * i; j <= N; j+=i) {
			check[j] = 1;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (!check[i]) arr[p++] = i;
	}
	while (1) {
		if (sum >= N)sum -= arr[l++];
		else if (r == p) break;
		else sum += arr[r++];
		if (sum == N) ret++;
	}
	cout << ret << '\n';
}