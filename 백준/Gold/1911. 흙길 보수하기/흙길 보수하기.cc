#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define INF 60000000004
using namespace std;

int N, L, a, b, s, e, cnt, ret;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }

    sort(v.begin(), v.end());
    
    for (int i = 0; i < N; i++) {
        if (v[i].second <= e) continue;

        if (e < v[i].first) {
            cnt = (v[i].second - v[i].first) / L + (((v[i].second - v[i].first) % L) ? 1 : 0);
            e = v[i].first + cnt * L;
        }
        else {
            cnt = (v[i].second -e)/L + (((v[i].second - e) % L) ? 1 : 0);
            e = e + cnt * L;
        }
        ret += cnt;
    }

    cout << ret << "\n";
}