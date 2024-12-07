#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define INF 987654321
#define y1 AAA
using namespace std;

int N, M, T, D, mountain[30][30], dist[3000][3000], ret;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
vector<int> v;
string str;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    fill(&dist[0][0], &dist[0][0] + 3000 * 3000, INF);

    cin >> N >> M >> T >> D;

    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            if (str[j] >= 'A' && str[j] <= 'Z') {
                mountain[i][j] = str[j] - 'A';
            }
            else {
                mountain[i][j] = 26 + str[j] - 'a';
            }            
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            v.push_back(i * 100 + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (abs(mountain[i][j] - mountain[ny][nx]) <= T) {
                    if (mountain[i][j] - mountain[ny][nx] >= 0) {
                        dist[100 * i + j][100 * ny + nx] = 1;
                    }
                    else {
                        dist[100 * i + j][100 * ny + nx] = (mountain[ny][nx] - mountain[i][j]) * (mountain[ny][nx] - mountain[i][j]);
                    }
                }               
            }
        }
    }
    for (int k:v) {
        for (int i : v) {
            for (int j : v) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    ret = mountain[0][0];
    for (int i: v) {
        if (dist[0][i] + dist[i][0] <= D) {
            ret = max(ret, mountain[i / 100][i%100]);
         }
    }
    cout << ret << "\n";
}