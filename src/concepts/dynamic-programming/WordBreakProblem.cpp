#include <bits/stdc++.h>

using namespace std;

map<string,bool> M;
void dictionaryConstruction(){
    int n;
    cin>>n;
    while(n--){
        string tmp;
        cin>>tmp;
        M[tmp] = true;
    }
}

bool wordBreak(string input){
    int len = input.size();
    int dp[len];
    for(int i = 0; i < len; i++){
        dp[i] = false;
        string tmp = input.substr(0,i+1);
        if(M.find(tmp) == M.end()){
            for(int k = i-1; k >=1; k--){
                tmp = input.substr(k, i-k+1);
                if(M.find(tmp) != M.end() && dp[k-1]) dp[i] = true;
            }
        } else dp[i] = true;
    }
return dp[len - 1];
}

int main(){
    dictionaryConstruction();
    string input;
    int T;
    cin>>T;
    while(T--){
        cin>>input;
        bool ans = false;
        ans = wordBreak(input);
        if(ans) cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;
    }
return 0;
}
