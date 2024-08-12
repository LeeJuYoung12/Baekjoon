#include <iostream>
#include <algorithm>
using namespace std;

int N, cnt[26];
bool check;
string str;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		cnt[str[0] - 'a']++;

	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) {
			check = true;
			cout << (char)('a' + i);
		}
	}

	if (check == false) {
		cout << "PREDAJA";
	}
}