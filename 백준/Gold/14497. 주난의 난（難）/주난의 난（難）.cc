#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define max_n 500000   
#define prev aaa
using namespace std;

int N, M, visited[304][304], ret;
pair <int, int> pos, dest;
char arr[304][304];
queue<pair<int,int>> q;
bool check;
string str;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void DFS(int y, int x) {
    if (check) return;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
        if (arr[ny][nx] == '0') {
            DFS(ny, nx);
        }
        else if (arr[ny][nx] == '1') {
            arr[ny][nx] = '0';
            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
        else if (arr[ny][nx] == '#') {
            check = true;
            return;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> pos.first >> pos.second >> dest.first >> dest.second;
    pos.first--; pos.second--; dest.first--; dest.second--;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j];
        }
    }

    q.push({ pos.first, pos.second });
    fill(&visited[0][0], &visited[0][0] + 304 * 304, 0);

    while (check == false) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            DFS(q.front().first, q.front().second);
            q.pop();
        }
        
        ret++;
    }

    cout << ret;
}