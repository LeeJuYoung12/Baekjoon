#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, K, A[14][14], plusA[14][14], ret;
vector<int> tree[14][14];

const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    // 각 칸에 추가될 양분을 입력받음
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> plusA[i][j];
        }
    }
    // 초기 양분은 모든 칸에 5로 설정
    fill(&A[0][0], &A[0][0] + 14 * 14, 5);

    // M개의 나무를 입력받음
    for (int i = 1; i <= M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);  // 좌표 (y, x)에 나무 나이 z를 저장
    }

    // K년 동안 계절 반복
    while (K--) {
        // 봄: 나무가 나이만큼 양분을 먹고, 나이가 1 증가. 먹을 양분이 없으면 죽음.
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (tree[i][j].empty()) continue;  // 나무가 없는 칸은 스킵
                int die_tree = 0;  // 죽은 나무들의 양분
                vector<int> temp;  // 살아남은 나무들
                sort(tree[i][j].begin(), tree[i][j].end());  // 나무를 나이 순으로 정렬
                for (int t : tree[i][j]) {
                    if (A[i][j] >= t) {
                        A[i][j] -= t;  // 나무가 양분을 먹음
                        temp.push_back(t + 1);  // 나무가 나이를 먹음
                    }
                    else {
                        die_tree += t / 2;  // 양분이 부족해 죽은 나무
                    }
                }
                tree[i][j] = temp;  // 살아남은 나무들로 교체
                A[i][j] += die_tree;  // 죽은 나무가 양분으로 변환
            }
        }

        // 가을: 나이가 5의 배수인 나무가 번식
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (tree[i][j].empty()) continue;
                for (int t : tree[i][j]) {
                    if (t % 5 == 0) {  // 나이가 5의 배수인 나무는 번식
                        for (int dir = 0; dir < 8; dir++) {
                            int ny = i + dy[dir];
                            int nx = j + dx[dir];
                            if (ny >= 1 && ny <= N && nx >= 1 && nx <= N) {
                                tree[ny][nx].push_back(1);  // 나이가 1인 나무 번식
                            }
                        }
                    }
                }
            }
        }

        // 겨울: 각 칸에 양분 추가
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                A[i][j] += plusA[i][j];  // 양분 추가
            }
        }
    }

    // 남아 있는 나무 개수 세기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ret += tree[i][j].size();
        }
    }

    cout << ret << "\n";
}
