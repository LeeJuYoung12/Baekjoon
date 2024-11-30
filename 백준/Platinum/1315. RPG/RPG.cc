#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#define INF 60000000004
using namespace std;

int N, Str[54], Int[54], Pnt[54], nowStr = 1, nowInt = 1, visited[54], dp[1004][1004];

int go(int STR, int INT) {
    
    int& ret = dp[STR][INT];
    if (ret != -1) return ret;

    ret = 0;
    int pnt = 0;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        if (STR >= Str[i] || INT >= Int[i]) {
            ret++;
            if (!visited[i]) {
                visited[i] = 1;
                pnt += Pnt[i];
                v.push_back(i);
            }
        }
    }

    for (int i = 0; i <= pnt; i++) {
        int nextStr = min(1000, STR + i);
        int nextInt = min(1000, INT + pnt - i);
        ret = max(ret, go(nextStr, nextInt));
    }

    for (int here : v) {
        visited[here] = 0;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Str[i] >> Int[i] >> Pnt[i];
    }

    cout << go(1, 1) << "\n";
}