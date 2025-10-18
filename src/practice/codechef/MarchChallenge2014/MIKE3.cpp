/*Author:Amit(IIIT-H)*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<bitset>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define INF INT_MAX
#define MINF INT_MIN
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <b+1; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)

int table[21][21];

void preProcess(vector<vector<int> >v,int m){
    FOR(i,0,m-1){
        int len = v[i].size();
        FOR(j,i+1,m-1){
            FOR(k,0,len-1){
                if(table[i+1][j+1] == 1)break;
                if(binary_search(v[j].begin(),v[j].end(),v[i][k])){
                    table[i+1][j+1] = table[j+1][i+1] = 1;
                }
            }
        }
    }
}
int solve(vector<vector<int> >v,int m,int n){
     int final_ans = 0;
     for(int i=0;i<(1<<m);i++){
         int total_size = 0;
         int local_ans = 0;
         vector<int>aux;
        for(int k=0;k<m;k++){
            if((i & (1<<k)) != 0){
                total_size += v[k].size();
                aux.pb(k+1);
                local_ans++;
                }
            }
            bool flag = false;
            if(total_size<=n){
                flag = true;
                FOR(i,0,aux.size()-1){
                    FOR(j,i+1,aux.size()-1){
                        if(table[aux[i]][aux[j]]==1){
                                flag = false;
                                break;
                        }
                    }
                }
            }
             if(flag)final_ans = max(final_ans,local_ans);
        }
    return final_ans;
}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int> >v;
    FOR(i,0,m-1){
        int num,x;
        scanf("%d",&num);
        vector<int>vv;
        while(num--){
            scanf("%d",&x);
            vv.pb(x);
        }
     v.pb(vv);
    }
    preProcess(v,m);
    cout<<solve(v,m,n)<<endl;
return 0;
}
