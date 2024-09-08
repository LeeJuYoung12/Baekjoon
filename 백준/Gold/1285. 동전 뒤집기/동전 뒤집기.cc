#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, ret = INF;
int arr[24];
string str;

void go(int here) {
	if (here == N) {
		int s = 0;

		for (int j = 0; j < N; j++) {
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				bool head = ((arr[i] & (1 << j)) != 0);
				if (head) cnt++;
			}
			s += min(cnt, N - cnt);
		}
		ret = min(ret, s);
		return;
	}


	go(here + 1);
	for (int j = 0; j < N; j++) {
		arr[here] ^= (1 << j); // 각 비트를 반전
	}
	go(here + 1);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int value = 0;
		for (int j = 0; j < N; j++) {
			if (str[j] == 'T') {
				value |= (1 << j); // 'T'를 비트로 변환
			}
		}

		arr[i] = value;
	}

	go(0);

	cout << ret;
}
         