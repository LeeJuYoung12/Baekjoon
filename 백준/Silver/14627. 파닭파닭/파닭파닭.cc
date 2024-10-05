#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

long long S, C, L, r, ret, sum;
vector<long long> v;

bool check(long long mid) {
    long long cnt = 0;
    for (int i = 0; i < S; i++) {
        cnt += v[i] / mid;
    }
    return cnt >= C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> S >> C;
    
    for (int i = 0; i < S; i++) {
        cin >> L;
        sum += L;
        v.push_back(L);
    }
    
    sort(v.begin(), v.end());
    long long l = 1, r = v[S - 1], mid;

    while (l <= r) {
        mid = (l + r) / 2;
      
        if (check(mid)) {//가능. 작아지는 경우
            l = mid + 1; 
            ret = mid;
        }
        else {
            r = mid - 1;
        }        
    }

    cout << sum - ret * C << "\n";
}   
