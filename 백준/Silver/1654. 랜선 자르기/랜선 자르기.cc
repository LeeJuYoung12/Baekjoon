#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#define INF 987654321
using namespace std;

long long N, K, arr[10004], ret, l = 1, r;

bool check(int m) {
    int s = 0;
    for (int i = 0; i < K; i++) {
        s += arr[i] / m;
    }

    return s >= N;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        r = max(r, arr[i]);
    }

    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
            ret = max(ret, mid);
        }
        else {
            r = mid - 1;
        }
    }

    cout << ret << '\n';
}