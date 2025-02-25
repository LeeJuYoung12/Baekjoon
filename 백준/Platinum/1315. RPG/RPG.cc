#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, STR[54], INT[54], PNT[54], visited[54], dp[1004][1004];

int go(int s, int i) {
    int& ret = dp[s][i];
    if (ret != -1) return ret;

    ret = 0;
    int pnt = 0;
    vector<int> v;
    for (int k = 0; k < N; k++) {
        if (s >= STR[k] || i >= INT[k]) {
            ret++;
            if (!visited[k]) {
                visited[k] = 1;
                pnt += PNT[k];
                v.push_back(k);
            }
        }
    }

    for (int k = 0; k <= pnt; k++) {
        int nextSTR = min(1000, s + k);
        int nextINT = min(1000, i + pnt - k);
        ret = max(ret, go(nextSTR, nextINT));
    }

    for (auto it : v) {
        visited[it] = 0;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> STR[i] >> INT[i] >> PNT[i];
    }

    cout << go(1, 1) << '\n';
}
    