#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX_N 1000004
#define INF 1e9+4
using namespace std;

long long N, arr[MAX_N], lis[MAX_N], len;
vector<long long> retV;
pair<int, int> ans[MAX_N];
stack<int> stk;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    fill(lis, lis + MAX_N, INF);

    for (int i = 0; i < N; i++) {
        auto lowerPos = lower_bound(lis, lis + len, arr[i]);
        int _pos = (int)(lower_bound(lis, lis + len, arr[i]) - lis);
        if (*lowerPos == INF) len++;
        *lowerPos = arr[i];
        ans[i].first = _pos;
        ans[i].second = arr[i];
    }

    cout << len << "\n";
    for (int i = N - 1; i >= 0; i--) {
        if (ans[i].first == len - 1) {
            stk.push(ans[i].second);
            len--;
        }
    }
    while (stk.size()) {
        cout<<stk.top()<<" ";
        stk.pop();
    }
}   
