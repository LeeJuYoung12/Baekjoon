#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int R, C, T, arr[54][54], add[54][54], visited[54][54], ret;
bool flag;
vector<pair<int, int>> v1, v2;

int dy1[4] = { 0, -1, 0, 1 };
int dx1[4] = { 1, 0, -1, 0 };

int dy2[4] = { 0, 1, 0, -1 };
int dx2[4] = { 1, 0, -1, 0 };


vector<pair<int, int>> chung(int sy, int sx, int dy[], int dx[]) {
	vector<pair<int, int>> v;
	int cnt = 0;
	int y = sy;
	int x = sx;
	while (1) {
		int ny = y + dy[cnt];
		int nx = x + dx[cnt];
		if (ny == sy && nx == sx) break;
		if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
			cnt++;
			ny = y + dy[cnt];
			nx = x + dx[cnt];
		}
		if (ny == sy && nx == sx) break;
		y = ny;
		x = nx;
		v.push_back({ ny, nx });
	}

	return v;
}

void misego() {

	fill(&add[0][0], &add[0][0] + 54 * 54, 0);

	//1. 먼지
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] / 5 > 0) {
				int temp = arr[i][j] / 5;

				for (int k = 0; k < 4; k++) {
					int ny = i + dy1[k];
					int nx = j + dx1[k];

					if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
					if (arr[ny][nx] == -1) continue;

					add[ny][nx] += temp;
					arr[i][j] -= temp;
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			arr[i][j] += add[i][j];
		}
	}

}

void go(vector<pair<int, int>> &v) {
	for (int i = v.size()-1; i > 0; i--) {
		arr[v[i].first][v[i].second] = arr[v[i-1].first][v[i-1].second];
	}
	arr[v[0].first][v[0].second] = 0;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	flag = true;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (flag) {
					v1 = chung(i, j, dy1, dx1);
					flag = false;
				}
				else {
					v2 = chung(i, j, dy2, dx2);
				}
			}
		}
	}
	while (T--) {
		misego();
		go(v1);
		go(v2);
	}




	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != -1) ret += arr[i][j];
		}
	}
	cout << ret << "\n";
}
