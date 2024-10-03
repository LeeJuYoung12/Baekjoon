#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1987654321

using namespace std;

long long N, M, A[200001], B[200001], cnt, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    
    sort(A, A + N);
    sort(B, B + M);

    for (int i = 0; i < N; i++) {
        long long l = 0, r = M - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (A[i] < B[mid]) {
                r = mid - 1;
            }
            else if (A[i] > B[mid]) {
                l = mid + 1;
            }
            else {
                cnt++;
                break;
            }
        }
    }
    ret = N + M - 2 * cnt;
    cout << ret << "\n";
}