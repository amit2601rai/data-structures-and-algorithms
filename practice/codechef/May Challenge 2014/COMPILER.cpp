#include<iostream>
#include<cstdio>
#include<stack>
#include<string>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string str;
        stack<int>s;
        cin>>str;
        int len = str.size();
        for(int i=0;i<len; i++){
            if(s.empty()){
                s.push(i);
            }else if(str[s.top()] == '<' && str[i] == '>'){
                str[s.top()] = '$';
                str[i] = '$';
                s.pop();
            }else s.push(i);
        }
        int ans = 0;
        for(int i=0; i<len; i++){
            if(str[i] != '$')break;
            ans++;
        }
        cout<<ans<<endl;
    }
return 0;
}
