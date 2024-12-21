#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, ret, alpha[26];
string str[54];

int check(int learn) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < str[i].length(); j++) {
			if (!(learn & (1 << (str[i][j] - 'a')))) {
				flag = false;
				break;
			}	
		}
		if (flag) cnt++;
	}

	return cnt;
}

void go(int cnt, int idx, int learn) {
	if (cnt == K) {
		ret = max(ret, check(learn));
		return;
	}

	
	for (int j = idx; j < 26; j++) {
		if (learn & (1 << j)) {
			continue;
		}
		else {
			go(cnt + 1, j+1, learn | (1 << j));					
		}	
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	//a n t i c 
	if (K < 5) {
		cout << 0;
		return 0;
	}
	int learn = 0;
	learn |= (1 << ('a' - 'a'));
	learn |= (1 << ('n' - 'a'));
	learn |= (1 << ('t' - 'a'));
	learn |= (1 << ('i' - 'a'));
	learn |= (1 << ('c' - 'a'));

	go(5, 0, learn);
	cout << ret;
}
 