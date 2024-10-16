#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

string str;
int dp[2504][2504];  // 팰린드롬 여부 저장
int minCut[2504];    // 최소 분할 횟수 저장

// 팰린드롬 여부를 확인하는 함수
int go(int l, int r) {
    if (l > r) return 1;

    int& ret = dp[l][r];
    if (ret != -1) return ret;

    if (str[l] != str[r]) return ret = 0;

    if (l == r) return ret = 1;
    else return ret = go(l + 1, r - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> str;
    int n = str.length();

    // dp 배열을 -1로 초기화
    memset(dp, -1, sizeof(dp));

    // 팰린드롬 여부 미리 계산
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            go(i, j);
        }
    }

    // 최소 분할 횟수 계산
    for (int i = 0; i < n; i++) {
        // 전체 구간이 팰린드롬이면 분할 횟수는 1
        if (go(0, i)) {
            minCut[i] = 1;
        } else {
            minCut[i] = 1e9; // 매우 큰 값으로 초기화
            for (int j = 0; j < i; j++) {
                if (go(j + 1, i)) { // j+1부터 i까지가 팰린드롬인 경우
                    minCut[i] = min(minCut[i], minCut[j] + 1);
                }
            }
        }
    }

    // 결과 출력 (최소 분할 횟수)
    cout << minCut[n - 1] << "\n";

    return 0;
}
