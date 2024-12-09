#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

long long N, s, e, M, a, b, c, dist[54], cityMoney[54], visited[54];
vector<pair<int, int>> adj[54];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    fill(dist, dist + 54, -INF);

    cin >> N >> s >> e >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }
    for (int i = 0; i < N; i++) {
        cin >> cityMoney[i];
    }
    queue<int> q;
    dist[s] = cityMoney[s];
    for (int i = 0; i < N; i++) {
        for (int here = 0; here < N; here++) {
            for (auto there : adj[here]) {
                int d = -there.second + cityMoney[there.first];
                int to = there.first;
                if (dist[here] != -INF && dist[to] < dist[here] + d) {
                    if (i == N - 1)q.push(to);
                    dist[to] = dist[here] + d;  
                }
            }
        }
    }
    bool isOk = false;
    while (q.size()) {
        int here = q.front();
        q.pop();
        for (pair<int, int> there : adj[here]) {
            if (there.first == e) {
                isOk = true;
                break;
            }
            if (!visited[there.first]) {
                visited[there.first] = 1;
                q.push(there.first);
            }
        }
        if (isOk) break;
    }

    if (dist[e] == -INF) {
        cout << "gg" << "\n";
    }
    else if (isOk) {
        cout << "Gee" << "\n";
    }
    else {
        cout << dist[e] << "\n";
    }
}