#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
vector<int> adj[10001]; // 각 노드에서 다른 노드로의 방향성 간선을 저장하는 인접 리스트
int result[10001]; // 각 노드에서 시작했을 때 도달할 수 있는 노드의 수를 저장

void bfs(int start) {
    bool visited[10001] = {false};
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int count = 1; // 시작 노드도 도달 가능한 노드 수에 포함
    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int next: adj[current]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++; // 다음 노드에 도달할 수 있으므로 카운트 증가
            }
        }
    }

    result[start] = count; // 시작 노드에서 도달할 수 있는 노드의 총 수 저장
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a); // b를 해킹하면 a를 해킹할 수 있다는 의미
    }

    int maxCount = 0; // 가장 많은 노드에 도달할 수 있는 경우의 수
    for(int i = 1; i <= N; i++) {
        bfs(i); // 각 노드에서 BFS 수행
        maxCount = max(maxCount, result[i]); // 최대 도달 가능 노드 수 갱신
    }

    for(int i = 1; i <= N; i++) {
        if(result[i] == maxCount) { // 가장 많은 노드에 도달할 수 있는 노드 출력
            cout << i << " ";
        }
    }

    return 0;
}
