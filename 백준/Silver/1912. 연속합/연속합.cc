#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, arr[100004], ret = -1004, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum += arr[i];
        ret = max(ret, sum);
        if (sum < 0)sum = 0;
    }
    cout << ret;    
}
