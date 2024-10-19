#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, dp[1004][1004], visited[104];

struct que {
    int s, i, p;
    que(int x, int y, int c) :s(x), i(y), p(c) {}

};
vector<que> a;

int go(int STR, int INT) {
     
    int &ret = dp[STR][INT];
    if (ret != -1) return ret;

    int pnt = 0;
    ret = 0;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        if (a[i].s <= STR || a[i].i <= INT) {
            ret++;
            if (!visited[i]) {
                visited[i] = true;
                pnt += a[i].p;
                v.push_back(i);
            }
        }
    }

    for (int i = 0; i <= pnt; i++) {
        int nextSTR = min(1000, STR + i);
        int nextINT = min(1000, INT + pnt - i);
        ret = max(ret, go(nextSTR, nextINT));
    }

    for (int q : v) {
        visited[q] = false;
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int STR, INT, PNT;
        cin >> STR >> INT >> PNT;
        a.push_back(que(STR, INT, PNT));
    }
    memset(dp, -1, sizeof(dp));
    cout << go(1, 1) << "\n";
}