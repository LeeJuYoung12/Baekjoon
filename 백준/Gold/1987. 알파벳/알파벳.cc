#include <iostream>
#include <map>

using namespace std;

int R, C, visited[26], ret;
char arr[24][24];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void DFS(int y, int x, int cnt){
    ret = max(ret, cnt);
    
    for(int i = 0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=R||nx>=C) continue;
        int next = (int)(arr[ny][nx] - 'A');
        if(visited[next] == 0){
            visited[next] = 1;
            DFS(ny, nx, cnt + 1);
            visited[next] = 0;
        }
        
    }
}
int main()
{
    cin>>R>>C;
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            cin>>arr[i][j];
        }
    }
    visited[(int)arr[0][0]-'A'] = 1;
    DFS(0, 0, 1);
    cout<<ret<<'\n';
    return 0;
}
