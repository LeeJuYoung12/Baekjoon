#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#define INF 1e9
using namespace std;

int N, ret, weight[26];
string str[20];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin>>str[i];
		int num = 1;
		for (int j = str[i].length() - 1; j>=0; j--) {
			weight[str[i][j] - 'A'] += num;
			num *= 10;
		}
	}
	sort(weight, weight + 26, greater<int>());
	for (int i = 0; i < 10 ; i++) {
		ret += weight[i] * (9-i);
	}

	cout << ret << '\n';
}
 