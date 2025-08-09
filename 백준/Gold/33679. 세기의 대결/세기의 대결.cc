#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#define INF 1e9
#define MAX 200001
using namespace std;

int N, A[504], B[504];

int lis(vector<int> &v) {
	int cnt[504], ret = 1;
	vector<int> temp;
	for (int i = 0; i < N; i++) {
		auto pos = lower_bound(temp.begin(), temp.end(), v[i]);
		if (pos == temp.end()) temp.push_back(v[i]);
		else *pos = v[i];
	}

	return temp.size();
}

int getMax(int arr[504]) {
	int ret = 0;
	for (int start = 0; start < N; start++) {
		vector<int> temp; 
		for (int i = start; i < N; i++) {
			temp.push_back(arr[i]);
		}

		for (int i = 0; i < start; i++) {
			temp.push_back(arr[i]);
		}

		ret = max(ret, lis(temp));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	int score1 = getMax(A), score2 = getMax(B);
	if (score1 > score2) {
		cout << "YJ Win!" << '\n';
	}
	else if (score1 < score2) {
		cout << "HG Win!" << '\n';
	}
	else {
		cout << "Both Win!" << '\n';
	}
}