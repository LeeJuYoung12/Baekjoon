#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

int A, B, arr[20];// 0이 아니면 소수.
double a, b, dp1[20][20], dp2[20][20], ret;


double go(int idx, int goal, double per) {
    if (idx == 18) {
        return (arr[goal] == 0) ? 1 : 0;
    }
    double& ret = dp1[idx][goal];
    if (ret >= -0.5) return ret;

    return ret = go(idx + 1, goal + 1, per) * per + go(idx + 1, goal, per) * (1 - per);
}
double go2(int idx, int goal, double per) {
    if (idx == 18) {
        return (arr[goal] == 0) ? 1 : 0;
    }
    double& ret = dp2[idx][goal];
    if (ret >= -0.5) return ret;

    return ret = go2(idx + 1, goal + 1, per) * per + go2(idx + 1, goal, per) * (1 - per);
}

void era(int mx) {
    fill(arr, arr + 20, 1);
    arr[0] = 0, arr[1] = 0;
    for (int i = 2; i <= mx; i++) {
        if (arr[i] == 0) {
            continue;
        }
        for (int j = 2 * i; j <= mx; j += i) {
            arr[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    era(20);
    
    cin >> A >> B;
    a = A * 0.01;
    b = B * 0.01;

    ret = 1 - (go(0, 0, a) * go2(0, 0, b));
    printf("%.6f", ret);
}