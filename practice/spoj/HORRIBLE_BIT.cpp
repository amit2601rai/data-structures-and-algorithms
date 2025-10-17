#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>

#define MAX 100000
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;

typedef long long ll;

using namespace std;


ll tree1[MAX+1];
ll tree2[MAX+1];

ll query1(int idx){
    ll sum = 0;
    while(idx > 0){
        sum += tree1[idx];
        idx -= (idx & -idx);
    }
return sum;
}

ll query2(int idx){
    ll sum = 0;
    while(idx > 0){
        sum += tree2[idx];
        idx -= (idx & -idx);
    }
return sum;
}


ll query(int b){
    return query1(b)*b - query2(b);
}

ll query(int a,int b){
    return query(b) - query(a-1);
}

void update1(int idx,ll val,int n){
    while(idx <= n){
        tree1[idx] += val;
        idx += (idx & -idx);
    }
}

void update2(int idx,ll val,int n){
    while(idx <= n){
        tree2[idx] += val;
        idx += (idx & -idx);
    }
}

void update(int y,int z,ll v,int n){
    update1(y,v,n);
    update1(z+1,-v,n);
    update2(y,v*(y-1),n);
    update2(z+1,-v*z,n);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        memset1d(tree1,MAX,0);
        memset1d(tree2,MAX,0);
        int n,q;
        cin>>n>>q;
        int x,y,z;
        ll v;
        while(q--){
            cin>>x>>y>>z;
            if(x == 0){
                cin>>v;
                update(y,z,v,n);
            }
            else
                cout<<query(y,z)<<endl;
        }
    }
return 0;
}

