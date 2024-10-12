#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[21][101];
int main()
{
    int N;
    int L[21], J[21], M = -1;
    
    cin>>N;
    for(int i = 1;i<=N;i++){
        cin>>L[i];
    }
        for(int i = 1;i<=N;i++){
        cin>>J[i];
    }
    
    for(int i =1;i<=N;i++){
        for(int j=100;j>=0;j--){
            if(j>L[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-L[i]]+J[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            if(dp[i][j]>=M) M = dp[i][j];
        }
    }
    cout<<M;
}