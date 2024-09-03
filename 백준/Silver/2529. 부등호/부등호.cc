#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, visited[10];
char arr[10];
string _Min, _Max;
vector<string> ret;

bool comp(string a, string b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
    }

    return a.size() < b.size();
}

bool check(char op, char x, char y) {
    if (x < y && op == '<') return true;
    if (x > y && op == '>') return true;
    return false;
}

void go(int idx, string temp) {
    if (idx == N+1) {
        ret.push_back(temp);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (visited[i]) continue;
        if (idx == 0 || check(arr[idx - 1], temp[idx - 1], i + '0')) {
            visited[i] = 1;
            go(idx + 1, temp + to_string(i));
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    go(0, "");

    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << '\n';
    cout << ret[0] << '\n';
}