#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int N, M, arr[55][55], ret = 987654321;
vector<pair<int, int>> house, chicken;

void go(int d, vector<int> v) {
	if (v.size() == M) {
		int s = 0;
		for (int i = 0; i < house.size(); i++) {
			int _min = 987654321;
			for (int j:v) {
				int dis = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
				_min = min(_min, dis);			
			}
			s += _min;
		}
		ret = min(ret, s);
		return;
	}
	for (int i = d + 1; i < chicken.size(); i++) {
		v.push_back(i);
		go(i, v);
		v.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.push_back({ i,j });
			else if(arr[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	vector<int> v;
	go(-1 ,v);
	cout << ret;
}