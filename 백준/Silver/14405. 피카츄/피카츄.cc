#include <iostream>

using namespace std;

string str, temp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    for(int i = 0;i<str.length();i++){
        temp += str[i];
        
        if(temp == "pi"){
            temp = "";
        }
        else if(temp == "ka"){
            temp = "";
        }
        else if(temp == "chu"){
            temp = "";
        }
    }
    
    if(temp == ""){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}