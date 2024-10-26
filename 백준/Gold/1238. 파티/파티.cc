#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;

long long N, M, ret, X, dist[1004][1004], a, b, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    fill(&dist[0][0], &dist[0][0] + 1004 * 1004, INF);

    cin >> N >> M >> X;
    X--;  // X에 대해서도 1을 빼서 0부터 시작하도록 설정

    for (int i = 0; i < N; i++) dist[i][i] = 0; // 자기 자신으로의 거리 초기화

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        a--, b--;
        dist[a][b] = t;
    }

    // 플로이드 와샬 알고리즘
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (dist[i][X] != INF && dist[X][i] != INF) {  // 무한대 검사
            ret = max(ret, dist[i][X] + dist[X][i]);
        }
    }

    cout << ret << "\n";
}
