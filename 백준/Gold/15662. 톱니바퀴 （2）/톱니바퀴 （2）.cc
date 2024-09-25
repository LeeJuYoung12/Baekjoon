#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
#include <vector>
#define INF 987654321

using namespace std;

int T, K, a, b, isRotate[1004], ret;
string arr[1004];

void rotateFunc() {
	for (int i = 0; i < T; i++) {
		if (isRotate[i] == 1) { //시계
			char temp = arr[i][arr[i].size() - 1];
			for (int j = arr[i].size()-1; j > 0; j--) {
				arr[i][j] = arr[i][j - 1];
			}
			arr[i][0] = temp;
		}
		else if (isRotate[i] == -1) {
			char temp = arr[i][0];
			for (int j = 0; j < arr[i].size() - 1; j++) {
				arr[i][j] = arr[i][j + 1];
			}
			arr[i][arr[i].size() - 1] = temp;
		}
	}
}

void go(int idx, int dir) {
	//1 시계방향 1 S극
	fill(&isRotate[0], &isRotate[0] + 1004, 0);

	isRotate[idx] = dir;

	for (int i = idx; i < T - 1; i++) {
		if (arr[i][2] != arr[i + 1][6]) {
			isRotate[i + 1] = -isRotate[i];
		}
	}

	for (int i = idx; i >= 1; i--) {
		if (arr[i][6] != arr[i - 1][2]) {
			isRotate[i - 1] = -isRotate[i];
		}
	}
	rotateFunc();

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		a--;
		go(a, b);
	}

	for (int i = 0; i < T; i++) {
		if (arr[i][0] == '1') {
			ret++;
		}
	}
	cout << ret;
}