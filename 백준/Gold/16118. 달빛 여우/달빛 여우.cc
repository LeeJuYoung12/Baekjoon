#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, a, b, d, dist[4004], dist2[4004][2], ret;
vector<pair<int,int>> adj[4004];

void dijkstra(int start) {
    fill(dist, dist + 4004, INF);
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
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

void dijkstra2(int start) {
    fill(&dist2[0][0], &dist2[0][0] + 4004 * 2, INF);
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist2[start][0] = 0;
    pq.push({ 0, {start, 0}});
    while (!pq.empty()) {
        int here_cost = pq.top().first;
        int u = pq.top().second.first;
        int cnt = pq.top().second.second;
        pq.pop();

        if (dist2[u][cnt] != here_cost) continue;

        for (auto there : adj[u]) {
            int new_cost = here_cost + (!cnt?there.first/2:there.first*2);
            if (new_cost < dist2[there.second][!cnt]) {
                dist2[there.second][!cnt] = new_cost;
                pq.push({ new_cost, {there.second, !cnt}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> d;
        adj[a].push_back({ d*2, b });
        adj[b].push_back({ d*2, a });
    }
    dijkstra(1);
    dijkstra2(1);
    for (int i = 2; i <= N; i++) {
        int d = min(dist2[i][0], dist2[i][1]);
        if (d > dist[i]) ret++;
    }
    cout << ret << "\n";

}