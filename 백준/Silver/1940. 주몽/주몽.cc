#include <iostream>

using namespace std;


int main()
{
    int N, M, num[15000], cnt = 0;
    cin>>N>>M;
    for(int i =0;i<N;i++){
        cin>>num[i];
    }
    
    for(int i = 0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(num[i]+num[j] == M){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
}