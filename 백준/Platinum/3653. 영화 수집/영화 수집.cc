#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

int T, N, M, tree[200004], arr[200004], temp;

void update(int idx, int val) {
    while (idx <= 200001) {
        tree[idx] += val;
        idx += (idx & -idx);
    }    
}

int sum(int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        memset(tree, 0, sizeof(tree));
        memset(tree, 0, sizeof(arr));
        cin >> N >> M;
        int updateidx = 100001;
        for (int i = 1; i <= N; i++) {
            update(i + updateidx, 1);
            arr[i] = i + updateidx;
        }

        for (int i = 0; i < M; i++) {
            cin >> temp;
            int idx = arr[temp];
            cout << sum(idx) - 1 << " ";
            update(idx, -1);
            update(--updateidx, 1);
            arr[temp] = updateidx;
        }
        cout << "\n";
    }
}