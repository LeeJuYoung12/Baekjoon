#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

long long N, arr[500004], ret;
stack<pair<long long, long long>> stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

   
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        while (stk.size() && stk.top().first <= arr[i]) {
            ret += stk.top().second;
            if (stk.top().first == arr[i]) {
                cnt = stk.top().second + 1;
            }
            else {
                cnt = 1;
            }
            stk.pop();
        }
        if (stk.size()) ret++;
        stk.push({ arr[i], cnt });
    } 
    
    cout << ret;
}