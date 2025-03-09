#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, temp, ret, l, r, s;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        l = 0, r = N-1;
        while (l < r) {
            if (l == i) {
                l++;
                continue;
            }
            if (r == i) {
                r--;
                continue;
            }

            s = v[l] + v[r];
            if (s == v[i]) {
                ret++;
                break;
            }
            else if (s < v[i]) {
                l++;
            }
            else if (s > v[i]) {
                r--;
            }
        }
    }

    cout << ret;
}