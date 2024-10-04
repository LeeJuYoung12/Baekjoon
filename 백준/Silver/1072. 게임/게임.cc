#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e18

using namespace std;

long long X, Y, now, ret = -1, mid, l = 1, r = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> X >> Y;
    now = Y * 100 / X;
    while (l <= r) {
        mid = (l + r) / 2;
        if ((Y + mid) * 100 / (X + mid) > now) {
            ret = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ret << "\n";
}
