#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#define INF 1e9
using namespace std;

int N, arr[1004], cnt[1004], ret = 1;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	fill(cnt, cnt + 1004, 1);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && cnt[i] < cnt[j] + 1) {
				cnt[i] = cnt[j] + 1;
				ret = max(ret, cnt[i]);
			}
		}
	}
	cout << ret << '\n';
}
 