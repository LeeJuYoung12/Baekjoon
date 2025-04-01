#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

struct State {
    int size, water, days;

    // 최소 힙을 위한 비교 연산자 (물이 적을수록 우선)
    bool operator>(const State& other) const {
        if (days == other.days) return water > other.water;
        return days > other.days;
    }
};

int minWaterToGrow(int N) {
    priority_queue<State, vector<State>, greater<State>> pq;
    unordered_map<int, pair<int, int>> visited; // {크기: {최소 물의 양, 최소 일수}}

    pq.push({ 0, 0, 0 });  // 초기 상태 (size 0, 물 0, 일수 0)
    visited[0] = { 0, 0 };

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        // 목표 크기에 도달하면 결과 출력
        if (cur.size == N) {
            cout << cur.days << " " << cur.water << endl;
            return cur.water;
        }

        // 세 가지 성장 방식
        vector<pair<int, int>> growthMethods = {
            {cur.size + 1, 1},  // 1 증가, 물 1 사용
            {cur.size * 3, 3},  // 3배 성장, 물 3 사용
            {cur.size * cur.size, 5} // 제곱 성장, 물 5 사용
        };

        for (auto& p : growthMethods) {
            int nextSize = p.first;
            int waterCost = p.second;

            // 오버플로우 방지 및 범위 체크
            if (nextSize > N || nextSize < 0) continue;

            int nextWater = cur.water + waterCost;
            int nextDays = cur.days + 1;

            // 더 적은 일수로 도달하거나, 같은 일수라면 더 적은 물 사용한 경우만 업데이트
            if (visited.find(nextSize) == visited.end() ||
                nextDays < visited[nextSize].second ||
                (nextDays == visited[nextSize].second && nextWater < visited[nextSize].first)) {
                visited[nextSize] = { nextWater, nextDays };
                pq.push({ nextSize, nextWater, nextDays });
            }
        }
    }
    return -1;  // 실행되지 않음 (N까지 항상 도달 가능하므로)
}

int main() {
    int N;
    cin >> N;

    minWaterToGrow(N);
    return 0;
}
