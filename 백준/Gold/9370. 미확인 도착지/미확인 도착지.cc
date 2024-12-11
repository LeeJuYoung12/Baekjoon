#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int T, n, m, t, s, g, h, a, b, d, x;
int dist_s[3000], dist_g[3000], dist_h[3000];
vector<pair<int, int>> adj[3000];
vector<int> finalDest;
void init() {
    fill(dist_s, dist_s + 3000, INF);
    fill(dist_g, dist_g + 3000, INF);
    fill(dist_h, dist_h + 3000, INF);
    for (int i = 0; i < 3000; i++) adj[i].clear();
    finalDest.clear();
}

void dijkstra(int start, int A[]) {
    priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;
    pq.push({ 0, start });
    A[start] = 0;
    while (pq.size()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (auto there : adj[u]) {
            int next = there.second;
            int next_cost = there.first;
            if (A[next] > cost + next_cost) {
                A[next] = cost + next_cost;
                pq.push({ A[next], next });
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        init();
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            adj[a].push_back({ d, b });
            adj[b].push_back({ d, a });
        }
        for (int i = 0; i < t; i++) {
            cin >> x;
            finalDest.push_back(x);
        }
        dijkstra(s, dist_s);
        dijkstra(g, dist_g);
        dijkstra(h, dist_h);
        int Dist_GH = dist_g[h];
        sort(finalDest.begin(), finalDest.end());
        for (auto a : finalDest) {
            int dest = a;
            if (dist_s[dest] == dist_s[g] + Dist_GH + dist_h[dest])cout << dest << " ";
            else if (dist_s[dest] == dist_s[h] + Dist_GH + dist_g[dest]) cout << dest << " ";
        }
        cout << "\n";
    }
}
