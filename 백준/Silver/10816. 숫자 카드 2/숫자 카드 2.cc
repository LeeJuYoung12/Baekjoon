#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#define INF 987654321
using namespace std;

int N, M, arr[100004], temp;
vector<int> v;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        cout << upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) << ' ';
    }

}