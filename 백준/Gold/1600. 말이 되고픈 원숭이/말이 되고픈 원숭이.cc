#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define INF 1e9
using namespace std;

int K, W, H, arr[204][204], ret = INF, visited[204][204][34];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
int dy2[] = { -1,-2,-2,-1,1,2,2,1 };
int dx2[] = { -2,-1,1,2,-2,-1,1,2 };

struct State {
	int y, x, k;
};

void BFS(int y, int x, int k) {
	queue<State> q;
	q.push({ y, x, K });
	visited[y][x][K] = 1;
	while (q.size()) {
		y = q.front().y;
		x = q.front().x;
		k = q.front().k;
		q.pop();
		if (k > 0) {
			for (int i = 0; i < 8; i++) {
				int ny = y + dy2[i];
				int nx = x + dx2[i];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
				if (arr[ny][nx] == 1 || visited[ny][nx][k - 1]) continue;

				visited[ny][nx][k - 1] = visited[y][x][k] + 1;
				q.push({ ny, nx, k - 1 });
			}
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (arr[ny][nx] == 1 || visited[ny][nx][k]) continue;
			visited[ny][nx][k] = visited[y][x][k] + 1;
			q.push({ ny, nx, k });
		}
	}
}

int main() {

	cin >> K;
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
		}
	}
	BFS(0, 0, K);
	for (int i = 0; i <= K; i++) {
		if (visited[H - 1][W - 1][i] != 0) {
			ret = min(ret, visited[H - 1][W - 1][i]);
		}
	}
	if (ret == INF) cout << -1 << '\n';
	else cout << ret - 1 << '\n';
}