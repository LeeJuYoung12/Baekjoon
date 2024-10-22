#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define size 1000001  // N의 최대 크기보다 1 크게 설정
using namespace std;

long long N, M, K, arr[size], tree[size], a, b, c;

void update(int idx, long long val) {
    while (idx <= N) {  // idx가 N 이하일 때까지만 업데이트
        tree[idx] += val;
        idx += (idx & -idx);  // 다음 인덱스 이동
    }
}

void make_Tree() {
    for (int i = 1; i <= N; i++) {
        update(i, arr[i]);
    }
}

long long sum(int idx) {
    long long ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= (idx & -idx);  // 이전 인덱스로 이동
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    make_Tree();  // 트리 생성

    for (int i = 1; i <= M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            // b번째 값을 c로 바꿈
            long long diff = c - arr[b];
            arr[b] = c;
            update(b, diff);
        }
        else {
            // b부터 c까지 합을 구함
            cout << sum(c) - sum(b - 1) << "\n";
        }
    }
}
