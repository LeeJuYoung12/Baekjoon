#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

string str;
int N, M, S, E, temp, dp[2504][2504], dp2[2504];

int go(int idx) {
    if (idx == str.length()) return 0;
    if (dp2[idx] != INF) return dp2[idx];
    int& ret = dp2[idx];
    for (int i = 1; idx + i <= str.length(); i++) {
        if (dp[idx][i]) ret = min(ret, go(idx + i) + 1);
    }
    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(dp2, dp2 + 2504, INF);
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        dp[i][1] = 1;
    }
    for (int i = 0; i < str.length()-1; i++) {
        if (str[i] == str[i + 1]) dp[i][2] = 1;
    }
    for (int s = 3; s <= str.length(); s++) {
        for (int i = 0; i + s <= str.length();i++) {
            if (str[i] == str[i + s -1] && dp[i+1][s-2]) dp[i][s] = 1;
        }
    }
    
    cout << go(0) << "\n";      
}