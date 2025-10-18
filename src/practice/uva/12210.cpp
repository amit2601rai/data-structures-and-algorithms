#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int b,s;
    int cases = 1;
    while(1){
        cin>>b>>s;
        if(b == 0 && s == 0)
            break;
        int x = 100,temp;
        int y;
        for(int i=0;i<b;i++){
            cin>>temp;
            x = min(x,temp);
        }
        for(int i=0;i<s;i++)
            cin>>y;
        if(b <= s)
            cout<<"Case "<<cases<<": 0"<<endl;
        else
            cout<<"Case "<<cases<<": "<<(b-s)<<" "<<x<<endl;
        cases++;
    }
return 0;
}
