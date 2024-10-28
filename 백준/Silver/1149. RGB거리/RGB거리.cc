#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

struct paint {
    int r, g, b;
};

int N, r, g, b, dp[1004][3], ret;
vector<paint> v;

//r:0 g:1 b:2
int go(int idx, int prev) {
    if (idx == N) {
        return 0;
    }

    int& ret = dp[idx][prev];
    if (ret != 0) return dp[idx][prev];
    
    if (prev == 0) {
        return ret = min(go(idx + 1, 1) + v[idx].g, go(idx + 1, 2) + v[idx].b);
    }
    else if (prev == 1) {
        return ret = min(go(idx + 1, 0) + v[idx].r, go(idx + 1, 2) + v[idx].b);
    }
    else {
        return ret = min(go(idx + 1, 0) + v[idx].r, go(idx + 1, 1) + v[idx].g);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> r >> g >> b;
        v.push_back({ r, g, b });
    }
    
    ret = min(go(1, 0) + v[0].r, go(1, 1) + v[0].g);
    ret = min(ret, go(1, 2) + v[0].b);
    cout << ret<<"\n";
}