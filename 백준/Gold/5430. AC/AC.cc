#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int T, N;
string strFunc, strArr;

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        deque<int> dq;
        cin >> strFunc;
        cin >> N;
        cin >> strArr;

        bool error = false, rev = false;
        int x = 0;
        for (char c : strArr) {
            if (c == '[' || c == ']') continue;
            if (c >= '0' && c <= '9') x = x * 10 + c - '0';
            else {
                if (x > 0) dq.push_back(x);
                x = 0;
            }
        }
        if (x > 0) dq.push_back(x);

        for (char a : strFunc) {
            if (a == 'R') rev = !rev; // 잘못된 부분 수정
            else {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (rev) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (error) cout << "error" << '\n';
        else {
            string ret = "[";
            if (rev) reverse(dq.begin(), dq.end());
            for (int i = 0; i < dq.size(); i++) {
                ret += to_string(dq[i]); // 숫자를 문자열로 변환
                if (i != dq.size() - 1) ret += ',';
            }
            ret += ']'; // 빈 덱 처리 및 종료
            cout << ret << '\n';
        }
    }
}
