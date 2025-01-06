#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int N, arr[104], visited[104];
vector<int> v;

void DFS(int now, int start) {
    if (visited[now]) {
        if (now == start) v.push_back(now);
        return;
    }

    visited[now] = 1;
    DFS(arr[now], start);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        DFS(i, i);
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto a : v) {
        cout << a << '\n';
    }
}   