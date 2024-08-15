#include <iostream>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

long long N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while (scanf("%d", &N) != EOF) {
		
		int ret = 1, cnt = 1;
		while (ret % N != 0) {
			ret = (ret * 10 + 1)%N;
			cnt++;
		}
		cout << cnt<<'\n';
	}
	
	
}
