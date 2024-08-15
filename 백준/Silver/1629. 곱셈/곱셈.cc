#include <iostream>

using namespace std;

long long A, B, C;

long long go(long long A, long long B){
    if(B == 1) return A%C;
    
    long long ret = go(A, B/2);
    ret = (ret * ret) % C;
    if(B%2) ret = (ret * A) % C;
    return ret;
}
int main()
{
  cin>>A>>B>>C;
  cout<<go(A, B)<<"\n";
}