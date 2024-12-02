#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, S, D, U, V, P, dist[504], adj[504][504], visited[504];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + 504, INF); // 거리 배열 초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int here_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] != here_cost) continue;

        for (int i = 0; i < N; i++) {
            if (adj[u][i] == -1) continue; // 간선이 없으면 스킵
            int _dist = adj[u][i];
            if (dist[i] > dist[u] + _dist) {
                dist[i] = dist[u] + _dist;
                pq.push({dist[i], i});
            }
        }
    }
}

void eraseEdge() {
    queue<int> q;
    q.push(D); // 도착점에서 역추적 시작
    while (!q.empty()) {
        int cx = q.front(); q.pop();
        for (int i = 0; i < N; i++) {
            if (adj[i][cx] == -1) continue; // 간선이 없으면 스킵
            if (dist[cx] == dist[i] + adj[i][cx]) { // 최단 경로 조건
                adj[i][cx] = -1; // 간선 제거
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        cin >> S >> D;
        memset(adj, -1, sizeof(adj)); // 간선 배열 초기화

        for (int i = 0; i < M; i++) {
            cin >> U >> V >> P;
            adj[U][V] = P; // 방향 그래프
        }

        dijkstra(S);      // 1. 최단 경로 계산
        eraseEdge();      // 2. 최단 경로 간선 제거
        dijkstra(S);      // 3. 다시 최단 경로 계산

        // 결과 출력
        if (dist[D] == INF) cout << -1 << "\n";
        else cout << dist[D] << "\n";
    }
    return 0;
}
