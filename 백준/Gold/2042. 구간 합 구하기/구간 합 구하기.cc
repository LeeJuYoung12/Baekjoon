#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define INF 987654321
using namespace std;

long long N, M, K, A[1000004], a, b, c, tree[1000004];

long long sum(int idx) {
    long long ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

void update(int idx, long long val) {
    while (idx <= N) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        update(i, A[i]);
    }

    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c - A[b]);
            A[b] = c;
        }            
        else {
            cout << sum(c) - sum(b - 1) << "\n";
        }
    }
}