#include <iostream>

using namespace std;

int X, ret = 1;

int main()
{
    cin>>X;
    while(X != 1){
    if(X&1) ret++;    
    X/=2;
    }
    
    cout<<ret;
}