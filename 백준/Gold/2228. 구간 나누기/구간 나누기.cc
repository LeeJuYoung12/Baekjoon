#include <iostream>
#include <cstring>
#include <algorithm>
#define INF -987654321
using namespace std;

int N, M, arr[104], dp[104][54]; // DP 배열: [현재 위치][남은 구간 수]

// DP 함수: idx 위치부터 시작해서 cnt개의 구간을 나눌 때의 최대 합 계산
int go(int idx, int cnt) {
    if (cnt == 0) return 0; // 더 나눌 구간이 없으면 0 반환
    if (idx >= N) return INF; // 인덱스가 배열 끝을 초과하면 음의 무한대 반환

    int& ret = dp[idx][cnt];
    if (ret != -1) return ret;

    ret = go(idx + 1, cnt); // 현재 위치를 포함하지 않는 경우
    int sum = 0;

    // 현재 위치부터 새로운 구간 시작
    for (int i = idx; i < N; i++) {
        sum += arr[i];
        ret = max(ret, sum + go(i + 2, cnt - 1)); // 다음 구간과 최소 한 칸 떨어져야 함
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0, M) << "\n";

    return 0;
}
