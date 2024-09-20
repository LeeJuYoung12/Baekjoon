#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N, a, b, ret = 1;
vector<pair<int, int>> v;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ b, a });
	}

	sort(v.begin(), v.end());
	int start = v[0].second;
	int end = v[0].first;
	for (int i = 1; i < N; i++) {
		if (v[i].second < end) {
			continue;
		}
		start = v[i].second; end = v[i].first; ret++;
	}

	cout << ret << '\n';

}
