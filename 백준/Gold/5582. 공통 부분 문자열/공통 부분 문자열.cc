#include <iostream>
#include <cstring>
#define mod 1000000000
using namespace std;

string str1, str2;
int dp[4004][4004], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str1 >> str2;
    
    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < str2.length(); j++)
        {
            if (str1[i] == str2[j]) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ret = max(ret, dp[i][j]);
                }
                else {
                    dp[i][j] = 1;
                }
            }
        }
    }
    cout << ret << "\n";
}
