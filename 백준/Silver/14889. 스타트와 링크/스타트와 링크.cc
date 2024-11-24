#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#define INF 987654321

using namespace std;

int N, arr[24][24], choice[24], ret = INF;

int go() {
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (choice[i] && choice[j]) {
				sum1 += (arr[i][j] + arr[j][i]);
			}
			else if (!choice[i] && !choice[j]) {
				sum2 += (arr[i][j] + arr[j][i]);
			}
		}
	}
	return abs(sum1 - sum2);
}

void choiceFunc(int cnt, int idx) {
	if (cnt == N / 2) {
		ret = min(ret, go());
		return;
	}

	for (int i = idx; i < N; i++) {
		choice[i] = 1;
		choiceFunc(cnt + 1, i + 1);
		choice[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	choiceFunc(0, 0);
	
	cout << ret;
}
