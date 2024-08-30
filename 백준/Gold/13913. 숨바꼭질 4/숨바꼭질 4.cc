#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define max_n 200004    
#define prev aaa
using namespace std;

int N, K, visited[max_n], prev[max_n];
vector<int> v;
void BFS(int _num) {
    queue<int> q;
    q.push(_num);
    visited[_num] = 1;
    while (q.size()) {           
        int pos = q.front();
        q.pop();
        if (pos == K) {
            return;
        }
        for (int k : {pos + 1, pos - 1, 2 * pos}) {
            if (k < 0 || k>=max_n) continue;
            if (!visited[k]) {
                visited[k] = visited[pos] + 1;
                prev[k] = pos;                
                q.push(k);
            }
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    
    if (N == K) {
        cout << 0 << '\n';
        cout << N << '\n';
        return 0;
    }
    

    BFS(N);    
    for (int i = K; i != N; i = prev[i]) {
        v.push_back(i);
    }
    v.push_back(N);
    reverse(v.begin(), v.end());

    cout << visited[K] - 1 << '\n';
    for (int i : v) cout << i << ' ';
 
    return 0;
}