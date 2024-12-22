#include <iostream>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;

int N, M, arr[54][54], cnt, maxS, bigRet,visited[54][54], compSize[2504];
int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };


int DFS(int y, int x, int idx) {

    int ret = 1;
    visited[y][x] = idx;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= M || nx >= N || visited[ny][nx]) continue;
        if (arr[y][x] & (1 << i)) continue;
        ret += DFS(ny, nx, idx);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
   
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                cnt++;
                compSize[cnt] = DFS(i, j, cnt);
                maxS = max(maxS, compSize[cnt]);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 1 < M) {
                int a = visited[i][j];
                int b = visited[i + 1][j];
                if (a != b) {
                    bigRet = max(bigRet, compSize[a] + compSize[b]);
                }
            }
            if (j + 1 < N) {
                int a = visited[i][j];
                int b = visited[i][j + 1];
                if (a != b) {
                    bigRet = max(bigRet, compSize[a] + compSize[b]);
                }
            }
        }
    }

    cout << cnt << '\n' << maxS << '\n' << bigRet << '\n';
}
