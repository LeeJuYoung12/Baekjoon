#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define size 1000001  // N의 최대 크기보다 1 크게 설정
using namespace std;

long long N, M, w, x, y, x2, y2, c, A[1030][1030], tree[1030][1030];

long long sum(int idx, int row) {
    long long ret = 0;
    while (idx > 0) {
        ret += tree[row][idx];
        idx -= (idx & -idx);
    }
    return ret;
}

void update(int idx, int row, long long val) {
    while (idx <= N) {
        tree[row][idx] += val;
        idx += (idx & -idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            update(j, i, A[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> w;
        if (w == 0) {
            //(x, y)를 c로
            cin >> y >> x >> c;
            long long temp = c - A[y][x];
            A[y][x] = c;
            update(x, y, temp);
        }
        else {
            //(x,y) ~ (x2, y2)합
            cin >> y >> x >> y2 >> x2;
            long long ret = 0;
            for (int j = y; j <= y2; j++) {
                if (x == 0) {
                    ret += sum(x2, j);
                }
                else {
                    ret += (sum(x2, j) - sum(x - 1, j));
                }
            }
            cout << ret << "\n";
        }
    }

}
