#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, arr[300004], l = 1, r, ret = INF;

bool check(int mid) {
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        cnt += arr[i] / mid;
        cnt += (arr[i] % mid ? 1 : 0);
    }
    return cnt <= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> arr[i];
        r = max(r, arr[i]);
    }

    while (l <= r) {
        int mid = (l + r) / 2;
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