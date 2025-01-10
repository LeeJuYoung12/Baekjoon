#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        int ret1 = 0, ret2 = 0;
        for (int j = 2; j <= N; j*=2) {
            ret1 += N / j;
        }
        for (int j = 5; j <= N; j *= 5) {
            ret2 += N / j;
        }
        cout << min(ret1, ret2) << '\n';
    }
}