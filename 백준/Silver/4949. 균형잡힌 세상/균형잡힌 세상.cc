#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

string str;

bool go(string& str) {
	
	stack<char> stk;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '('||str[i] == '[') {
			stk.push(str[i]);
		}
		else if(str[i] == ')' || str[i] == ']'){
			if (stk.empty()) return false;
						
			if (str[i] == ')') {
				if (stk.top() == '(') stk.pop();
				else return false;
			}
			else if (str[i] == ']') {
				if (stk.top() == '[') stk.pop();
				else return false;
			}
		}
	}

	if (!stk.empty()) return false;
	else return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while (1) {
		getline(cin, str);
		if (str == ".") return 0;
		

		bool flag = go(str);

		if (flag) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}