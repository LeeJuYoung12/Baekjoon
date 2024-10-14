#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[10][10], cnt[6] = { 0, 5, 5, 5, 5, 5 }; // 1x1부터 5x5까지 색종이 5개씩
int ret = 1e9; // 최솟값을 구하기 위해 큰 값으로 초기화

// 해당 위치에 크기가 size인 색종이를 붙일 수 있는지 확인
bool canAttach(int y, int x, int size) {
    if (y + size > 10 || x + size > 10) return false; // 범위 체크
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (arr[i][j] == 0) return false; // 0이 있으면 붙일 수 없음
        }
    }
    return true;
}

// 색종이를 붙이거나 떼는 함수
void attach(int y, int x, int size, int state) {
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            arr[i][j] = state; // state가 0이면 색종이를 떼고, 1이면 붙임
        }
    }
}

// 백트래킹으로 최소 색종이 수 찾기
void go(int y, int x, int used) {
    if (x == 10) {
        go(y + 1, 0, used); // 다음 행으로 이동
        return;
    }
    if (y == 10) {
        ret = min(ret, used); // 최솟값 갱신
        return;
    }
    if (arr[y][x] == 0) {
        go(y, x + 1, used); // 빈 칸이면 오른쪽으로 이동
        return;
    }

    for (int size = 5; size >= 1; size--) {
        if (cnt[size] > 0 && canAttach(y, x, size)) { // 색종이를 붙일 수 있으면
            attach(y, x, size, 0); // 색종이를 붙임 (0으로 만들기)
            cnt[size]--;
            go(y, x + size, used + 1); // 다음 칸으로 이동
            attach(y, x, size, 1); // 되돌리기
            cnt[size]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
        }
    }

    go(0, 0, 0); // 백트래킹 시작
    if (ret == 1e9) cout << -1 << "\n"; // 불가능한 경우
    else cout << ret << "\n"; // 가능한 최소 색종이 수
}
