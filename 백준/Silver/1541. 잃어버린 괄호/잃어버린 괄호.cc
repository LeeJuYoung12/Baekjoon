#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define INF 1e9
using namespace std;

int ret;
string str, num;
bool check = false;
int main() {
	cin >> str;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '-' || str[i] == '+' || i == str.length()) {
			if (check == false) {
				ret += stoi(num);
				num = "";
			}
			else {
				ret += -stoi(num);
				num = "";
			}	//10 +20 -30 +20 + 30
		}
		else {
			num += str[i];
		}
		if (str[i] == '-') check = true;
	}
	cout << ret << '\n';
}
