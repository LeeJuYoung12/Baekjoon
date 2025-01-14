#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#define INF 987654321
using namespace std;

int N, arr[1000004];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> N; 
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i]; // 최대 10억 

	
		v.push_back(arr[i]);
	}

	
	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());

	// 원래 배열의 원소가 새 배열의 어느 위치로 압축되었는지 출력  
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		cout << idx << " ";
	}

	return 0;
}