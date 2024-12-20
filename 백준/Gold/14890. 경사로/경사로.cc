#include <iostream>
#include <cstring>
using namespace std;

int N, L, arr[104][104], ret;

bool checkRow(int row) {
    int cnt = 1; // 현재 연속된 칸의 수
    for (int j = 1; j < N; j++) {
        if (arr[row][j] == arr[row][j - 1]) { // 같은 높이
            cnt++;
        } else if (arr[row][j] - arr[row][j - 1] == 1) { // 오르막길
            if (cnt >= L) { // L만큼 연속된 칸이 있어야 함
                cnt = 1; // 새로 시작
            } else {
                return false;
            }
        } else if (arr[row][j - 1] - arr[row][j] == 1) { // 내리막길
            if (j + L - 1 >= N) return false; // 경사로 범위를 벗어남
            for (int k = j; k < j + L; k++) { // 내리막길 확인
                if (arr[row][k] != arr[row][j]) return false;
            }
            j += L - 1; // 경사로 설치된 칸만큼 건너뜀
            cnt = 0; // 새로 시작
        } else { // 높이 차이가 1 이상이면 설치 불가
            return false;
        }
    }
    return true;
}

bool checkCol(int col) {
    int cnt = 1; // 현재 연속된 칸의 수
    for (int i = 1; i < N; i++) {
        if (arr[i][col] == arr[i - 1][col]) { // 같은 높이
            cnt++;
        } else if (arr[i][col] - arr[i - 1][col] == 1) { // 오르막길
            if (cnt >= L) { // L만큼 연속된 칸이 있어야 함
                cnt = 1; // 새로 시작
            } else {
                return false;
            }
        } else if (arr[i - 1][col] - arr[i][col] == 1) { // 내리막길
            if (i + L - 1 >= N) return false; // 경사로 범위를 벗어남
            for (int k = i; k < i + L; k++) { // 내리막길 확인
                if (arr[k][col] != arr[i][col]) return false;
            }
            i += L - 1; // 경사로 설치된 칸만큼 건너뜀
            cnt = 0; // 새로 시작
        } else { // 높이 차이가 1 이상이면 설치 불가
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // 가로 방향 검사
    for (int i = 0; i < N; i++) {
        if (checkRow(i)) ret++;
    }

    // 세로 방향 검사
    for (int j = 0; j < N; j++) {
        if (checkCol(j)) ret++;
    }

    cout << ret << "\n";
    return 0;
}
