#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define INF 987654321
using namespace std;


int N, arr[16][16], dp[16][1<<16] ;

int go(int here, int visited) {
    if (visited == (1 << N) - 1) {
        return arr[here][0] ? arr[here][0] : INF;
    }

    int& ret = dp[here][visited];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i < N; i++) {
        if (visited & (1 << i)) continue;
        if (arr[here][i] == 0) continue;
        ret = min(ret, go(i, visited | (1 << i)) + arr[here][i]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 1) << "\n";

}   
