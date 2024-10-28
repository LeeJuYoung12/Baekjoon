#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, arr[100001], visited[100001],X, Y;
   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) arr[i] = i;
    for (int i = 0; i < M; i++) {
        cin >> X >> Y;
        arr[X]++, arr[Y]--;
    }
    for (int i = 1; i <= N; i++) {
        visited[arr[i]]++;
    }
    bool flag = false;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0 || visited[i] >= 2) flag = 1;
    }
    if (flag) cout << -1 << "\n";
    else {
        for (int i = 1; i <= N; i++) {
            cout << arr[i] << " ";
        }
    }
}
