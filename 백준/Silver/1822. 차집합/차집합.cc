#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, x, s, e, mid;
vector<int> A, B, ret;


void go(int a) {
    s = 0, e = M - 1;
    while (s <= e) {
        mid = (s + e) / 2;
        if (a > B[mid]) {
            s = mid + 1;
        }
        else if (a == B[mid]) {
            return;
        }
        else {
            e = mid - 1;
        }
    }
    ret.push_back(a);
    return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> x;
        A.push_back(x);
    }
    for (int i = 0; i < M; i++) {
        cin >> x;
        B.push_back(x);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < N; i++) {
        go(A[i]);
    }

    if (ret.empty()) {
        cout << 0 << '\n';
    }
    else {
        cout << ret.size() << '\n';
        for (auto it : ret) {
            cout << it << ' ';
        }
    }
}
