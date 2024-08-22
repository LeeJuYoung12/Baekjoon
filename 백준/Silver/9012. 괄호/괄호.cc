#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int T;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--) {
		cin >> str;
		bool flag = true;
		stack<char> stk;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				stk.push('(');
			}
			else {
				if (stk.empty()) {
					flag = false;
					break;
				}
				else {
					stk.pop();
				}
			}
		}

		if (!stk.empty()) {
			flag = false;
		}

		if (flag) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}