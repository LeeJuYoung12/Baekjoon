#include <iostream>
#include <cstring>
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

void checkOtherShapes(int y, int x) {
    // "ㅗ", "ㅜ", "ㅏ", "ㅓ" 모양 계산
    for (int i = 0; i < 4; i++) {
        int temp = arr[y][x];
        bool valid = true;
        for (int j = 0; j < 3; j++) {
            int ny = y + dy[(i + j) % 4];
            int nx = x + dx[(i + j) % 4];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
                valid = false;
                break;
            }
            temp += arr[ny][nx];
        }
        if (valid) ret = max(ret, temp);
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

    // DFS를 이용한 "ㄴ", "ㄱ", "ㅁ" 등 모양 처리
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 1;
            go(i, j, 1, arr[i][j]);
            visited[i][j] = 0;
        }
    }

    // "ㅗ", "ㅜ", "ㅏ", "ㅓ" 모양 처리
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            checkOtherShapes(i, j);
        }
    }

    cout << ret << '\n';
    return 0;
}
