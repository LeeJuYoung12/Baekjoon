#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e18

using namespace std;

int T, N, M, temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        vector<int> arr1, arr2;    

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            arr1.push_back(temp);
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> temp;
            arr2.push_back(temp);
        }

        sort(arr1.begin(), arr1.end());

        for (int i = 0; i < M; i++) {
            int l = 0, r = N - 1, mid;
            bool flag = false;
            while (l <= r) {
                mid = (l + r) / 2;
                if (arr1[mid] > arr2[i]) {
                    r = mid - 1;
                }
                else if(arr1[mid] < arr2[i]){
                    l = mid + 1;
                }
                else {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                cout << "1" << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }       
    }
}
