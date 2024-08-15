#include <iostream>
#include <algorithm>
using namespace std;

long long N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while (cin>>N) {
		
		int ret = 1, cnt = 1;
		while (ret % N != 0) {
			ret = (ret * 10 + 1)%N;
			cnt++;
		}
		cout << cnt<<'\n';
	}
	
	
}
