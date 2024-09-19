#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, a, b, ret;
vector <pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());

	int start = v[0].first;

	for (int i = 0; i < N; i++) {
		if (start > v[i].first) {
			start = start;
		}
		else {
			start = v[i].first;
		}

		start += v[i].second;
	 }
	

	cout << start << '\n';
	return 0;
}

