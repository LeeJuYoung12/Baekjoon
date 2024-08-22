#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, i;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (i = 666;; i++) {
		if (to_string(i).find("666") != string::npos)N--;
		if (N == 0) break;
	}
	cout << i;
}