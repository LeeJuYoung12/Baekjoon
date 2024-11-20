#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define INF 987654321
using namespace std;

int N, K, arr[104], cnt[104], ret;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < K; i++) {
        if (!cnt[arr[i]]) {
            if (v.size() == N) {
                int last = 0, pos;
                for (int _a : v) {
                    int here = INF;
                    for (int j = i + 1; j < K; j++) {
                        if (_a == arr[j]) {
                            here = j;
                            break;
                        }
                    }
                    if (last < here) {
                        last = here;
                        pos = _a;
                    }
                }
                cnt[pos] = 0;
                ret++;
                v.erase(find(v.begin(), v.end(), pos));
            }

            v.push_back(arr[i]);
            cnt[arr[i]] = 1;
        }
    }
    cout << ret;
}