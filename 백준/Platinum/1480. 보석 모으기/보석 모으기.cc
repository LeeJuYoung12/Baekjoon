#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, C, temp, dp[24][1<<14][24];
vector<int> v;

int go(int idx, int ju, int capacity) {
    if (idx == M) return 0;
    int& ret = dp[idx][ju][capacity];
    if (ret) return ret;
    ret = max(ret, go(idx + 1, ju, C));
    for (int i = 0; i < N; i++) {
        bool isBefore = (1 << i)& ju;
        bool isCan = (capacity - v[i]) >= 0;
        if (!isBefore && isCan) ret = max(ret, go(idx, ju | (1 << i), capacity - v[i])+1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    
    cout << go(0, 0, C) << "\n";
}