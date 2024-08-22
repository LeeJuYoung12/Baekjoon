#include <iostream>
#include <algorithm>
#include <string>
#define prev ppp

using namespace std;

string str, prev;
int team, score1, score2, T, time1, time2;

string print(int a) {
	string m = "00" + to_string(a / 60);
	string e = "00" + to_string(a % 60);
	return m.substr(m.length() - 2, 2) + ":" + e.substr(e.length() - 2, 2);
}

int changeToInt(string a) {
	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

void go(int& sum, string str) {
	sum += (changeToInt(str) - changeToInt(prev));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--) {
		cin >> team >> str;
		if (score1 > score2) go(time1, str);
		else if (score1 < score2) go(time2, str);
		team == 1 ? score1++ : score2++;
		prev = str;
	}
	if (score1 > score2) go(time1, "48:00");
	else if (score1 < score2) go(time2, "48:00");
	cout << print(time1) << '\n';
	cout << print(time2) << '\n';
}