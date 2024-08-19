#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

    int N, c, temp;
    map<int, int> cnt, order;
    vector<pair<int, int>> v;
    
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first==b.first) return order[a.second] < order[b.second];
    
    return a.first>b.first;
}
int main()
{

    cin>>N>>c;
    
    for(int i = 0;i<N;i++){
        cin>>temp;
        cnt[temp]++;
        if(order[temp] == 0) order[temp] = order.size() + 1;
    }    
    for(auto it: cnt){
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i : v){
        for(int j = 0;j<i.first;j++){
            cout<<i.second<<" ";
        }
    }
    
}