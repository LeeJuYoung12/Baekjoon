#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, visited[104][104], ret;
int dy[] = { 0, -1, 0, 1 };  // 우, 상, 좌, 하 순서
int dx[] = { 1, 0, -1, 0 };
int dy1[] = { 0, 0, 1, 1 };  // 사각형 체크용
int dx1[] = { 0, 1, 1, 0 };

struct Drc {
    int x, y, d, g;
} drc[20];

// 드래곤 커브를 그리는 함수
void go(int idx) {
    int y = drc[idx].y;
    int x = drc[idx].x;
    int d = drc[idx].d;
    int g = drc[idx].g;

    vector<int> directions;
    directions.push_back(d);  // 시작 방향 추가

    // 각 세대에 대해 반전 + 시계방향 회전 처리
    for (int i = 0; i < g; i++) {
        int size = directions.size();
        for (int j = size - 1; j >= 0; j--) {
            directions.push_back((directions[j] + 1) % 4);  // 반전 후 시계방향 회전
        }
    }

    // 드래곤 커브 그리기
    visited[y][x] = 1;  // 시작점 방문 처리
    for (int dir : directions) {
        y += dy[dir];
        x += dx[dir];
        if (y >= 0 && y <= 100 && x >= 0 && x <= 100) {  // 범위 내일 때만 처리
            visited[y][x] = 1;
        }
    }
}

// 사각형의 개수를 세는 함수
void check() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (visited[i][j] && visited[i + dy1[1]][j + dx1[1]] &&
                visited[i + dy1[2]][j + dx1[2]] && visited[i + dy1[3]][j + dx1[3]]) {
                ret++;  // 4개의 꼭짓점이 모두 방문된 경우 사각형 카운트
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> drc[i].x >> drc[i].y >> drc[i].d >> drc[i].g;
        go(i);  // 드래곤 커브 그리기
    }

    check();  // 사각형 개수 세기

    cout << ret << "\n";  // 결과 출력
}
