#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define INF 1e9
using namespace std;

int N, M, K, arr[54][54], ret = 1;
string str;
int dy[] = { 0, 0, 1, 1 };
int dx[] = { 0, 1, 1, 0 };
int main() {

	cin >> N >> M;
	K = max(N, M);
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < K; k++) {
				if (i + k >= N || j + k >= M) break;
				bool check = true;
				for (int l = 0; l < 4; l++) {
					if (arr[i][j] != arr[i + dy[l]*k][j + dx[l]*k]) {
						check = false;
						break;
					}
				}
				if (!check) continue;
				ret = max(ret, k + 1);
			}
		}
	}

	cout << ret * ret << '\n';
}