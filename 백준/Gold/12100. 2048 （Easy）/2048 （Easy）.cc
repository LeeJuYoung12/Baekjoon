#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#define INF 987654321

using namespace std;

int N, ret;

class board {
public:
	int arr[24][24];
	void _rotate90() {
		int temp[24][24];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp[i][j] = arr[N - j - 1][i];
			}
		}
		memcpy(arr, temp, sizeof(arr));
	}

	void _move() {
		int temp[24][24];
		for (int i = 0; i < N; i++) {
			int c = -1, d = 0;
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 0) continue;
				if (d && arr[i][j] == temp[i][c]) temp[i][c] *= 2, d= 0;
				else temp[i][++c] = arr[i][j], d = 1;
			}
			for (c++; c < N; c++) temp[i][c] = 0;
		}    
		memcpy(arr, temp, sizeof(arr));
	}

	void getMax() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret = max(ret, arr[i][j]);
			}
		}
	}
};

void go(board c,int cnt) {	
	if (cnt == 5) {
		c.getMax();
		return;
	}

	for (int i = 0; i < 4; i++) {
		board d = c;
		d._move();
		go(d, cnt + 1);
		c._rotate90();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	board c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> c.arr[i][j];
		}
	}

	go(c, 0);
	cout << ret << "\n";
}
