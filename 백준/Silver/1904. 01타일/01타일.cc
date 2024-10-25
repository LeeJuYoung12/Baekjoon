#include <iostream>

using namespace std;

long long tile[1000001];

void tileFunc(int n){
    for(int i = 5;i<=n;i++){
        tile[i] = (tile[i-1] + tile[i-2])%15746;
    }
}
int main()
{
    int N;
    tile[1] = 1;//1
    tile[2] = 2;//11 00
    tile[3] = 3;//001 100 111
    tile[4] = 5;//0000 0011 1001 1100 1111 [3] + [2]
    cin>>N;
    tileFunc(N);
    cout<<tile[N];
}