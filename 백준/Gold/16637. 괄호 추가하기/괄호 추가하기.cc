#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ret = -9999999;
string str;
vector<int> num;
vector<char> str_oper;

int oper(char a, int b, int c){
    if(a=='+') return b + c;
    if(a=='-') return b - c;
    if(a=='*') return b * c;
    return 0;
}

void go(int here, int _num){
    if(here == num.size() - 1){
        ret = max(ret, _num);
        return;
    }
    go(here + 1, oper(str_oper[here], _num, num[here + 1]));
    if(here + 2 <= num.size() - 1){
        int temp = oper(str_oper[here+1], num[here + 1], num[here + 2]);
        go(here + 2, oper(str_oper[here], _num, temp));
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>str;
    for(int i = 0;i<N;i++){
        if(i%2==0){
            num.push_back(str[i]-'0');
        }
        else{
            str_oper.push_back(str[i]);
        }
    }
    
    go(0, num[0]);
    cout<<ret;
    return 0;
}