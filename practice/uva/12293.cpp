#include<iostream>

using namespace std;

int main(){
    while(1){
        int n;
        cin>>n;
        if(!n)break;
        n++;
        if((n & (n-1)) == 0)cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
return 0;
}
