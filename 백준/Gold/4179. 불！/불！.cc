#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int R, C, visited[1004][1004], ret;
char arr[1004][1004];
vector<pair<int, int>> playerPos;
queue<pair<int, int>> fireQ;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

bool clearCheck(int y, int x) {
    if (y < 0 || x < 0 || y >= R || x >= C) return true;
    return false;
}

void fireGo() {
    int size = fireQ.size();
    for (int i = 0; i < size; i++) {
        int y = fireQ.front().first;
        int x = fireQ.front().second;
        fireQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (arr[ny][nx] == '#' || arr[ny][nx] == 'F') continue;
            arr[ny][nx] = 'F';
            fireQ.push({ ny, nx });
        }
    }
}

bool BFS(int y, int x) {
    queue<pair<int, int>> q;
    int size;
    bool flag = false;
    q.push({ y,x });
    visited[y][x] = 1;

    while (q.size()){

        fireGo();
        size = q.size();

        for (int s = 0; s < size; s++) {

            y = q.front().first;
            x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (clearCheck(ny, nx)) {
                    flag = true;
                    ret = visited[y][x];
                    break;
                }
                if (arr[ny][nx] == 'F' || arr[ny][nx] == '#' || visited[ny][nx]) continue;
                q.push({ ny,nx });
                visited[ny][nx] = visited[y][x] + 1;
            }
            if (flag) break;
        }
        if (flag) break;
    }

    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'J') playerPos.push_back({ i,j });
            else if (arr[i][j] == 'F') fireQ.push({ i, j });
        }
    }

    if (BFS(playerPos.front().first, playerPos.front().second)) {
        cout << ret << '\n';
    }
    else {
        cout << "IMPOSSIBLE" << '\n';
    }
}
