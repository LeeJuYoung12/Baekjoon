#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, arr[54][54], visited[54][54], ret = INF;
vector<pair<int, int>> virusV;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int emptySpaces = 0; // 빈 칸 개수

// BFS로 바이러스 확산
int BFS(const vector<int>& v) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;

    for (int i : v) {
        int y = virusV[i].first;
        int x = virusV[i].second;
        q.push({ y, x });
        visited[y][x] = 1;
    }

    int time = 0;
    int filled = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] || arr[ny][nx] == 1) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });

            // 빈 칸인 경우만 채운 개수 증가
            if (arr[ny][nx] == 0) {
                filled++;
                if (filled == emptySpaces) return visited[ny][nx] - 1;
            }
        }
    }

    // 빈 칸을 모두 채우지 못한 경우
    return INF;
}

// 조합으로 활성화할 바이러스 선택
void comb(int idx, vector<int>& v) {
    if (v.size() == M) {
        ret = min(ret, BFS(v));
        return;
    }

    for (int i = idx + 1; i < virusV.size(); i++) {
        v.push_back(i);
        comb(i, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                virusV.push_back({ i, j });
            }
            else if (arr[i][j] == 0) {
                emptySpaces++;
            }
        }
    }

    // 빈 칸이 없는 경우
    if (emptySpaces == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> temp;
    comb(-1, temp);

    if (ret == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << ret << '\n';
    }
}
