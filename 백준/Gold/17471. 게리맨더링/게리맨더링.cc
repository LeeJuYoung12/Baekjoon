#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#define INF 1e9
using namespace std;

int N, arr[14], areaNum[14], visited[14], m, temp, ret = INF;
vector<int> adj[14];

void dfs(int idx, int num) {
	visited[idx] = 1;
	for (int next : adj[idx]) {
		if (visited[next] || areaNum[next] != num) continue;
		dfs(next, num);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			adj[i].push_back(temp);
		}
	}

	for (int i = 0; i < (1 << N); i++) {
		memset(areaNum, 0, sizeof(areaNum));
		memset(visited, 0, sizeof(visited));

		int cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				areaNum[j + 1] = 1;
				sum1 += arr[j + 1];
			}
			else {
				sum2 += arr[j + 1];
			}
		}

		
		for (int j = 1; j <= N; j++) {
			if (areaNum[j] == 1 && !visited[j]) {
				dfs(j, 1);
				cnt1++;
			}
			if (areaNum[j] == 0 && !visited[j]) {
				dfs(j, 0);
				cnt2++;
			}
		}

		if (cnt1 == 1 && cnt2==1) {
			ret = min(ret, abs(sum1 - sum2));
		}
	}
	if (ret == INF) cout << -1 << '\n';
	else cout << ret << "\n";
}
 