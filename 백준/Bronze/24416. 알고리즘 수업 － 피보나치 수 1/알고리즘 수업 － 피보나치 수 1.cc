#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define size 1000001  // N의 최대 크기보다 1 크게 설정
using namespace std;

int dp[50], cnt1, cnt2;

int fib(int n) {

    if (n == 1 || n == 2) {
        cnt1++;
        return 1;
    }

    return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    int &ret = dp[n];
    if (ret != 0) return ret;
    cnt2++;
    return ret = fibonacci(n-1) + fibonacci(n-2);        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    dp[1] = 1; dp[2] = 1;
    fib(N); fibonacci(N);
    cout << cnt1 << " " << cnt2 << "\n";
}
