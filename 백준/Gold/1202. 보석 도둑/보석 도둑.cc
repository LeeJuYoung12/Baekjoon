#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

long long N, K, M, V, C, ret;
vector<pair<long long, long long>> v;
vector<long long> maxWeight;
priority_queue<long long> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> M >> V;
		v.push_back({ M, V});
	}
	for (int i = 0; i < K; i++) {
		cin >> C;
		maxWeight.push_back(C);
	}

	sort(v.begin(), v.end());	
	sort(maxWeight.begin(), maxWeight.end());

	int j = 0;
	for (int i = 0; i < K; i++) {
		while (j < N && v[j].first <= maxWeight[i]) {
			pq.push(v[j++].second);
		}
		if (pq.size()) {
			ret += pq.top(); pq.pop();
		}
	}

	cout << ret << '\n';

}
