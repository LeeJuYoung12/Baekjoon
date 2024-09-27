#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1987654321

using namespace std;

int N, arr[104], operCnt[4], minRet = INF, maxRet = -INF;
char oper[4] = { '+', '-', '*', '/' };
vector<char> operV;
vector<int> numV;

int go(int A, int B, char c) {
	if (c == '+') {
		return A + B;
	}
	else if (c == '-') {
		return A - B;
	}
	else if (c == '*') {
		return A * B;
	}
	else if (c == '/') {
		return A / B;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		numV.push_back(i);		
	}
	numV.pop_back();

	for (int i = 0; i < 4; i++) {
		cin >> operCnt[i];
		for (int j = 0; j < operCnt[i]; j++) {
			operV.push_back({ oper[i] });
		}
	}


	do {
		int ret = arr[0];
		for (int i = 0; i < N-1; i++) {
			ret = go(ret, arr[i + 1], operV[numV[i]]);
		}
		minRet = min(minRet, ret);
		maxRet = max(maxRet, ret);

	} while (next_permutation(numV.begin(), numV.end()));
	// A + B - C + D - E
 	cout << maxRet << "\n";
	cout << minRet << "\n";
}
