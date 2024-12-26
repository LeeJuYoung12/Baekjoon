#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, arr[54][54], ret = INF;//0빈칸 1집 2치킨집
vector<pair<int, int>> chicken, house, temp;

int checkFunc() {
    int ret = 0;
    for (int i = 0; i < house.size(); i++) {
        int distance = INF;
        for (auto there : temp) {
            int tempDistance = abs(there.first - house[i].first) + abs(there.second - house[i].second);
            distance = min(distance, tempDistance);
        }
        ret += distance;
    }

    return ret;
}

void go(int idx, int cnt) {
    if (cnt == M) {
        ret = min(ret, checkFunc());
        return;
    }
    if (idx == chicken.size()) return;

    go(idx + 1, cnt);

    temp.push_back(chicken[idx]);
    go(idx + 1, cnt + 1);
    temp.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) house.push_back({ i,j });
            else if (arr[i][j] == 2) chicken.push_back({ i,j });
        }
    }

    go(0, 0);
    cout << ret << '\n';
}
