#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int k, arr[1050], limit;
vector<int> ret[14];

void solve(int s, int e, int level){
    if(s>e) return;
    if(s==e){
        ret[level].push_back(arr[s]);
        return;
    }
    
    int mid = (s + e)/2;
    ret[level].push_back(arr[mid]);
    solve(s, mid-1, level + 1);
    solve(mid + 1, e, level + 1);
    return;
}

int main()
{
    cin>>k;
    limit = pow(2, k) - 1;
    for(int i = 0;i<limit;i++){
        cin>>arr[i];
    }
    
    solve(0, limit, 1);
    for(int i = 1;i<=k;i++){
        for(int j:ret[i]){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    
}