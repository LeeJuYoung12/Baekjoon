#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> v;
int N;
string ret;
void go(){
    while(1){
        if(ret.size() && ret.front() == '0')ret.erase(ret.begin());
        else break;
    }
    if(ret.size() == 0) ret = "0";
    v.push_back(ret);
    ret = "";
}

bool cmp(string a, string b){
    if(a.size() == b.size()) return a<b;
    return a.size()<b.size();
}
int main()
{
    string str;
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>str;
        ret = "";
        for(int j = 0;j<str.size();j++){
            if(str[j]>='0' && str[j]<='9') ret += str[j];
            else if(ret.size()) go();
        }
        if(ret.size()) go();
    }
    sort(v.begin(), v.end(), cmp);
    for(string i:v){
        cout<<i<<'\n';
    }
}