#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long N, l, r, arr[100004], cnt[100004];
long long ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	while (r < N) {
		if (!cnt[arr[r]]) {
			cnt[arr[r]]++;
			r++;
		}
		else {
			ret += (r - l);
			cnt[arr[l]]--;
			l++;
		}
	}
	ret += ((r - l) * (r - l + 1) / 2);
	cout << ret;
}

