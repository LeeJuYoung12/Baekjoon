#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 1000004

using namespace std;

int arr[MAX_N], cnt[MAX_N], N, prev_list[MAX_N], ret = 1, idx;
vector<int> retV;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    fill(prev_list, prev_list + MAX_N, -1);
    fill(cnt, cnt + MAX_N, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }
    cout << ret<<"\n";

    int i = idx;
    for (; prev_list[i] != -1; i = prev_list[i]) {
        retV.push_back(arr[i]);
    }

    retV.push_back(arr[i]);
    for (int i = retV.size() - 1; i >= 0; i--) {
        cout << retV[i]<<" ";
    }
}   
