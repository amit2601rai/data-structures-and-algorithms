#include<iostream>
#include<string>
#include<set>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    bool flag = true;
    set<int>ss;
    while(n--){
        string str;
        cin>>str;
        int g,s;
        for(int i=0;i<m;i++){
            if(str[i]=='G')g=i;
            else if(str[i]=='S')s=i;
        }
        if(s-g<0)flag = false;
        else ss.insert(s-g);
    }
    if(!flag)cout<<"-1"<<endl;
    else cout<<ss.size()<<endl;
return 0;
}
