#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, M, visited[1004], a, b, cnt;
vector<int> adj[1004];

void go(int here) {
    visited[here] = 1;
    for (int k : adj[here]) {
        if (visited[k]) continue;
        go(k);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        bool flag = true;
        for (int i = 0; i < 1004; i++) adj[i].clear();
        fill(visited, visited + 1004, 0);
        cin >> N; 
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        go(1);
        for (int i = 1; i <= N; i++) {
            if (visited[i] == 0) flag = false;
        }
        
        if (M != N - 1) flag = false;

        if (flag == false) cout << "graph" << '\n';
        else cout << "tree" << '\n';
    }
   

}