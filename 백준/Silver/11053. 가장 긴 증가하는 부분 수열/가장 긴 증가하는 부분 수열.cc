#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int N, arr[1004], cnt[1004], ret = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    fill(cnt, cnt + 1004, 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                if (ret < cnt[i]) ret = cnt[i];
            }
        }
    }

    cout << ret;
}   
