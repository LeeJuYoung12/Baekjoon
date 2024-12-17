#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

int N, arr[100004][3];
int dpMax[2][3], dpMin[2][3]; // 최대, 최소를 저장할 DP 테이블

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    // 입력 처리
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    // DP 테이블 초기화
    for (int i = 0; i < 3; i++) {
        dpMax[0][i] = arr[0][i];
        dpMin[0][i] = arr[0][i];
    }

    // Bottom-Up DP
    for (int i = 1; i < N; i++) {
        // 최대값 계산
        dpMax[1][0] = arr[i][0] + max(dpMax[0][0], dpMax[0][1]);
        dpMax[1][1] = arr[i][1] + max({dpMax[0][0], dpMax[0][1], dpMax[0][2]});
        dpMax[1][2] = arr[i][2] + max(dpMax[0][1], dpMax[0][2]);

        // 최소값 계산
        dpMin[1][0] = arr[i][0] + min(dpMin[0][0], dpMin[0][1]);
        dpMin[1][1] = arr[i][1] + min({dpMin[0][0], dpMin[0][1], dpMin[0][2]});
        dpMin[1][2] = arr[i][2] + min(dpMin[0][1], dpMin[0][2]);

        // DP 테이블 갱신
        for (int j = 0; j < 3; j++) {
            dpMax[0][j] = dpMax[1][j];
            dpMin[0][j] = dpMin[1][j];
        }
    }

    // 결과 출력
    int maxResult = max({dpMax[0][0], dpMax[0][1], dpMax[0][2]});
    int minResult = min({dpMin[0][0], dpMin[0][1], dpMin[0][2]});
    cout << maxResult << ' ' << minResult << '\n';

    return 0;
}
