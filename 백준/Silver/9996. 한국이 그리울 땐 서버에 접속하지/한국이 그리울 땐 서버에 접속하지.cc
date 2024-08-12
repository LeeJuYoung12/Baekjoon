#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
string first, last ,str, temp;

int main() {
	cin >> N;
	cin >> str;
	first = str.substr(0, str.find("*"));
	last = str.substr(str.find("*") + 1);

	for (int i = 0; i < N; i++) {
		cin >> temp;
		//크기같은 예외 주의
		if (first.length()+last.length() > temp.length()) {
			cout << "NE\n";
		}
		else {
			//아이디어.
			if (first == temp.substr(0, first.length()) && last == temp.substr(temp.length() - last.size())) cout << "DA\n";
			else cout << "NE\n";
		}

	}
}
