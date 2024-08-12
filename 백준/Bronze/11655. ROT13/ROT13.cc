#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;

int main() {
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			if ((str[i] + 13) <= 'z') {
				str[i] += 13;
			}
			else {
				str[i] -= 13;
			}
		}
		else if(str[i] >= 'A' && str[i] <= 'Z') {
			if ((str[i] + 13) <= 'Z') {
				str[i] += 13;
			}
			else {
				str[i] -= 13;
			}
		}
		
	}

	cout << str;
}