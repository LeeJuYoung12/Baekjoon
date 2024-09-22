#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

long long N, K, arr[104], visited[104];
long long ret;
vector<long> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	for (int i = 0; i < K; i++) cin >> arr[i];
	for (int i = 0; i < K; i++) {
		if (!visited[arr[i]]) {
			if (v.size() == N) {
				int last_idx = 0, pos;
				for (int _a : v) {
					int here_pick = INF;
					for (int j = i + 1; j < K; j++) {
						if (_a == arr[j]) {
							here_pick = j;
							break;
						}
					}
					if (last_idx < here_pick) {
						last_idx = here_pick;
						pos = _a;
					}
				}

				visited[pos] = 0;
				ret++;
				v.erase(find(v.begin(), v.end(), pos));


			}
			v.push_back(arr[i]);
			visited[arr[i]] = 1;
		}	
	}
	cout << ret;

}
