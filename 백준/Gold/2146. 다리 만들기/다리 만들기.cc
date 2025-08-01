#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#define INF 1e9
using namespace std;

int N, arr[104][104], visited[104][104], cnt = 1, ret = INF;
queue<pair<int, int>> q;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

void makeLabel(int y, int x, int cnt) {
	visited[y][x] = 1;
	arr[y][x] = cnt;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (visited[ny][nx] || arr[ny][nx] == 0) continue;
		makeLabel(ny, nx, cnt);
			
	}
}

void bfs(int num) {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == num) {
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx]) continue;
			if (arr[ny][nx] != 0 && arr[ny][nx] != 0) {
				ret = min(ret, visited[y][x] - 1);
			}
			else {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

void solve() {
	for (int i = 1; i < cnt; i++) {
		memset(visited, 0, sizeof(visited));
		bfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) arr[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] || arr[i][j] == 0) continue;
			makeLabel(i, j, cnt++);
		}
	}
	solve();
	cout << ret << '\n';
}
 