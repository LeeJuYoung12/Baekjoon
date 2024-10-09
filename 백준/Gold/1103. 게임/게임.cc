#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 1e9
using namespace std;

int N, M, arr[54][54], dp[54][54], visited[54][54];
int dy[] = { 0, -1 , 0, 1 };
int dx[] = { -1, 0, 1, 0 };
string str;

int go(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= M) return 0; // 범위를 벗어나면 멈춤
    if (arr[y][x] == 0) return 0; // 구멍이거나 더 이상 이동할 수 없을 때

    if (visited[y][x]) return INF; // 사이클을 탐지했을 때
    if (dp[y][x] != -1) return dp[y][x]; // 이미 계산된 경우

    visited[y][x] = 1; // 현재 위치 방문 표시
    dp[y][x] = 0; // 최소값을 구하기 위해 0으로 설정

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * arr[y][x];
        int nx = x + dx[i] * arr[y][x];
        dp[y][x] = max(dp[y][x], go(ny, nx) + 1); // 가능한 최대 이동 횟수 계산
    }

    visited[y][x] = 0; // 방문 표시 해제
    return dp[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M; // N과 M 입력 받기
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            if (str[j] == 'H') arr[i][j] = 0; // 구멍인 경우 0으로 처리
            else arr[i][j] = str[j] - '0'; // 숫자를 그대로 배열에 저장
        }
    }

    memset(dp, -1, sizeof(dp)); // dp 배열을 -1로 초기화
    int ret = go(0, 0);

    if (ret >= INF) {
        cout << -1 << "\n"; // 게임 오버
    }
    else {
        cout << ret << "\n"; // 최대 이동 횟수 출력
    }
}
