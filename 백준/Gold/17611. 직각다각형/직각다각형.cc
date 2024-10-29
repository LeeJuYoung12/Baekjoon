#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#define INF 987654321
#define y1 yyy
using namespace std;

int N, x, y, x1, y1, x2, y2, _y[1000004], _x[1000004], ret;
pair<int, int> a[100004];
vector<int> checkX, checkY;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        x += 500000;
        y += 500000;
        a[i] = { x, y };
        checkX.push_back(x);
        checkY.push_back(y);
    }
    a[N] = a[0];

    for (int i = 0; i < N; i++) {
        x1 = a[i].first;
        y1 = a[i].second;
        x2 = a[i+1].first;
        y2 = a[i+1].second;
        if (x1 != x2) {
            if (x1 > x2) swap(x1, x2);
            for (int j = x1 + 1; j <= x2; j++) {
                _x[j]++;
            }
        }
        else {
            if (y1 > y2) swap(y1, y2);
            for (int j = y1 + 1; j <= y2; j++) {
                _y[j]++;
            }
        }
    }
    for (int a : checkY) ret = max(ret, _y[a]);
    for (int a : checkX) ret = max(ret, _x[a]);
    cout << ret << "\n";
}