#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, mp, mf, ms, mv;
int p[20], f[20], s[20], v[20], c[20];
int ret = INF;
vector<int> retVec;
int main()
{
	cin >> N;

	cin >> mp >> mf >> ms >> mv;
	
	for (int i = 0; i < N; i++) {
		cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
	}

	for (int i = 0; i < (1 << N); i++) {
		int tempp = 0, tempf = 0, temps = 0, tempv = 0, tempc = 0;
		vector<int> tempVec;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				tempp += p[j];
				tempf += f[j];
				temps += s[j];
				tempv += v[j];
				tempc += c[j];
				tempVec.push_back(j+1);
			}
		}
		if (tempp >= mp && tempf >= mf && temps >= ms && tempv >= mv) {
			if (ret > tempc || (ret == tempc && tempVec<retVec)) {
				ret = tempc;
				tempVec.swap(retVec);
				
			}
		}
	}
	if (ret == INF) {
		cout << -1 << '\n';
	}
	else {
		cout << ret << '\n';
		for (int i : retVec) {
			cout << i << ' ';
		}
	}

}