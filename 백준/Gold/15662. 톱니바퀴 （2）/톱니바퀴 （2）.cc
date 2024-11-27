#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define INF 60000000004
using namespace std;

int T, temp, K, a, b, ret;
vector<int> v[1004];
string str;

void rotateFunc(int num, int dir) {
    int now1, now2, tempDir;

    now1 = v[num][2];
    now2 = v[num][6];

    if (dir == 1) {
        rotate(v[num].rbegin(), v[num].rbegin() + 1, v[num].rend());
    }
    else {
        rotate(v[num].begin(), v[num].begin() + 1, v[num].end());
    }
    
    tempDir = dir;
    //right
    for (int i = num + 1; i < T; i++) {
        if (now1 == v[i][6]) {
            break;
        }
        else {
            now1 = v[i][2];
            if (tempDir == 1) {
                rotate(v[i].begin(), v[i].begin() + 1, v[i].end());
            }
            else {
                rotate(v[i].rbegin(), v[i].rbegin() + 1, v[i].rend());
            }
            tempDir *= -1;
        }
    }

    tempDir = dir;
    //left
    for (int i = num - 1; i >= 0; i--) {
        if (now2 == v[i][2]) {
            break;
        }
        else {
            now2 = v[i][6];
            if (tempDir == 1) {
                rotate(v[i].begin(), v[i].begin() + 1, v[i].end());
            }
            else {
                rotate(v[i].rbegin(), v[i].rbegin() + 1, v[i].rend());
            }
            tempDir *= -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            v[i].push_back(str[j] - '0');
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        a--;// 1 시계 -1 반시계
        rotateFunc(a, b);
    }

    for (int i = 0; i < T; i++) {
        if (v[i][0] == 1) {
            ret++;
        }
    }
    cout << ret << "\n";
}