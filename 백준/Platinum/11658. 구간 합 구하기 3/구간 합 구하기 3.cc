#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define INF 987654321
#define y1 AAA
using namespace std;

long long N, M, A[1025][1025], tree[1025][1025], w, x1, y1, c, x2, y2;

void update(int y, int x, int val) {
    while (y <= N) {
        int j = x;
        while (j <= N) {
            tree[y][j] += val;
            j += (j & -j);
        }
        y += (y & -y);
    }
}

long long sum(int y, int x) {
    long long ret = 0;
    while (y > 0) {
        int j = x;
        while (j > 0) {
            ret += tree[y][j];
            j -= (j & -j);
        }
        y -= (y & -y);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            update(i, j, A[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> w;
        if (w == 0) {//(x1,y1) to c
            cin >> y1 >> x1 >> c;
            long long diff = c - A[y1][x1];
            A[y1][x1] = c;
            update(y1, x1, diff);
        }
        else {//(x2,y2) ~ (x1, y1) sum
            cin >> y1 >> x1 >> y2 >> x2;
            cout << sum(y2, x2) - sum(y2, x1-1) - sum(y1-1, x2) + sum(y1-1, x1-1) << "\n";
        }
    }
}