#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int N, a, b, lis[504], len;
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

    for (int i = 0; i < v.size(); i++) {
        auto it = lower_bound(lis, lis + len, v[i].second);
        if (*it == 0) len++;
        *it = v[i].second;
    }
    cout << N - len;
}   
