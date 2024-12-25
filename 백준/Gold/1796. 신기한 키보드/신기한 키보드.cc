#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int DP[27][2];

int main() {
	vector<vector<int>> v(27); // 0:0, a:1, b:2 ... z:26
	string s;
	
	cin >> s;
	
	for (int i = 0; i < s.size();i++) {
		v[int(s[i] - 'a')+1].push_back(i);
	}
	v[0].push_back(0);

	DP[0][0] = 0;
	DP[0][1] = 0;

	int idx = 0;

	for (int i = 1;i < 27;i++) {
		if (v[i].empty()) {
			DP[i][0] = DP[i - 1][0];
			DP[i][1] = DP[i - 1][1];
			continue;
		}
		int F_E = abs(v[i][0] - v[i].back());
		int enter = v[i].size();
		DP[i][0] = min(DP[idx][0] + abs(v[idx][0] - v[i].back()), DP[idx][1] + abs(v[idx].back() - v[i].back()))+F_E+enter;
		DP[i][1] = min(DP[idx][0] + abs(v[idx][0] - v[i][0]), DP[idx][1] + abs(v[idx].back() - v[i][0]))+F_E+enter;
		idx = i;
	}

	cout << min(DP[26][0], DP[26][1]);


}