#include <iostream>
#include <queue>
using namespace std;

int N, K, visited[100004], cnt[100004];
queue<int> q;

int main()
{
    cin>>N>>K;
    if(N == K){
        cout<<0<<'\n';
        cout<<1;
        return 0;
    }
    visited[N] = 1;
    cnt[N] = 1;
    q.push(N);
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int next:{now -1, now + 1, now*2}){
            if(0<=next && next<=100000){
                if(!visited[next]){
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];     
                }
                else if(visited[next] == visited[now] + 1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout<<visited[K] - 1<<'\n';
    cout<<cnt[K];
    
}