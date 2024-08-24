#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int N, input, visited[50], ret, cut, root;
vector<int> v[50];

void DFS(int i) {
	visited[i] = 1;
	bool isLeaf = true;
	for (int next : v[i]) {
		if (visited[next]||cut==next) continue;
		isLeaf = false;
		DFS(next);
	}
	if (isLeaf) ret++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == -1) {
			root = i;			
		}
		else {
			v[input].push_back(i);
		}
	}

	cin >> cut;
	if (cut == root) {
		cout << 0;
	}
	else {
		DFS(root);
		cout << ret;
	}
}