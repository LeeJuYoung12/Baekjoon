#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int N, L, a, b, ret;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> L;
	
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		b--;
		pq.push({ a, b });		
	}

	int last_cover = 0;
	while (!pq.empty()) {
		int _start = pq.top().first;
		int _end = pq.top().second;
		pq.pop();

		if (last_cover >= _end) continue;

		if (last_cover < _start) {
			last_cover = _start - 1;
		}
		while (last_cover < _end) {
			last_cover += L;
			ret++;
		}
	}

	cout << ret;
}
