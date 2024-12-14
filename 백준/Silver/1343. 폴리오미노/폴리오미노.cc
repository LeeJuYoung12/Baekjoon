#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int N;
string input;
void go(int idx, string str) {
	if (idx == N) {
		cout << str << "\n";
		exit(0);
	}

	if (input[idx] == '.') {
		go(idx + 1, str + '.');
		return;
	}
	// 'AAAA'로 변환 가능한 경우
	if (idx + 3 < N && input[idx] == 'X' && input[idx + 1] == 'X' &&
		input[idx + 2] == 'X' && input[idx + 3] == 'X') {
		go(idx + 4, str + "AAAA");
		return;
	}

	// 'BB'로 변환 가능한 경우
	if (idx + 1 < N && input[idx] == 'X' && input[idx + 1] == 'X') {
		go(idx + 2, str + "BB");
		return;
	}

	cout << -1 << "\n";
	exit(0);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> input;
	N = input.length();
	go(0, "");
}
