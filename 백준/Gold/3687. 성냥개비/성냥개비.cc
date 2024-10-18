#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int T, N;
int a[10] = { 6, 2, 5, 5, 4, 5, 6, 3 ,7, 6 };
string dp[104], MAX_STR = "111111111111111111111111111111111111111111111111119";

string findMax(int here) {
    string ret = "";

    if (here & 1) {
       ret += '7'; 
       here -= 3;
    }

    while (here) {
        ret += '1';
        here -= 2;
    }

    return ret;
}

string get_min_str(string a, string b) {
    if (a.size() == b.size()) return ((a < b) ? a : b);
    if (a.size() < b.size()) return a;
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    fill(dp, dp + 104, MAX_STR);
    dp[0] = "";
    for (int i = 2; i < 104; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i - a[j] < 0) continue;
            if (j == 0 && dp[i - a[j]] == "")continue;
            dp[i] = get_min_str(dp[i], dp[i - a[j]] + to_string(j));
        }
    }

    cin >> T;
    while (T--) {
        cin >> N;
        cout << dp[N] << " " << findMax(N) << "\n";
    }
}