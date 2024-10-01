#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1987654321
using namespace std;

long long N, M, ret = INF, arr[300004];

bool check(long long mid) {
    long long num = 0;
    for (int i = 0; i < M; i++) {
        num += arr[i] / mid;
        if (arr [i] % mid) num++;
    }
    return N >= num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    long long lo = 1, hi = 0, mid;
    for (int i = 0; i < M; i++) {
        cin >> arr[i];
        hi = max(hi, arr[i]);
    }
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            ret = min(ret, mid);
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ret << "\n";
}
