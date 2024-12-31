#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N, K, visited[100004], prevIdx[100004] , ret, temp;

bool checkBound(int a) {
    return (a >= 0 && a <= 100000);
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    
    while (q.size()){
        int now = q.front();
        q.pop();
        if (now == K) {
            ret = visited[now];
            break;
        }

        for (auto next : { now + 1, now - 1, 2 * now }) {
            if (!checkBound(next)) continue;

            if (!visited[next]) {
                q.push(next);
                visited[next] = visited[now] + 1;
                prevIdx[next] = now;
            }
        }
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(prevIdx, -1, sizeof(prevIdx));

    cin >> N >> K;
    if (N == K) {
        cout << 0 << '\n';
        cout << N << '\n';

        return 0;
    }

    BFS(N);
    cout << ret - 1 << '\n';
    
    vector<int> v;
    temp = K;
    while (1) {
        if (prevIdx[temp] == -1) {
            v.push_back(temp);
            break;
        }
        else {
            v.push_back(temp);
            temp = prevIdx[temp];
        }
    }
    reverse(v.begin(), v.end());
    for (auto a : v) {
        cout << a << ' ';
    }
}