#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int N, K, visited[100004], parent[100004];
stack<int> stk;

int main()
{
    cin>>N>>K;
    if(N == K){
        cout<<0<<'\n';
        cout<<N;
        return 0;
    }
    visited[N] = 1;

    queue<int> q;
    q.push(N);
    while(q.size()){
                
        int now = q.front();
        q.pop();
        
        if(now == K){
            cout<<visited[now] - 1<<'\n';
            int t = K;
            stk.push(K);
            while(t != N){
                t = parent[t];
                stk.push(t);
                
            }
            while(stk.size()){
                cout<<stk.top()<<' ';
                stk.pop();
            }
        }
        
        for(int next:{now-1, now+1, 2*now}){
            if(next>=0 && next<=100000){
                if(!visited[next]){
                    visited[next] = visited[now] + 1;
                    q.push(next);
                    parent[next] = now;
                }
            }
        }
    }
}