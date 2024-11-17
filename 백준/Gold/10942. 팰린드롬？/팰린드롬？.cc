#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

string str;
int N, M, S, E, temp, dp[2004][2004], A[2004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i][i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (A[i] == A[i + 1]) dp[i][i + 1] = 1;
    }
    for (int s = 2; s <= N; s++) {
        for (int i = 1; i <= N - s;i++ ) {
            if (A[i] == A[i + s] && dp[i + 1][i + s - 1]) dp[i][i + s] = 1;
        }
    }
    cin >> M;
    while (M--) {
        cin >> S >> E;
        if (dp[S][E]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }    
}