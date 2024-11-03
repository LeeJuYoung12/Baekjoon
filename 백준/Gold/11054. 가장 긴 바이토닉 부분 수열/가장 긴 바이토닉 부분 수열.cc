#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;

int N, arr[1001], dp_inc[1001], dp_dec[1001];

// 증가 부분 수열 길이 계산
int lis(int idx) {
    if (dp_inc[idx] != -1) return dp_inc[idx];
    dp_inc[idx] = 1; // 최소 길이 1 (자기 자신만 포함한 수열)
    for (int i = 0; i < idx; i++) {
        if (arr[i] < arr[idx]) {
            dp_inc[idx] = max(dp_inc[idx], lis(i) + 1);
        }
    }
    return dp_inc[idx];
}

// 감소 부분 수열 길이 계산
int lds(int idx) {
    if (dp_dec[idx] != -1) return dp_dec[idx];
    dp_dec[idx] = 1; // 최소 길이 1 (자기 자신만 포함한 수열)
    for (int i = idx + 1; i < N; i++) {
        if (arr[i] < arr[idx]) {
            dp_dec[idx] = max(dp_dec[idx], lds(i) + 1);
        }
    }
    return dp_dec[idx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(dp_inc, -1, sizeof(dp_inc));
    memset(dp_dec, -1, sizeof(dp_dec));

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int ret = 0;
    for (int i = 0; i < N; i++) {
        ret = max(ret, lis(i) + lds(i) - 1); // 현재 인덱스 i에서 바이토닉 수열 길이 계산
    }

    cout << ret << "\n";
}
