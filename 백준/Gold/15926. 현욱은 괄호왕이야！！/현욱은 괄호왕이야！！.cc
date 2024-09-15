#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int N, d[200000], ret;
string str;

void go() {
    int cnt = 0;
    stack<int> stk;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            stk.push(i);
        }
        else if (stk.size()) {
            d[stk.top()] = d[i] = 1;
            stk.pop();
        }
    }

    
}

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    cin >> str;
    go();
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (d[i] == 1) {
            cnt++;
            ret = max(ret, cnt);
        }
        else {
            cnt = 0;
        }
    }
    cout<<ret<<'\n';
        
}