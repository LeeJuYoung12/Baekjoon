#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int N, M, arr[104][104], visited[104][104], ret, cnt;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void DFS(int y, int x) {
	visited[y][x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M||visited[ny][nx]) continue;
		if (arr[ny][nx] == 1) {
			arr[ny][nx] = 0;
			visited[ny][nx] = 1;
			cnt++;
		}
		else {
			DFS(ny, nx);
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
	while (1) {
		bool flag = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					flag = false;
				}
			}
		}
		if (flag) break;

		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		cnt = 0;
		ret++;

		DFS(0, 0);
	}
	cout << ret <<'\n';
	cout << cnt << '\n';
	
}