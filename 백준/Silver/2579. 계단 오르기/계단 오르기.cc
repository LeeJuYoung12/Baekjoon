#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#define INF 987654321
using namespace std;

int N, arr[304], dp[304][3];

int go(int idx, int cnt) {
    if (cnt >= 3) return -INF;

    if (idx == N) {  // 배열 끝까지 도달했을 때
        return 0;
    }
    else if (idx > N) {  // 배열을 초과할 때
        return -INF;
    }
    

    int& ret = dp[idx][cnt];
    if (ret != -1) return ret;  // dp 초기화가 -1임을 고려해 사용

    return ret = max(go(idx + 1, cnt + 1) + arr[idx + 1], go(idx + 2, 1) + arr[idx + 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));  // dp 초기화를 -1로

    cout << go(0, 0) << "\n";  // 0번째 계단에서 시작하도록 수정
}
