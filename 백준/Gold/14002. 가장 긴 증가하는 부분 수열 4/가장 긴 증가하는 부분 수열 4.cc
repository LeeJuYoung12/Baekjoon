#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#define INF 1e9
using namespace std;

int N, arr[1004], cnt[1004], ret = 1, prevIdx[1004], idx;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	fill(cnt, cnt + 1004, 1);
	fill(prevIdx, prevIdx + 1004, -1);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && cnt[j] + 1 > cnt[i]) {
				cnt[i] = cnt[j] + 1;
				prevIdx[i] = j;
				if (ret < cnt[i]) {
					idx = i;
					ret = cnt[i];
				}
			}
		}
	}

	cout << ret << '\n';
	while (idx >= 0) {
		v.push_back(arr[idx]);
		idx = prevIdx[idx];
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i]<<' ';
	}

}