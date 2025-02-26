#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, L[1000004], s = 1, l = 1, mid, ret;

bool check(int a) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += (L[i] / a);
    }

    return cnt >= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        l = max(l, L[i]);
    }

    while (s <= l) {
        mid = (s + l) / 2;
        if (check(mid)) {
            s = mid + 1;
            ret = max(ret, mid);
        }
        else {
            l = mid - 1;
        }
    }

    cout << ret << '\n';
}
    