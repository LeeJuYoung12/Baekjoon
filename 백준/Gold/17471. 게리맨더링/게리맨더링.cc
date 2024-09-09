#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
using namespace std;

int N, ret = INF, arr[14], num, visited[14], areaNum[14];
vector<int> adj[14];

void DFS(int here, int area) {
	visited[here] = 1;
	for (int next : adj[here]) {
		if (visited[next]) continue;
		if (areaNum[next] != area) continue;
		DFS(next, area);
	}
}

bool isConnected(int area) {
	
	int start = -1;
	
	for (int i = 0; i < N; i++) {
		if (areaNum[i] == area) {
			start = i;
			break;
		}
	}

	if (start == -1) return false;

	DFS(start, area);

	for(int i = 0;i<N;i++){
		if (areaNum[i] == area && !visited[i]) return false;
	}

	return true;
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			
			int temp;
			cin >> temp;
			temp--;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}
	
	for (int i = 0; i < (1 << N); i++) {
		
		bool flag = false;
		int sumA = 0, sumB = 0;

		fill(&visited[0], &visited[0] + 14, 0);
		fill(&areaNum[0], &areaNum[0] + 14, 0);

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				areaNum[j] = 1;//A area check
				sumA += arr[j];
			}
			else {
				sumB += arr[j];
			}
		}		

		if (isConnected(1) && isConnected(0)) {
			ret = min(ret, abs(sumA - sumB));
		}
	}
	if (ret == INF) {
		cout << -1 << '\n';
	}
	else {
		cout << ret << '\n';
	}
}
 