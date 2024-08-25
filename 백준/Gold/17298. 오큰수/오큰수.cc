#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int N, arr[1000000], ret[1000000];
stack<int> stk;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	fill(&ret[0], &ret[0] + 1000000, -1);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		while (stk.size() && arr[stk.top()] < arr[i]) {
			ret[stk.top()] = arr[i]; stk.pop();
		}
		stk.push(i);
	}

	for (int i = 0; i < N; i++) cout << ret[i] << ' ';

}