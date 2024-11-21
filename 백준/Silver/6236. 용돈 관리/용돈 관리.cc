#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, K, A[100004], l, r, mid, ret;

bool check(int mid) {
    int sum = 0, cnt = 1;
    for (int i = 0; i < N; i++) {
        if (A[i] > mid) return false;
        
        if (sum + A[i] > mid) {
            sum = 0;
            cnt++;
        }
        
        sum += A[i];
    }

    return cnt <= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        r += A[i];
    }
    ret = r;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ret = min(ret, mid);
        }
        else {
            l = mid + 1;
        }
    }

    cout << ret << '\n';
}