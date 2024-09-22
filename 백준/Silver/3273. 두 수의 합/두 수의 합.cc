#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long N, M, input, s, e;
long long ret;
vector<long> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	cin >> M;
	sort(v.begin(), v.end());

	s = 0; e = N - 1;
	while (s < e) {
		if (M > (v[s] + v[e])) {
			s++;
		}
		else if (M < (v[s] + v[e])) {
			e--;
		}
		else {
			ret++;
			s++;
		}
	}
	cout << ret << '\n';
}
