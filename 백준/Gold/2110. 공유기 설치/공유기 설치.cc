#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#define INF 1e9
using namespace std;

int N, C, arr[200004], ret, l, r;
vector<int> v;

bool check(int mid) {
	int pos = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (pos <= arr[i]) {
			cnt++;
			pos = arr[i] + mid;
		}		
	}
	return cnt >= C;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		r = max(r, arr[i]);
	}
	sort(arr, arr + N);
	
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			ret = max(ret, mid);
		}
		else {
			r = mid - 1;
		}
	}
	cout << ret << '\n';
}
 