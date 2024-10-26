#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
using namespace std;

int N, K, S, A[404][404], a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        A[a][b] = -1;
        A[b][a] = 1;
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (A[i][k] == 1 && A[k][j] == 1) A[i][j] = 1;
                else if(A[i][k] == -1 && A[k][j] == -1) A[i][j] = -1;
            }
        }
    }
    cin >> S;
    for (int i = 0; i < S; i++) {
        cin >> a >> b;
        cout << A[a][b] << "\n";
    }

}