#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define INF 1e9
using namespace std;

int N, M, a, b, ret, visited[104];
vector<int> adj[104];

int DFS(int idx) {
	int ret = 1;
	visited[idx] = 1;
	for (int next : adj[idx]) {
		if (visited[next]) continue;
		ret += DFS(next);
	}
	return ret;
}

int main() {

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << DFS(1) - 1 << '\n';
}