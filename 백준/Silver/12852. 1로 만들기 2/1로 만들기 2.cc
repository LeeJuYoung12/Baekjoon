#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main()
{
    int N;
    cin>>N;
    dp[1] = 0;
    for(int i = 2;i<=N;i++){
        dp[i] = i;
        if(i%3 == 0){
            dp[i] = min(dp[i], dp[i/3]);
        }
        if(i%2 == 0){
            dp[i] = min(dp[i], dp[i/2]);
        }
        dp[i] = min(dp[i], dp[i-1])+1;
        
    }
    cout<<dp[N]<<endl;
    while(N>0){
        cout<<N<<' ';
        if(N%3==0 && dp[N] == dp[N/3] + 1){
            N /= 3;
        }
        else if(N%2==0 && dp[N] == dp[N/2] + 1){
            N /= 2;
        }
        else{
            N -= 1;
        }
        
    }
    
}