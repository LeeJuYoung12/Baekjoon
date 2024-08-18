#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int M, N, K, visited[105][105], arr[105][105], cnt;
int a1, a2, b1, b2;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
vector<int> v;

void DFS(int y, int x) {
	visited[y][x] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= M || nx >= N || !arr[ny][nx]) continue;
		if (visited[ny][nx]) continue;
		DFS(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> M >> N >> K; //MxN
	fill(&arr[0][0], &arr[0][0] + 105 * 105, 1);
	for (int i = 0; i < K; i++) {
		cin >> a1 >> a2 >> b1 >> b2;
		for (int j = a2; j < b2; j++) {
			for (int k = a1; k < b1; k++) {
				arr[j][k] = 0;
			}
		} 
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] && visited[i][j] == 0) {
				cnt = 0;
				DFS(i, j);
				v.push_back(cnt);
			}
		}
	}
	cout << v.size()<<'\n';
	sort(v.begin(), v.end());
	for (int ret : v) {
		cout << ret << ' ';
	}	
}