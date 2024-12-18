#include <iostream>
#include <cstring>
#define mod 1000000000
using namespace std;

long long dp[101][10][1 << 10], full = (1 << 10) - 1;
int N;

// 계단 수 계산
long long go(int idx, int now, int check) {
    if (now < 0 || now > 9) return 0; // 숫자가 0~9 범위를 벗어나면 종료
    if (idx == N) {
        return (check == full) ? 1 : 0; 
    }

    long long& ret = dp[idx][now][check];
    if (ret != -1) return ret;
    ret = 0;
    ret += (go(idx + 1, now + 1, check | (1 << (now + 1)))) % mod;
    ret += (go(idx + 1, now - 1, check | (1 << (now - 1)))) % mod;
    return ret % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    // DP 배열 초기화
    memset(dp, -1, sizeof(dp));

    long long ret = 0;

    // 1부터 9까지의 숫자로 시작하는 경우를 계산
    for (int i = 1; i <= 9; i++) {
        ret += (go(1, i, (1 << i))); // i번째 숫자로 시작
    }

    cout << ret % mod << "\n";
    return 0;
}
