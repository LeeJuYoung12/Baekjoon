#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int R, C, swanY, swanX, day, visited[1504][1504], visited_Swan[1504][1504];
char arr[1504][1504];

queue<pair<int, int>> q_Water, q_Swan;
queue<pair<int, int>> temp_Swan, temp_Water;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void Qclear(queue<pair<int, int>>& q) {
    queue<pair<int, int>> empty;
    swap(q, empty);
}

void water_melt() {


    while (q_Water.size()) {
        int y = q_Water.front().first;
        int x = q_Water.front().second;
        q_Water.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) continue;

            if (arr[ny][nx] == 'X') {
                temp_Water.push({ ny, nx });
                visited[ny][nx] = 1;
                arr[ny][nx] = '.';
            }

        }
    }
}


bool move_swan() {

    while (q_Swan.size()) {
        int y = q_Swan.front().first;
        int x = q_Swan.front().second;
        q_Swan.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited_Swan[ny][nx]) continue;
            if (arr[ny][nx] == '.') {
                q_Swan.push({ ny, nx });
                visited_Swan[ny][nx] = 1;
            }
            else if (arr[ny][nx] == 'L') {
                return true;
            }
            else if (arr[ny][nx] == 'X') {
                temp_Swan.push({ ny, nx });
                visited_Swan[ny][nx] = 1;
            }

        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'L') {
                swanY = i;
                swanX = j;
            }
            if (arr[i][j] == '.' || arr[i][j] == 'L') {
                q_Water.push({ i, j });
                visited[i][j] = 1;
            }
        }
    }

    q_Swan.push({ swanY, swanX });
    visited_Swan[swanY][swanX] = 1;

    while (true) {
        if (move_swan()) break;
        water_melt();
        q_Water = temp_Water;
        q_Swan = temp_Swan;
        Qclear(temp_Water);
        Qclear(temp_Swan);
        day++;
    }

    cout << day << '\n';

    return 0;
}
