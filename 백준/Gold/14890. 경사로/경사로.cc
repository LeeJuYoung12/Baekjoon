#include <iostream>
#include <cstdlib>
using namespace std;

int N, L, arr1[105][105], arr2[105][105], ret;

void go(int arr[][105]){
    for(int i = 0;i<N;i++){
        bool check = true;
        int visited[105] = {0};
        for(int j = 0;j<N-1;j++){

            int height = arr[i][j+1] - arr[i][j]; 

            if(abs(height)>1){
                check = false;
                break;
            } 
            if(height == 1){
                
                int value = arr[i][j];
                for(int k = j;k>j-L;k--){
                   if(k <0||visited[k]||arr[i][k] != value){
                        check = false;
                        break;
                    }
                    else{
                        visited[k] = true;
                    }
    
                }
            }
            if(height== -1){
                
                int value = arr[i][j+1];
                for(int k = j+1;k<= j + L ;k++){
                    if(k >=N||visited[k]||arr[i][k] != value){
                        check = false;
                        break;
                    }
                    else{
                        visited[k] = true;
                    }
    
                }
            }

            
            if(!check) break;
        }
        if(check) ret++;
    }
} 

int main()
{
    cin>>N>>L;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin>>arr1[i][j];
            arr2[j][i] = arr1[i][j];
        }
    }
    //행을 기준으로 풀거임
    go(arr1);
    go(arr2);
    cout<<ret;
    return 0;
}