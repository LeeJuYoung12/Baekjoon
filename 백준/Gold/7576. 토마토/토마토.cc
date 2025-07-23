#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define INF 1e9
using namespace std;

int N, M, arr[1004][1004], visited[1004][1004], ret;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
queue<pair<int, int>> tomato;

void BFS() {
	int y, x;
	while (tomato.size()) {
		y = tomato.front().first;
		x = tomato.front().second;
		tomato.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] || arr[ny][nx] != 0)continue;
			tomato.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
}

int main() {

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				tomato.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}
	BFS();
	bool check = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				if (visited[i][j]) {
					ret = max(ret, visited[i][j] - 1);
				}
				else {
					check = false;
					break;
				}
			}
		}
		if (!check) break;
	}
	if (!check) cout << -1 << '\n';
	else cout << ret << '\n';
}