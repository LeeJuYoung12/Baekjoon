#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, X, a, b, visited[100004];
vector<int> adj[100004], adj_reversed[100004];

int BFS(int here, vector<int> adj[]) {
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    int ret = 0;
    while (q.size()) {
        int _here = q.front();
        q.pop();
        for (int there : adj[_here]) {
            if (visited[there]) continue;
            visited[there] = 1;
            q.push(there);
            ret++;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj_reversed[b].push_back(a);
    }
    
    
    int ret1 = BFS(X, adj_reversed);
    fill(visited, visited + 100004, 0);
    int ret2 = BFS(X, adj);
    cout << ret1 + 1 << " " << N - ret2 << "\n";
}
