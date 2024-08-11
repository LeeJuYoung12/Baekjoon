#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, in[3], out[3], cnt[105], ret;

int main() {
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		cin >> in[i] >> out[i];

		for (int j = in[i]; j < out[i]; j++) {
			cnt[j]++;
		}
	}
	
	for (int i = 0; i < 105; i++) {
		if (cnt[i] == 1) {
			ret += A * 1;
		}
		else if (cnt[i] == 2) {
			ret += B * 2;
		}
		else if (cnt[i] == 3) {
			ret += C * 3;
		}
	}
	cout << ret;
}