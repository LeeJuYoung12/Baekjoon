#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int R, C, startY, startX, destY, destX, visited[54][54], visitedWater[54][54];
char arr[54][54];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
queue<pair<int, int>> waterQ;

void waterBFS() {
    int size = waterQ.size();
    for (int s = 0; s < size; s++) {
        int y = waterQ.front().first;
        int x = waterQ.front().second;
        waterQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C || visitedWater[ny][nx]) continue;
            if (arr[ny][nx] == '.') {
                visitedWater[ny][nx] = visitedWater[y][x] + 1;
                waterQ.push({ ny, nx });
                arr[ny][nx] = '*';
            }
        }
    }
}

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = 1;
    while (q.size()) {
        int size = q.size();
        waterBFS();
        for (int s = 0; s < size; s++) {
            y = q.front().first;
            x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue;
                if (arr[ny][nx] == '*' || arr[ny][nx] == 'X') continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                startY = i;
                startX = j;
            }
            else if (arr[i][j] == 'D') {
                destY = i;
                destX = j;
            }
            else if (arr[i][j] == '*') {
                waterQ.push({ i,j });
                visitedWater[i][j] = 1;
            }                
        }
    }
    BFS(startY, startX);
    if (visited[destY][destX] == 0) {
        cout << "KAKTUS" << '\n';
    }
    else {
        cout << visited[destY][destX] - 1 << '\n';
    }
}   