#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
#include <vector>
#define INF 987654321

using namespace std;

int arr[104][104], N, K, L, ret, a, b, dir, cnt;
char c[10004];

deque<pair<int, int>> snakePos;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		arr[a - 1][b - 1] = 1;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> a;
		cin >> c[a];
	}
	//0번째 머리
	snakePos.push_back({ 0, 0 });
	arr[0][0] = 2;
	//1 사과 2 뱀
	while (1) {
		cnt++;
		
		//2. go
		int ny = snakePos[0].first + dy[dir];
		int nx = snakePos[0].second + dx[dir];
		
		if (ny <0||nx<0||ny>=N||nx>=N||arr[ny][nx] == 2) {
			break;
		}
		if (arr[ny][nx] == 0) {
			snakePos.push_front({ ny, nx });
			arr[ny][nx] = 2;

			arr[snakePos.back().first][snakePos.back().second] = 0;
			snakePos.pop_back();
		}
		else if (arr[ny][nx] == 1) {
			snakePos.push_front({ ny, nx });
			arr[ny][nx] = 2;
		}

		//1. 방향
		if (c[cnt] != 0) {
			if (c[cnt] == 'D') {
				dir++;
				if (dir >= 4) dir = 0;

			}
			else if (c[cnt] == 'L') {
				dir--;
				if (dir < 0) dir = 3;
			}
		}
	}

	cout << cnt;
}

