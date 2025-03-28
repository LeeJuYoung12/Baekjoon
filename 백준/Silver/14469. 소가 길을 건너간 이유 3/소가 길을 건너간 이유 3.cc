#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;

int N, a, b, now;
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
    for (auto it : v) {
        if (now < it.first) now = it.first;
        now += it.second;
    }

    cout << now;
}
