#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define max_n 500000   
#define prev aaa
using namespace std;

int N, K, visited[2][500004], turn = 1;
vector<int> v;
bool ok;
void BFS(int _num) {
    queue<int> q;
    q.push(_num);
    visited[0][_num] = 1;
    while (q.size()) {
        K += turn;
        if (K > max_n) break;
        if (visited[turn % 2][K]) {
            ok = true;
            break;
        }
        int qSzie = q.size();
        for (int i = 0; i < qSzie; i++) {
            int pos = q.front();
            q.pop();
            
            for (int next : {pos + 1, pos - 1, 2 * pos}) {
                if (next < 0 || next > max_n||visited[turn%2][next]) continue;
                    visited[turn % 2][next] = visited[(turn + 1) % 2][pos] + 1;
                    
                    if (next == K) {
                        ok = 1;
                        break;                    }
                    q.push(next);
            }
            if (ok) break;
        }       
        if (ok) break;
        turn++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (N == K) {
        cout << 0 << '\n';
        return 0;
    }


    BFS(N);
    if (ok) cout << turn << "\n";
    else cout << -1 << "\n";

    return 0;
}