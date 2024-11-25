#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long S, C, mid, l = 1, r, totalSum = 0, result = 0;
vector<long long> v;

bool check(long long m) {
    long long cnt = 0;
    for (long long length : v) {
        cnt += length / m; // 막대길이로 잘라낼 수 있는 막대 수
    }
    return cnt >= C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> S >> C;
    for (int i = 0; i < S; i++) {
        long long L;
        cin >> L;
        v.push_back(L);
        totalSum += L; // 전체 막대 길이의 합
        r = max(r, L); // 최대 막대 길이
    }

    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            result = mid; // 현재 최대 길이를 저장
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    // 결과 계산
    long long usedLength = result * C; // 사용된 총 길이
    long long leftover = totalSum - usedLength; // 남는 총 길이

    cout << leftover << "\n";
}
