#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define INF 987654321
#define y1 AAA
using namespace std;

int N, K, a, b, dist[404][404], s;
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        dist[a][b] = -1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] == 1 && dist[k][j] == 1) dist[i][j] = 1;
                if (dist[i][k] == -1 && dist[k][j] == -1) dist[i][j] = -1;
            }
        }
    }
    
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> a >> b;
        cout << dist[a][b] << '\n';
    }
}