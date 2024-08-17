#include <iostream>
#include <algorithm>
using namespace std;

int  N, visited[105][105], arr[105][105], ret, height;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void DFS(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (arr[ny][nx] <= height) continue;
		if (visited[ny][nx]) continue;
		DFS(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i <= 100; i++) {
		
		int cnt = 0;
		height = i;
		fill(&visited[0][0], &visited[104][105], 0);

		for(int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (arr[j][k] > height && !visited[j][k]) {
					DFS(j, k);
					cnt++;
				}
			}
		}

		ret = max(cnt, ret);
	}
	cout << ret;
}