#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

int N, M;
long long f[44] = { 0, 5, 13 };
string str = "Messi Gimossi";
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> M;
    M--;
    for (int i = 3; i <= 41; i++) {
        f[i] = f[i - 1] + f[i - 2] + 1;
    }
    for (int i = 41; i >= 2; i--) {
        if (M >= f[i]) M -= (f[i] + 1);
    }
    if (M == 5 || M == -1) cout << "Messi Messi Gimossi" << "\n";
    else cout << str[M] << "\n";
}
