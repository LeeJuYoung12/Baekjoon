#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;

int N, a, b, now, ret;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({ b, a });
    }
    sort(v.begin(), v.end());
    now = v[0].first;
    ret++;
    for (int i = 1; i < N;i++) {
        if (v[i].second < now) continue;
        now = v[i].first;
        ret++;
    }
    cout << ret << "\n";
}
