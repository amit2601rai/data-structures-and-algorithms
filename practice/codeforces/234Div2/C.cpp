#include<iostream>
#include<algorithm>

using namespace std;

int u,v;

void clockwise(int t,int &n,int &m){
    int x,y;
    for(int i=1;i<=t;i++){
        x = v;
        y = n-u+1;
        u = x;
        v = y;
        swap(n,m);
    }
}

void anticlockwise(int t,int &n,int &m){
    int x,y;
    for(int i=1;i<=t;i++){
        x = m-v+1;
        y = u;
        u = x;
        v = y;
        swap(n,m);
    }
}

void horizontal(int t,int m){
    for(int i=1;i<=t;i++)
        v = m-v+1;
}


int main(){
    int nn,mm,n,m,x,y,z,p;
    cin>>nn>>mm>>x>>y>>z>>p;
    x %= 4;
    y %= 2;
    z %= 4;
    while(p--){
            n = nn;
            m = mm;
            cin>>u>>v;
            clockwise(x,n,m);
            horizontal(y,m);
            anticlockwise(z,n,m);
            cout<<u<<" "<<v<<endl;
        }
return 0;
}
