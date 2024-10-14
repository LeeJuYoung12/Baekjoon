#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, A[16][16], dir[14];
pair<int, int> pos[14];
vector<int> v[16][16];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };

int change(int n) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return 0;
    }
    else if (n == 2) {
        return 3;
    }
    else if (n == 3) {
        return 2;
    }
    return -1;
}

bool check() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (v[i][j].size() >= 4) return true;
        }
    }
    return false;
}

bool move(int idx) {
    int y = pos[idx].first;
    int x = pos[idx].second;
    int d = dir[idx];

    int ny = y + dy[d];
    int nx = x + dx[d];

    if (ny<1 || nx<1 || ny>N || nx>N || A[ny][nx] == 2) {
        d = change(d);
        dir[idx] = d;
        ny = y + dy[dir[idx]];
        nx = x + dx[dir[idx]];

        if (ny<1 || nx<1 || ny>N || nx>N || A[ny][nx] == 2) {
            return false;
        }
    }

    vector<int> next, now;
    bool check = false;

    for (int i = 0; i < v[y][x].size(); i++) {
        if (v[y][x][i] == idx) {
            check = true;
        }

        if (check) {
            next.push_back(v[y][x][i]);
        }
        else {
            now.push_back(v[y][x][i]);
        }
    }

    //0 흰 1 빨 2 파

    if (A[ny][nx] == 0) {
        v[y][x] = now;
        for (int k : next) {
            v[ny][nx].push_back(k);
            pos[k] = { ny, nx };
        }
    }
    else if (A[ny][nx] == 1) {
        v[y][x] = now;      
        for (int k = next.size() - 1; k >= 0; k--) {
            v[ny][nx].push_back(next[k]);
            pos[next[k]] = { ny, nx };
        }
    }
    
    return v[ny][nx].size() >= 4;

}

int go() {
    int cnt = 0;
    while (cnt<=1000) {
        cnt++;
        
        for (int i = 1; i <= K; i++) {
            if (move(i)) return cnt;
        }
        
        if (check()) return cnt;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            //0 흰 1 빨 2 파
        }
    }

    for (int i = 1; i <=K ; i++) {
        cin >> pos[i].first >> pos[i].second >> dir[i];
        dir[i]--;
        v[pos[i].first][pos[i].second].push_back(i);
    }
    
    cout << go() << "\n";
}
