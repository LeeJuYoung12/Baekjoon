#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#define INF 987654321
using namespace std;

int N, M, temp;
vector<int> v;

int go(int num) {
    int s = 0, e = v.size() - 1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (v[mid] > num) {
            e = mid - 1;
        }
        else if (v[mid] == num) {
            return 1;
        }
        else {
            s = mid + 1;
        }
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        cout << go(temp) << " ";
    }
}