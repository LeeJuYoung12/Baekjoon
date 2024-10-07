#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N;
double arr[10004], ret;
vector<int> v;

double go() {
    double mx = -1e9;
    for (int s = 0; s < N; s++) {
        double cur = 1.0;
        for (int e = s; e < N; e++) {
            cur *= arr[e];
            mx = max(mx, cur);
        }
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    ret = go();
    

    printf("%.3f", ret);
}   
