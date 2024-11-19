#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, temp, K, A[2004], B[2004], psumA[4004], psumB[4004], ret;
map<int, int> aCnt, bCnt;
map<int, int> make(int n, int psum[]) {
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n + i; j++) {
            int sum = psum[j] - psum[j - i];
            mp[sum]++;
            if (i == n) break;
        }
    }
    return mp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> K;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        psumA[i] = psumA[i - 1] + A[i];
    }
    for (int i = N + 1; i <= 2 * N; i++) {
        psumA[i] = psumA[i - 1] + A[i - N];
    }

    for (int i = 1; i <= M; i++) {
        cin >> B[i];
        psumB[i] = psumB[i - 1] + B[i];
    }
    for (int i = M + 1; i <= 2 * M; i++) {
        psumB[i] = psumB[i - 1] + B[i - M];
    }
    aCnt = make(N, psumA);
    bCnt = make(M, psumB);
    ret = aCnt[K] + bCnt[K];
    for (int i = 1; i < K; i++) {
        ret += (aCnt[i] * bCnt[K - i]);
    }
    cout << ret << "\n";
}