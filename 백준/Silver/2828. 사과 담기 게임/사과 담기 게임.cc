#include <iostream>

using namespace std;

int main()
{
    int N, M, J, temp, pos = 1, cnt = 0;
    cin>>N>>M;
    cin>>J;
    for(int i = 0;i<J;i++){
        cin>>temp;
        if(pos<=temp && pos + M>temp){
            
        }
        else{
            while(!(pos<=temp && pos + M>temp))
            if(pos>temp){
                pos--;
                cnt++;
            }
            else{
                pos++;
                cnt++;
            }
        }
    }
    cout<<cnt;
}