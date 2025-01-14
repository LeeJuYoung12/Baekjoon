#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, arr[504][504], ret, visited[504][504];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void go(int y, int x, int cnt, int s) {
    if (cnt == 4) {
        ret = max(ret, s);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        go(ny, nx, cnt + 1, s + arr[ny][nx]);
        visited[ny][nx] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // DFS로 테트로미노 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 1;
            go(i, j, 1, arr[i][j]);
            visited[i][j] = 0;
        }
    }

    // "ㅗ" 모양 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i >= 1 && i < N - 1 && j >= 1) { // "ㅓ"
                int temp = arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1];
                ret = max(ret, temp);
            }
            if (i >= 1 && i < N - 1 && j < M - 1) { // "ㅏ"
                int temp = arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j + 1];
                ret = max(ret, temp);
            }
            if (j >= 1 && j < M - 1 && i >= 1) { // "ㅗ"
                int temp = arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i - 1][j];
                ret = max(ret, temp);
            }
            if (j >= 1 && j < M - 1 && i < N - 1) { // "ㅜ"
                int temp = arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j];
                ret = max(ret, temp);
            }
        }
    }

    cout << ret << '\n';
}
