#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M, K, visited[55][55], arr[55][55], x, y, ret;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void DFS(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M|| !arr[ny][nx]) continue;
		if (visited[ny][nx]) continue;
		DFS(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		ret = 0;
		fill(&arr[0][0], &arr[54][55], 0);
		fill(&visited[0][0], &visited[54][55], 0);

		cin >> M >> N >> K; // NxM
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] && visited[i][j] == 0) {
					DFS(i, j);
					ret++;
				}
			}
		}
		cout << ret << '\n';
	}

}