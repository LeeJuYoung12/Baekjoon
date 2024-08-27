#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, L, R, arr[54][54], visited[54][54], ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void DFS(int y, int x){
    visited[y][x] = 1;
    v.push_back({y, x});
    for(int i = 0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=N||nx>=N) continue;
        if(visited[ny][nx]) continue;
        if(abs(arr[y][x]-arr[ny][nx])>=L && abs(arr[y][x]-arr[ny][nx])<=R){
            DFS(ny, nx);
        }
    }
}

bool check(int y, int x){
    for(int i = 0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=N||nx>=N) continue;
        if(abs(arr[y][x]-arr[ny][nx])>=L && abs(arr[y][x]-arr[ny][nx])<=R){
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>N>>L>>R;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            //2*2 3*4 4*
            cin>>arr[i][j];
        }
    }
    while(1){
        bool flag = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(visited[i][j] == 0 && check(i, j) == true){ 
                    DFS(i, j);
                    flag = 1;
                    int after = 0;
                    
                    for(pair<int, int> k:v){
                        after += arr[k.first][k.second];
                    }
                    
                    for(pair<int, int> k:v){
                        arr[k.first][k.second] = after/v.size();
                    }
                    v.clear();
                }
            }
        }
        if(flag == 1){
            ret++;
        }
        else{
            break;    
        } 
        memset(visited, 0, sizeof(visited));
        v.clear();
    }
    cout<<ret;
 
    return 0;
}