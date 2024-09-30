#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

int N, M, T, arr[54][54], x[54], d[54], k[54], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= T; i++) {
        cin >> x[i] >> d[i] >> k[i];
    }

    for (int i = 1; i <= T; i++) {
        //돌리고.
        for (int j = x[i]; j <= N; j += x[i]) {
            for (int w = 1; w <= k[i]; w++) {
                if (d[i] == 0) {
                    int temp = arr[j][M];
                    for (int z = M-1; z >= 1; z--) {
                        arr[j][z + 1] = arr[j][z];
                    }
                    arr[j][1] = temp;
                }
                else if (d[i] == 1) {
                    int temp = arr[j][1];
                    for (int z = 1; z <M; z++) {
                        arr[j][z] = arr[j][z+1];
                    }
                    arr[j][M] = temp;
                }
            }
        }
        //조정하고
        bool check = false;
        int tempArr[54][54];  // 값을 임시로 저장할 배열
        memcpy(tempArr, arr, sizeof(arr));  // 배열 복사

        // 행에서 인접한 값 체크
        for (int j = 1; j <= N; j++) {
            for (int w = 1; w < M; w++) {
                if (arr[j][w] == arr[j][w + 1] && arr[j][w] != 0) {
                    tempArr[j][w] = 0;
                    tempArr[j][w + 1] = 0;
                    check = true;
                }
            }
            // 원형으로 첫 번째와 마지막 원소 체크
            if (arr[j][1] == arr[j][M] && arr[j][1] != 0) {
                tempArr[j][1] = 0;
                tempArr[j][M] = 0;
                check = true;
            }
        }

        // 열에서 인접한 값 체크
        for (int w = 1; w <= M; w++) {
            for (int j = 1; j < N; j++) {
                if (arr[j][w] == arr[j + 1][w] && arr[j][w] != 0) {
                    tempArr[j][w] = 0;
                    tempArr[j + 1][w] = 0;
                    check = true;
                }
            }
        }

        // 배열을 갱신
        memcpy(arr, tempArr, sizeof(tempArr));

        if (!check) {
            int cnt = 0;
            float sum = 0;
            for (int j = 1; j <= N; j++) {
                for (int w = 1; w <= M; w++) {
                    if (arr[j][w] != 0) {
                        sum += arr[j][w];
                        cnt++;
                    }
                }
            }

            if (cnt != 0) {
                float avg = sum / cnt;
                for (int j = 1; j <= N; j++) {
                    for (int w = 1; w <= M; w++) {
                        if (arr[j][w] != 0) {
                            if (arr[j][w] > avg) {
                                arr[j][w]--;  // 평균보다 크면 감소
                            }
                            else if (arr[j][w] < avg) {
                                arr[j][w]++;  // 평균보다 작으면 증가
                            }
                            // 평균과 같을 경우 아무런 변화 없음
                        }
                    }
                }
            }
        }
    }


    for (int j = 1; j <= N; j++) {
        for (int w = 1; w <= M; w++) {
            if (arr[j][w] != 0) {
                ret += arr[j][w];
            }
        }
    }

    cout << ret << "\n";
}
