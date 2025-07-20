#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define INF 1e9
using namespace std;

int N, M, visited[54][54], ret = -INF;
char arr[54][54];
string str;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

void BFS(int y,int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = 1;
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] || arr[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
			ret = max(ret, visited[ny][nx] - 1);
		}
	}
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'L') {
				memset(visited, 0, sizeof(visited));
				BFS(i, j);
			}
		}
	}
	cout << ret << '\n';
}