#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, L, temp, s, e, mid, ret;
vector<int> v;

bool check(int mid) {
    int cnt = 0;
    for (int i = 1; i < v.size(); i++) {
        int dist = v[i] - v[i - 1];
        cnt += dist / mid;
        if (dist % mid == 0) cnt--;
    }

    return cnt > M;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> L;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    v.push_back(0);
    v.push_back(L);
    sort(v.begin(), v.end());
    s = 1, e = L;
    while (s <= e) {
        mid = (s + e) / 2;
        if (check(mid)) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
            ret = mid;
        }
    }
    cout << ret << '\n';

}
