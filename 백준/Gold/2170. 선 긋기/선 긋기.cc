#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, a, b, ret;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end());

    int l = v[0].first, r = v[0].second;
    for (int i = 1; i < N; i++) {
        if (r < v[i].first) {
            ret += (r - l);
            l = v[i].first;
            r = v[i].second;
        }
        else if (v[i].first <= r && v[i].second >= r) {
            r = v[i].second;
        }
    }
    ret += (r - l);
    cout << ret;
}
