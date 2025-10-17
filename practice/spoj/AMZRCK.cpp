#include<iostream>


using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
                int n;
                cin>>n;
                int p=1,q=2,ans;
                if(n==0){
                    cout<<p<<endl;
                    continue;
                }
                if(n==1){
                    cout<<q<<endl;
                    continue;
                }
                for(int i=2;i<=n;i++){
                    ans=p+q;
                    p=q;
                    q=ans;
                }
                cout<<ans<<endl;
    }
    return 0;
}
