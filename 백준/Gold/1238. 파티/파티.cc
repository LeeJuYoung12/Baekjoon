#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, dist1[1004], dist2[1004], a, b, t, X, ret;
vector<pair<int, int>> adj1[20004], adj2[20004];
void dijkstra(int start, int *dist, vector<pair<int,int>> *adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int here_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] != here_cost) continue;

        for (auto there : adj[u]) {
            int new_cost = here_cost + there.first;
            if (new_cost < dist[there.second]) {
                dist[there.second] = new_cost;
                pq.push({ new_cost, there.second });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    fill(&dist1[0], &dist1[0] + 1004, INF);
    fill(&dist2[0], &dist2[0] + 1004, INF);
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        adj1[a].push_back({ t, b });
        adj2[b].push_back({ t, a });
    }
    dijkstra(X, dist1, adj1);
    dijkstra(X, dist2, adj2);
    
    for (int i = 1; i <= N; i++) {
        ret = max(ret, dist1[i] + dist2[i]);
    }
    cout << ret << "\n";
}