#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
#define INF 987654321
using namespace std;

int N, arr[1004], dp[1004], ret;

int lis(int start) {
    int& ret = dp[start + 1];
    if (ret != 0) return ret;
    ret = 1;
    for (int i = start + 1; i < N; i++) {
        if (start == -1 || arr[start] < arr[i]) {
            ret = max(ret, lis(i) + 1);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << lis(-1)-1 << "\n";
}