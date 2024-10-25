#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
using namespace std;

int N, M, T, D, A[30][30], b[3000][3000], ret;
string str;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> T >> D;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {            
            if (str[j] >= 'A' && str[j] <= 'Z') {
                A[i][j] = str[j] - 'A';
            }
            else {
                A[i][j] = str[j] - 'a' + 26;
            }
        }
    }
    ret = A[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            v.push_back(i * 100 + j);
        }
    }
    fill(&b[0][0], &b[0][0] + 3000 * 3000, INF);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int d = 0; d < 4; d++) {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                int height_diff = abs(A[i][j] - A[ny][nx]);
                if (height_diff <= T) {
                    if (A[ny][nx] > A[i][j]) {
                        b[i * 100 + j][ny * 100 + nx] = height_diff * height_diff;
                    }
                    else {
                        b[i * 100 + j][ny * 100 + nx] = 1;
                    }
                }
            }
        }
    }

    for (int k : v) {
        for (int i : v) {
            for (int j : v) {
                b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }

    for (int i : v) {
        if (D >= b[0][i] + b[i][0]) {
            ret = max(ret, A[i / 100][i % 100]);
        }
    }
    cout << ret << "\n";
}
