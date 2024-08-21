#include <iostream>
#include <algorithm>
#include <queue>
#include <ctype.h>
#include <vector>
using namespace std;

int H, W;
int arr[104][104];
string str;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		cin >> str;
		for (int j = 0; j < W; j++) {
			if (str[j] == 'c') arr[i][j] = 0;
			else arr[i][j] = -1;
			
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j]== 0) {
				int cnt = 1;
				while (arr[i][j + 1] == -1) {
					arr[i][j + 1] = cnt++;
					j++;
				}
			}

		}
	}


	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << arr[i][j]<<' ';
		}
		cout << '\n';
	}
}