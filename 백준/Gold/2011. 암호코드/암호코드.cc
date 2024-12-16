#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

string str;
int dp[5004], n;

bool check1(int idx) {
	if (idx + 1 >= n) return false;
	int a = str[idx] - '0', b = str[idx + 1] - '0', c;

	c = 10 * a + b;
	return (c >= 10 && c <= 26);
}

bool check2(int idx) {
	int c = str[idx] - '0';
	return (c >= 1 && c <= 9);
}

int go(int idx) {
	if (idx == n) return 1;

	int& ret = dp[idx];
	if (ret != -1) return ret;
	ret = 0;

	if (check2(idx)) ret += (go(idx + 1) % 1000000);
	if (check1(idx)) ret += (go(idx + 2) % 1000000);

	return ret % 1000000;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> str;
	n = str.length();
	cout << go(0) << "\n";
}