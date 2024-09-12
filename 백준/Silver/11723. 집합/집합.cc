#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int M, N;
string str;
map<int, int> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (str == "add") {
            cin >> N;
            if (mp[N] == 0) {
                mp[N] = 1;
            }
        }
        else if (str == "remove") {
            cin >> N;
            if (mp.find(N) != mp.end()) {
                mp.erase(N);
            }
        }
        else if (str == "check") {
            cin >> N;
            if (mp.find(N) != mp.end()) {
                cout << "1" << '\n';
            }
            else {
                cout << "0" << '\n';
            }
        }
        else if (str == "toggle") {
            cin >> N;
            if (mp.find(N) != mp.end()) {
                mp.erase(N);
            }
            else {
                mp[N] = 1;
            }
        }
        else if (str == "all") {
            for (int i = 1; i <= 20; i++) {
                mp[i] = 1;
            }
        }
        else if (str == "empty") {
            mp.clear();
        }
    }

}