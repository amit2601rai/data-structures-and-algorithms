/*Amit Rai(IIIT Hyderabad)*/
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

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)

double dp[55][55][105];

void init(){
    FOR(i,0,54)FOR(j,0,54)FOR(k,0,104)if(k == 1 && i == 0)dp[i][j][k] = 1.0;else dp[i][j][k] = 0.0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        init();
        int n,c,k,u,v;
        scanf("%d%d%d",&n,&c,&k);
        double cc = c;
        double pc = 1.0/cc;
        double ps = 0.5;
        FOR(p,1,k){
            scanf("%d%d",&u,&v);
            FOR(q,1,n){
                FOR(r,0,c-1){
                    if(q<u || q>v){dp[p][q][r] = dp[p-1][q][r];continue;}
                    dp[p][q][r] += (dp[p-1][q][r]*ps);//empty subset
                    FOR(s,0,c-1){
                        dp[p][q][(r*s)%c] += (dp[p-1][q][r]*ps*pc);
                    }
                }
            }
        }
        double sum = 0;
        FOR(j,0,c-1){
            double tmp = 0.0;
            FOR(i,1,n){
                tmp += dp[k][i][j];
            }
            sum += (tmp*j);
        }
        printf("%lf\n",sum);
    }
return 0;
}
