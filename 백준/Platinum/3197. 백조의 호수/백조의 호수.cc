#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

int R, C, visited[1504][1504], visited2[1504][1504], d;
char arr[1504][1504];
vector<pair<int, int>> beak;
queue<pair<int, int>> q, posQ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'L') {
                beak.push_back({ i, j });
                q.push({ i, j });
                visited[i][j] = 1;
            }
            else if (arr[i][j] == '.') {
                q.push({ i, j });
                visited[i][j] = 1;
            }
        }
    }

    posQ.push({ beak[0].first, beak[0].second});
    visited2[beak[0].first][beak[0].second] = 1;

    while (1) {
        //check
        queue<pair<int, int>> tempPos;
        while (!posQ.empty()) {
            int y = posQ.front().first;
            int x = posQ.front().second;
            posQ.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited2[ny][nx]) continue;

                visited2[ny][nx] = true;

                if (arr[ny][nx] == 'L') {
                    cout << d << '\n';
                    return 0;
                }

                if (arr[ny][nx] == '.') posQ.push({ ny, nx });
                else tempPos.push({ ny, nx }); // 얼음이면 다음 탐색을 위해 저장
            }
        }
        posQ = tempPos; // 다음 날 이동할 백조 큐
        
        //water
        queue<pair<int, int>> tempwater;
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue;

                visited[ny][nx] = true;
                arr[ny][nx] = '.';
                tempwater.push({ ny, nx });
            }
        }
        q = tempwater; // 다음 날 확장할 물 큐

        d++;
    }
}