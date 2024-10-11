#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;

int n, k, a[10001], temp, ret = INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill(a, a + 10001, INF);
    a[0] = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = temp; j <= k; j++) {
            a[j] = min(a[j], a[j - temp] + 1);
        }
    }
    
    if (a[k] == INF) cout << -1 << "\n";
    else cout << a[k] << "\n";
}
