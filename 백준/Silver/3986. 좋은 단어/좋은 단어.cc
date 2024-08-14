#include <iostream>
#include <stack>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, cnt = 0;;
    string str;
    stack<char> stk;
    
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>str;
        for(int i = 0;i<str.length();i++){
            if(stk.empty()){
                stk.push(str[i]);
            }
            else if(stk.top() == str[i]){
                stk.pop();
            }
            else{          
                stk.push(str[i]);

            }
        }
        if(stk.empty()){
            cnt++;
        }
        else{
            while(!stk.empty()){
                stk.pop();
            }
        }
    }
    cout<<cnt;
}