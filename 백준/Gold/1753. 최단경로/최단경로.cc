#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int V, E, K, u, v, w;
vector<pair<int, int>> adj[20004];
int dist[20004];
void go() {
    fill(dist, dist + 20004, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, K });
    dist[K] = 0;
    while (pq.size()) {
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (dist[here] != cost) continue;
        for (pair<int, int> there : adj[here]) {
            int _cost = there.first;
            int _there = there.second;
            if (dist[_there] > dist[here] + _cost) {
                dist[_there] = dist[here] + _cost;
                pq.push({ dist[_there], _there });
            }
        }
    }

}
   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> V >> E;
    cin >> K;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
    }
    go();
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF" << "\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }
}