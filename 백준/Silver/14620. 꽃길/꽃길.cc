#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;

int N, arr[10][10], visited[10][10], ret = 987654321;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

bool check(int y, int x) {
	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (visited[ny][nx]) {
			return false;
		}
	}
	return true;

}
void go(int cnt, int _sum) {
	if (cnt == 3) {
		ret = min(ret, _sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i <= 0 || j <= 0 || i >= N - 1 || j >= N - 1||visited[i][j]) {
				continue;
			}

			if (check(i, j) == false) continue;

			int temp = 0;			
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				temp += arr[ny][nx];
				visited[ny][nx] = 1;
			}
			
			visited[i][j] = 1;
			go(cnt + 1, _sum + arr[i][j] + temp);
			visited[i][j] = 0;

			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				
				visited[ny][nx] = 0;
			}			
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	go(0, 0);
	cout << ret;
}