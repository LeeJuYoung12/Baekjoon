#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int R, C, K, ret, visited[10][10];
char arr[10][10];


int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void go(int cnt, int y, int x) {
	if (cnt > K) return;
	if (cnt == K && y == 0 && x == C - 1) ret++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue;
		if (arr[ny][nx] == 'T') continue;
		visited[ny][nx] = 1;
		go(cnt + 1, ny, nx);
		visited[ny][nx] = 0;
	}
}

int main()
{
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	visited[R-1][0] = 1;
	go(1, R-1, 0);
	cout << ret;
}