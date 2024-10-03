#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1e18

using namespace std;

long long N, atk, nowHeart, t[123457], a[123457], h[123457];

bool check(long long mid) {
    long long now = mid; // 현재 체력
    long long tempAtk = atk; // 현재 공격력
    for (int i = 0; i < N; i++) {
        if (t[i] == 1) {  // 몬스터
            // 몬스터와의 전투에서 공격 횟수를 계산
            long long attackTimesHero = (h[i] + tempAtk - 1) / tempAtk;  // 영웅이 몬스터를 죽이는데 필요한 공격 횟수
            long long attackTimesMonster = (attackTimesHero - 1) * a[i];  // 몬스터가 영웅을 때리는 횟수 * 데미지

            if (now - attackTimesMonster <= 0) return false;  // 영웅이 죽으면 false
            now -= attackTimesMonster;  // 전투 후 체력 계산
        }
        else {  // 포션, 회복
            tempAtk += a[i];  // 공격력 증가
            now = min(mid, now + h[i]);  // 체력 회복, 최대 체력을 넘지 않도록 조정
        }
    }
    return now > 0;  // 영웅이 살아남았으면 true
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> atk;

    for (int i = 0; i < N; i++) {
        cin >> t[i] >> a[i] >> h[i];        
    }
    
    long long l = 1, r = INF, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l;
}
