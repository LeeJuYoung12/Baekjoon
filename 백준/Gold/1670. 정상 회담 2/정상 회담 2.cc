#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 987654321;

int N, dp[10004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    // N이 홀수면 올바른 괄호 문자열을 만들 수 없음
    if (N % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    dp[0] = 1; // 길이가 0인 경우
    dp[2] = 1; // 길이가 2인 경우

    // 길이가 짝수일 때만 dp를 계산
    for (int i = 4; i <= N; i += 2) {
        dp[i] = 0; // 초기화
        for (int j = 0; j <= i - 2; j += 2) {
            dp[i] = (dp[i] + 1LL * dp[j] * dp[i - j - 2] % MOD) % MOD;
        }
    }

    cout << dp[N] << '\n';
    return 0;
}
