#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int R, C, visited[1004][1004], ret;
char arr[1004][1004];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
pair<int, int> jPos;
queue<pair<int, int>> fireQ;

void fire() {
    int size = fireQ.size();
    for (int i = 0; i < size; i++) {
        int y = fireQ.front().first;
        int x = fireQ.front().second;
        fireQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (arr[ny][nx] == '#'||arr[ny][nx] == 'F') continue;
            arr[ny][nx] = 'F';
            fireQ.push({ ny, nx });
        }
    }    
}

bool BFS(int y, int x) {
    bool flag = false;
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({ y, x });

    while (q.size()) {     

        fire();

        int size = q.size();
        for (int i = 0; i < size; i++) {

            y = q.front().first;
            x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
                    flag = true;
                    ret = visited[y][x];
                    break;
                }
                if (arr[ny][nx] == '#' || arr[ny][nx] == 'F') continue;
                if (visited[ny][nx]) continue;

                visited[ny][nx] = visited[y][x] + 1;
                q.push({ ny,nx });
            }
            if (flag) break;
        }    
        if (flag) break;
    }

    return flag;
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'J') {
                jPos = { i, j };
            }
            else if (arr[i][j] == 'F') {
                fireQ.push({ i, j });
            }
        }
    }

    if (BFS(jPos.first, jPos.second)) {
        cout << ret << '\n';
    }
    else {
        cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}