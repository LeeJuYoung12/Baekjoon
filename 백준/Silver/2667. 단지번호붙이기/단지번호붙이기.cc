#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define INF 1e9
using namespace std;

vector<int> ret;
int N, arr[30][30], visited[30][30];
string str;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

int dfs(int y, int x) {
	
	int ret = 1;
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (visited[ny][nx] || arr[ny][nx] == 0) continue;
		ret += dfs(ny, nx);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				ret.push_back(dfs(i, j));
			}
		}
	}

	sort(ret.begin(), ret.end());
	cout << ret.size() << '\n';
	for (int i : ret) {
		cout << i << '\n';
	}
}
