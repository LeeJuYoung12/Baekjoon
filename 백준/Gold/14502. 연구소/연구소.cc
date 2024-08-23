#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int N, M, arr[8][8], visited[8][8], ret;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
vector<pair<int, int>> safeVec, virusVec;

void DFS(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		if (arr[ny][nx] == 1 || visited[ny][nx] == 1) continue;
		DFS(ny, nx);
	}
}

int solve() {
	fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
	for (pair<int, int> b: virusVec) {
		DFS(b.first, b.second);
	}

	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (arr[y][x] == 0 && !visited[y][x]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) safeVec.push_back({i, j});
			if (arr[i][j] == 2) virusVec.push_back({ i, j });
		}
	}
	
	for (int i = 0; i < safeVec.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				
				arr[safeVec[i].first][safeVec[i].second] = 1;
				arr[safeVec[j].first][safeVec[j].second] = 1;
				arr[safeVec[k].first][safeVec[k].second] = 1;
				
				ret = max(solve(), ret);

				arr[safeVec[i].first][safeVec[i].second] = 0;
				arr[safeVec[j].first][safeVec[j].second] = 0;
				arr[safeVec[k].first][safeVec[k].second] = 0;

			}
		}
	}
	cout << ret;	
}