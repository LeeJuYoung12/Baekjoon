#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

long long N, A[104], dp[104][24], ret;

bool check(long long a, long long b, long long oper) {
    long long temp;
    if (oper == 0) {  // 덧셈
        temp = a + b;
    }
    else if (oper == 1) {  // 뺄셈
        temp = a - b;
    }
    else {
        return false;
    }
    return temp >= 0 && temp <= 20;  // 유효 범위 확인
}

void go(int s, int idx) {
    if (idx == N - 1) {  // 마지막까지 탐색
        return;
    }
    // 0: 덧셈
    if (check(s, A[idx + 1], 0)) {
        long long temp = s + A[idx + 1];
        dp[idx + 1][temp] += dp[idx][s];
    }
    // 1: 뺄셈
    if (check(s, A[idx + 1], 1)) {
        long long temp = s - A[idx + 1];
        dp[idx + 1][temp] += dp[idx][s];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    dp[0][A[0]] = 1;  // 시작 상태 초기화

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i][j] > 0) {
                go(j, i);  // 현재 숫자와 인덱스에서 가능한 연산 호출
            }
        }
    }

    cout << dp[N - 2][A[N - 1]] << "\n";  // 마지막 결과 출력
}
