#include <iostream>
#include <algorithm>
using namespace std;


int N, M;
int arr[5][5], ret;

int main()
{
    cin>>N>>M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    for(int s = 0;s<(1<<(N*M));s++){
        int sum = 0;
        for(int i = 0;i<N;i++){
            int cur = 0;
            for(int j = 0;j<M;j++){
                int k = i * M + j;
                if((s&(1<<k)) == 0){
                    cur = cur * 10 + arr[i][j];
                }
                else{
                    sum += cur;
                    cur = 0 ;
                }
            }
            
            sum += cur;
        }
        
        for(int i = 0;i<M;i++){
            int cur = 0;
            for(int j = 0;j<N;j++){
                int k = j * M + i; 
                if((s&(1<<k)) != 0){
                    cur = cur * 10 + arr[j][i];
                }
                else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        
        ret = max(ret, sum);
    }
    cout<<ret;
}