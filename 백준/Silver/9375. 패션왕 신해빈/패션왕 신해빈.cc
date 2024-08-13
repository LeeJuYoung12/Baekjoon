#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N, T, ret;
string a, b;
map<string, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	
	while (T--) {
		cin >> N;
		ret = 1;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			mp[b]++;
		}

		for (auto iter = mp.begin(); iter != mp.end(); iter++) {
			ret *= (iter->second + 1);
		}
		ret--;
		mp.erase(mp.begin(), mp.end());
		cout << ret<<'\n';
	}
}
