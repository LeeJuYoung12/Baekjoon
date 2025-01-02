#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string maxRet = "", minRet = "9999999999"; // 최대, 최소값 저장
bool visited[10];
char arr[14];
int k; // 전역 변수로 k 선언

bool check(int a, int b, char c) {
    if (c == '>') return a > b;
    else return a < b;
}

void go(int idx, string str) {
    // 숫자를 모두 만들었으면 결과 계산
    if (idx == k + 1) {
        if (str > maxRet) maxRet = str;
        if (str < minRet) minRet = str;
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (visited[i]) continue;

        // 부등호 조건 확인
        if (idx == 0 || check(str.back() - '0', i, arr[idx - 1])) {
            visited[i] = true;
            go(idx + 1, str + to_string(i));
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k; // 입력받은 k 값 저장
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    // 백트래킹 시작
    go(0, "");

    // 결과 출력
    cout << maxRet << '\n';
    cout << minRet << '\n';

    return 0;
}
