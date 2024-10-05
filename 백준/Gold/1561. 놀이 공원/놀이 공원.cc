#include <iostream>
#include <vector>
#include <algorithm>
#define INF 60000000004

using namespace std;

long long N, M, t, ret, l, r = INF, mid, temp;
vector<int> v;

bool check(long long mid) {
    temp = M;
    for (long long i = 0; i < M; i++) {
        temp += mid / v[i];
    }
    return temp >= N;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> t;
        v.push_back(t);
    }
    
    if (N <= M) {
        cout << N;
        return 0;
    }

    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ret = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    temp = M;
    for (long long i = 0; i < M; i++) {
        temp += (ret - 1) / v[i];
    }

    for (long long i = 0; i < M; i++) {
        if (ret % v[i] == 0)temp++;
        if (temp == N) {
            cout << i + 1 << "\n";
            return 0;
        }
    }

    return 0;
}   
