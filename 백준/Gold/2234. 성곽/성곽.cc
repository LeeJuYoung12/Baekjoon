#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 사용을 위해 추가

using namespace std;

int N, M, cnt, maxSize = 0, delMaxSize = 0, arr[54][54], visited[54][54];
int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

int DFS(int y, int x) {
    
    int ret = 1;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (arr[y][x] & (1 << i)) continue;
        if (ny < 0 || ny >= M || nx < 0 || nx >= N || visited[ny][nx]) continue;

        ret += DFS(ny, nx);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // 1. 방의 개수와 최대 방 크기 구하기
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {           
                maxSize = max(maxSize, DFS(i, j));
                cnt++;  // 방의 개수 증가
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                if (arr[i][j] & (1 << k)) {
                    fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
                    arr[i][j] -= (1 << k);
                    delMaxSize = max(delMaxSize, DFS(i, j));
                    arr[i][j] += (1 << k);
                }
            }
        }
    }

    // 출력
    cout << cnt << '\n';         
    cout << maxSize << '\n';
    cout << delMaxSize << '\n';
}
