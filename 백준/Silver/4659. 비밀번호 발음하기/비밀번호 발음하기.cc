#include <iostream>
#include <algorithm>
using namespace std;


string str;
bool flag;

bool go(string &str) {
	int vowel = 0, con = 0;
	
	bool isVowel = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			//모음인경우
			if (!isVowel) isVowel = true;
			vowel++;
			con = 0;

			if (vowel >= 3) return false;
		}
		else {
			//자음인경우
			vowel = 0;
			con++;			

			if (con >= 3) return false;
		}

		if (i > 0 && (str[i - 1] == str[i])) {
			if (!(str[i] == 'o' || str[i] == 'e')) {
				return false;
			}
		}
	}
	if (isVowel) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> str;
		if (str == "end") return 0;

		flag = go(str);

		if (flag) {
			cout << "<" + str + "> " + "is acceptable." << '\n';
		}
		else {
			cout << "<" + str + "> " + "is not acceptable." << '\n';
		}
	}
}