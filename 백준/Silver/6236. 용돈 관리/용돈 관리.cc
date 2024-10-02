#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1987654321

using namespace std;

long long N, M, arr[100004], l, r, mid, ret;

bool check(int mid) {
    int cnt = 1;
    int num = mid;
    for (int i = 0; i < N; i++) {
        if (num - arr[i]>=0) {
            num -= arr[i];
        }
        else {
            num = mid;
            cnt++;
            if (num - arr[i] < 0) {
                return false;
            }
            else {
                num -= arr[i];
            }
        }
    }

    return M >= cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        r += arr[i];
    }
    
    ret = r;

    while (l <= r) {
        
        mid = (l + r) / 2;
        if (check(mid)) {
            ret = min(ret, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    
   
    cout << ret << "\n";
}
