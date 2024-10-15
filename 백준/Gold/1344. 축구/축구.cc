#include <iostream>
#include <cmath>  // sqrt를 사용하기 위해 추가
#include <iomanip>  // 소수점 출력 형식을 맞추기 위해 추가

using namespace std;

double outputA = 0, outputB = 0;  // A팀과 B팀의 소수가 아닌 확률을 저장
double aProb, bProb;  // A와 B팀의 득점 확률

// 주어진 값이 소수인지 판단하는 함수
bool isPrime(int n) {
    if (n <= 1) return false;  // 1 이하의 수는 소수가 아님
    for (int i = 2; i <= sqrt(n); i++) {  // 2부터 n의 제곱근까지 검사
        if (n % i == 0) return false;  // 약수가 있으면 소수가 아님
    }
    return true;  // 약수가 없으면 소수
}

// A팀 또는 B팀의 소수가 아닐 확률을 계산하는 함수
void go(double per, double& output, double ret, int cnt, int goal) {
    if (cnt == 18) {  // 18번의 시도 모두 끝난 경우
        if (!isPrime(goal)) {  // 득점이 소수가 아닌 경우만 더함
            output += ret;
        }
        return;
    }
    
    // 득점한 경우
    go(per, output, ret * per, cnt + 1, goal + 1);
    
    // 득점하지 않은 경우
    go(per, output, ret * (1 - per), cnt + 1, goal);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;  // A팀과 B팀의 득점 확률 입력

    // 백분율을 소수로 변환
    aProb = a * 0.01;
    bProb = b * 0.01;

    // A팀과 B팀 각각의 소수 득점 확률을 계산
    go(aProb, outputA, 1.0, 0, 0);  // A팀의 확률 계산
    go(bProb, outputB, 1.0, 0, 0);  // B팀의 확률 계산

    // A팀과 B팀 모두 소수가 아닐 확률은 outputA * outputB
    // A팀이나 B팀 중 하나라도 소수가 득점할 확률은 1 - (outputA * outputB)
    double result = 1.0 - (outputA * outputB);

    // 소수점 6자리까지 출력
    cout << fixed << setprecision(6) << result << "\n";

    return 0;
}
