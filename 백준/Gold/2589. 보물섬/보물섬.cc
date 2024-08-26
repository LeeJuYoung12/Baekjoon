#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, visited[55][55], ret;
char arr[55][55];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void BFS(int i, int j) {

	queue < pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = 1;
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (arr[ny][nx] == 'W' || visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
			ret = max(ret, visited[ny][nx]);

		}
	}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'L') {
				fill(&visited[0][0], &visited[0][0] + 55 * 55, 0);
				BFS(i, j);
			}
		}
	}

	cout << ret-1;
}