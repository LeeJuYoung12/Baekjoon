#include <iostream>
#include <cmath>  // sqrt를 사용하기 위해 추가
#include <iomanip>  // 소수점 출력 형식을 맞추기 위해 추가

using namespace std;

int a, b;
double outputA, outputB, err = 1e-6;

bool isPrime2(int n) {
    if (n <= 1) return false;  // 1 이하의 수는 소수가 아님
    for (int i = 2; i <= sqrt(n); i++) {  // 2부터 n의 제곱근까지 검사
        if (n % i == 0) {  // i가 n의 약수라면 소수가 아님
            return false;
        }
    }
    return true;  // 소수일 경우 true
}

void go(double per, double &output, double ret, int cnt, int goal) {
    if (cnt == 18) {
        if (!isPrime2(goal)) {  // 소수가 아닐 때만 결과에 더함
            output += ret;
        }
        return;
    }

    go(per, output, ret*per, cnt+1, goal +1);  // 성공한 경우
    go(per, output, ret * (1-per), cnt + 1, goal);  // 실패한 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    double perA = a * 0.01;  // a를 백분율에서 소수로 변환
    double perB = b * 0.01;  // b를 백분율에서 소수로 변환

    go(perA, outputA, 1.0, 0, 0);  // a의 확률로 계산
    go(perB, outputB, 1.0, 0, 0);  // b의 확률로 계산

    double result = 1.0 - (outputA * outputB);

    // 소수점 6자리까지 출력
    cout << fixed << setprecision(6) << result << "\n";
}