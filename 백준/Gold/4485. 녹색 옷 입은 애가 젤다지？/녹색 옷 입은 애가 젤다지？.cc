#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int N, A[130][130], dist[130][130], ret = INF, t = 1;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void go() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ A[0][0], 0 });
    dist[0][0] = A[0][0];
    while (pq.size()) {
        int y = pq.top().second / 1000;
        int x = pq.top().second % 1000;
        int cost = pq.top().first;
        pq.pop();
        if (dist[y][x] != cost) continue;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            int _dist = A[ny][nx];
            if (dist[ny][nx] > _dist + dist[y][x]) {
                dist[ny][nx] = _dist + dist[y][x];
                pq.push({ dist[ny][nx], ny * 1000 + nx });
            }
        }
    }
}
   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (1) {
        memset(A, 0, sizeof(A));
        fill(&dist[0][0], &dist[0][0] + 130 * 130, INF);
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }
        go();
        cout <<"Problem "<< t++<<": "<< dist[N - 1][N - 1] << "\n";
    }
}