#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
#include <vector>
#define INF 987654321

using namespace std;

int N, M, K, arr[55][55], r, c, s, ret = INF;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
vector<pair<pair<int, int>, int>> cas;
vector<int> numV;
void go(int r, int c, int s, int arr[55][55]) {
	for (int layer = 1; layer <= s; layer++) {
		vector<pair<int, int>> v;
		int y = r - layer;
		int x = c - layer;

		for (int i = 0; i < 2 * layer; i++) {
			v.push_back({ y, x++ });
		}
		for (int i = 0; i < 2 * layer; i++) {
			v.push_back({ y++, x });
		}
		for (int i = 0; i < 2 * layer; i++) {
			v.push_back({ y, x-- });
		}
		for (int i = 0; i < 2 * layer; i++) {
			v.push_back({ y--, x });
		}

		 int temp = arr[v.back().first][v.back().second];
        for (int i = v.size() - 1; i > 0; i--) {
            arr[v[i].first][v[i].second] = arr[v[i - 1].first][v[i - 1].second];
        }
        arr[v[0].first][v[0].second] = temp;
	}
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> r >> c >> s;
		r--, c--;
		cas.push_back({ { r, c }, s });
		numV.push_back(i);
	}


	
	do {
		int temp[55][55];
		memcpy(temp, arr, sizeof(arr));
		for (auto it = numV.begin(); it != numV.end(); it++) {
			go(cas[*it].first.first, cas[*it].first.second, cas[*it].second, temp);
		}
		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < M; j++) {
				sum += temp[i][j];
			}
			ret = min(ret, sum);
		}
	} while (next_permutation(numV.begin(), numV.end()));

	cout << ret;
}