#include <iostream>
#include <algorithm>
using namespace std;

string str;
int cnt[26];

int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		cnt[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << cnt[i] << ' ';
	}
}