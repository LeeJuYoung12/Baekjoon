#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define INF 1e9
using namespace std;

vector<int> vec[10002] ,ret_bfs, ret_dfs;
int visited[1002];

void bfs(int idx) {
	queue<int> q;
	q.push(idx);
	visited[idx] = 1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		ret_bfs.push_back(x);
		for (int next : vec[x]) {
			if (visited[next]) continue;
			q.push(next);
			visited[next] = 1;
		}
	}
}

void dfs(int idx) {
	visited[idx] = 1;
	ret_dfs.push_back(idx);
	for (int next : vec[idx]) {
		if (visited[next]) continue;
		dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m, v, a, b;
	cin >> n >> m >> v;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		vec[a].push_back(b); //양방향 간선처리
		vec[b].push_back(a); //양방향 간선처리
	}

	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end()); // 낮은 숫자부터 탐색.
	}
	dfs(v);
	memset(visited, 0, sizeof(visited));
	bfs(v);
	for (auto it : ret_dfs) {
		cout << it << " ";
	}
	cout << '\n';
	for (auto it : ret_bfs) {
		cout << it << " ";
	}
}
