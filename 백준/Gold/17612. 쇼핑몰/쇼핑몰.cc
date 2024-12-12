#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, K, a, b;
long long ret;
struct cacher {
    int id, maxTime, cacher_id;
};

struct comp {
    bool operator()(cacher& a, cacher& b) {
        if (a.maxTime == b.maxTime) {
            return a.cacher_id > b.cacher_id;
        }
        return a.maxTime > b.maxTime;
    }
};

bool comp2(cacher& a, cacher& b) {
    if (a.maxTime == b.maxTime) {
        return a.cacher_id > b.cacher_id;
    }
    return a.maxTime < b.maxTime;
}

priority_queue<cacher, vector<cacher>, comp> pq;
vector<cacher> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (i < K) {
            pq.push({ a, b , i + 1 });
            continue;
        }
        pq.push({ a, b + pq.top().maxTime, pq.top().cacher_id });
        v.push_back(pq.top());
        pq.pop();
    }
    while (pq.size()) {
        v.push_back(pq.top());
        pq.pop();
    }
    sort(v.begin(), v.end(), comp2);
    for (int i = 0; i < v.size(); i++) {
        ret += 1LL * (i + 1) * v[i].id;
    }
    cout << ret << "\n";
}