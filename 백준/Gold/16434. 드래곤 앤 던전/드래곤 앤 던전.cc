#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1e18

using namespace std;

long long N, atk, nowHeart, t[123457], a[123457], h[123457], ret;

bool check(long long mid) {
    long long now = mid, tempAtk = atk;
    for (int i = 0; i < N; i++) {
        if (t[i] == 1) {
            long long cnt = h[i] / tempAtk + (h[i] % tempAtk ? 1 : 0);
            now -= (cnt - 1) * a[i];            
            if (now <= 0) return false;
        }
        else {
            now = min(mid, now + h[i]);
            tempAtk += a[i];
        }
    }

    return now > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> atk;

    for (int i = 0; i < N; i++) {
        cin >> t[i] >> a[i] >> h[i];        
    }
    
    long long l = 1, r = INF, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {            
            r = mid - 1;
            ret = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ret<<"\n";

}