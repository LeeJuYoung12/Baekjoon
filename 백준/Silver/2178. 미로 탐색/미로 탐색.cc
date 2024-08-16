#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue> 
using namespace std;

    int N, M, map[104][104], visited[104][104];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    
void BFS(int x, int y){
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while(q.size()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0||nx<0||ny>=N||nx>=M) continue;
            if(visited[ny][nx] || map[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            if(ny == N-1 && nx == M-1){
                cout<<visited[ny][nx];
                return;
            }
        }
    }
    
}
int main()
{
    cin>>N>>M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    BFS(0, 0);
}