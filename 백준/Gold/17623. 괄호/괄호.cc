#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define INF 987654321
using namespace std;

int T, N;
char a[6] = { '(', ')', '{', '}', '[', ']' };
string dp[1004];
map<char, char> mp;

bool check(string before, string after) {
    if (before == "" && after == "")return false;
    if (before == "")return true;
    if (before.size() == after.size())return after < before;
    return after.size() < before.size();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 6; i++) {
        mp[i + '1'] = a[i];
    }
    dp[1] = "12";
    dp[2] = "34";
    dp[3] = "56";
    for (int i = 1; i <= 1000; i++) {
        if (i % 2 == 0 && check(dp[i], '1' + dp[i / 2] + '2')) dp[i] = '1' + dp[i / 2] + '2';
        if (i % 3 == 0 && check(dp[i], '3' + dp[i / 3] + '4')) dp[i] = '3' + dp[i / 3] + '4';
        if (i % 5 == 0 && check(dp[i], '5' + dp[i / 5] + '6')) dp[i] = '5' + dp[i / 5] + '6';

        for (int j = 1; j <= i; j++) {
            if (check(dp[i], dp[j] + dp[i - j])) dp[i] = dp[j] + dp[i - j];
        }
        
    }

    cin >> T;
    while (T--) {
        cin >> N;
        for (char a : dp[N]) cout << mp[a];
        cout << "\n";
    }   
}
