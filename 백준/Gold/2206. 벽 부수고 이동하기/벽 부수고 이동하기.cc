#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, arr[1004][1004], visited[1004][1004][2]; // 3차원 방문 배열 추가
string str;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

struct Node {
    int y, x, breakUsed;
};

int bfs() {
    queue<Node> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1; // 벽을 부수지 않고 방문

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int breakUsed = q.front().breakUsed;
        q.pop();

        if (y == N - 1 && x == M - 1) return visited[y][x][breakUsed];

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

            // 벽이 아닌 경우, 그대로 이동
            if (arr[ny][nx] == 0 && !visited[ny][nx][breakUsed]) {
                visited[ny][nx][breakUsed] = visited[y][x][breakUsed] + 1;
                q.push({ny, nx, breakUsed});
            }
            // 벽인 경우, 아직 벽을 부순 적이 없다면 부수고 이동
            else if (arr[ny][nx] == 1 && breakUsed == 0 && !visited[ny][nx][1]) {
                visited[ny][nx][1] = visited[y][x][breakUsed] + 1;
                q.push({ny, nx, 1});
            }
        }
    }
    return -1; // 도달할 수 없는 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j] - '0'; // 올바른 숫자로 변환
        }
    }

    memset(visited, 0, sizeof(visited));
    cout << bfs() << '\n';
}
