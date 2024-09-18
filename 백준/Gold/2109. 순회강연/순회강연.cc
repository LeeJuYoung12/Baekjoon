#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, ret, a, b;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ b, a });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		pq.push(v[i].second);
		if (pq.size() > v[i].first) {
			pq.pop();
		}
	}

	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}
	cout << ret;
}