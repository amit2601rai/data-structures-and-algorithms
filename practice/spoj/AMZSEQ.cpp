#include<iostream>

using namespace std;

int main(){
   
        int n;
        cin>>n;
        if(n==0){
            cout<<"1"<<endl;
          return 0;
        }
        int p=1,q=1,r=1,pp,qq,rr;
        for(int i=2;i<=n;i++){
            pp=p+q;
            qq=p+q+r;
            rr=q+r;
            p=pp;
            q=qq;
            r=rr;
        }
        cout<<p+q+r<<endl;
    return 0;
}



