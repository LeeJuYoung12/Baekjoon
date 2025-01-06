#include <iostream>

using namespace std;

int N, arr[65][65];

void Func(int y, int x, int size){
    
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size;j++){
            if(arr[y][x] != arr[y + i][x + j]){
                cout<<"(";
                Func(y, x, size/2);
                Func(y, x+size/2, size/2);
                Func(y+size/2, x, size/2);
                Func(y+size/2, x+size/2, size/2);
                cout<<")";
                return;
            }
        }
    }
    cout<<arr[y][x];
}
int main()
{
    cin>>N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    Func(0, 0, N);
}