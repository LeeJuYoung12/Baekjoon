	#include <iostream>
	#include <algorithm>
	#include <vector>
	using namespace std;

	int N, K, psum[100005], temp, ret = -99999999;
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0); cout.tie(0);

		cin >> N >> K;
		for (int i = 1; i <=N; i++) {
			cin >> temp;
			psum[i] = psum[i - 1] + temp;
		}

		for (int i = K; i <= N; i++) {
			ret = max(ret, psum[i] - psum[i - K]);
		}
		cout << ret;
	}
