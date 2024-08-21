#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N, T, ret, five = 0, two = 0;
    cin>>T;
    for(int i = 0; i<T;i++){
        cin>>N;
        two = 0; five = 0;
        for(int j = 2;j<=N;j*=2){
            two += N/j;
        }
        for(int j = 5;j<=N;j*=5){
            five += N/j;
        }
        ret = min(five, two);
        cout<<ret<<'\n';
        
    }
    
}