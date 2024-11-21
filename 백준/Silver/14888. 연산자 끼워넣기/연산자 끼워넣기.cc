#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define INF 1987654321
using namespace std;

int N, A[104], oper[4], maxRet =-INF, minRet = INF;
void go(int idx, int now, int a, int b, int c, int d) {
    if (idx == N - 1) {
        minRet = min(minRet, now);
        maxRet = max(maxRet, now);
        return;
    }

    if (a > 0) go(idx + 1, now + A[idx + 1], a - 1, b, c, d); 
    if (b > 0) go(idx + 1, now - A[idx + 1], a, b - 1, c, d);
    if (c > 0) go(idx + 1, now * A[idx + 1], a, b, c - 1, d);
    if (d > 0) go(idx + 1, now / A[idx + 1], a, b, c, d - 1);

    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }
    go(0, A[0], oper[0], oper[1], oper[2], oper[3]);
    cout << maxRet << "\n" << minRet << "\n";
}