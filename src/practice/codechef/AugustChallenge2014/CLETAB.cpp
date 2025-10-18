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
typedef vector<bool> vb;
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
#define MAX INT_MAX

void updateMax(map<int,int>window,int &maxIdx,int &targetCutmr){
      map<int,int>:: iterator it;
    for(it = window.begin(); it != window.end(); it++){
        if(it->second > maxIdx)maxIdx = it->second,targetCutmr = it->first;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        vi custmr(401);
        vi v[401];
        map<int,int>window;
        FOR(i,0,400)v[i].pb(0),window[i] = 0;
        FOR(i,1,m){
            scanf("%d",&custmr[i]);
            v[custmr[i]].pb(i);
        }
        int x, ans = 0, sz = 0, t;
        int maxIdx = -1, targetCustmr;
        FOR(i,1,m){
            x = custmr[i];
            if(window[x] != 0){
                v[x][0] += 1;
                t = v[x][0] + 1;
                if(t >= v[x].size()) t = MAX;
                else t = v[x][t];
                window[x] = t;
                maxIdx = -1;
                updateMax(window,maxIdx,targetCustmr);
            }
            else if(sz == n){
                window[targetCustmr] = 0;
                v[x][0] += 1;
                t = v[x][0] + 1;
                if(t >= v[x].size()) t = MAX;
                else t = v[x][t];
                window[x] = t;
                maxIdx = -1;
                updateMax(window,maxIdx,targetCustmr);
                ans++;
            }else{
                v[x][0] += 1;
                t = v[x][0] + 1;
                if(t >= v[x].size()) t = MAX;
                else t = v[x][t];
                window[x] = t;
                if(maxIdx < window[x])maxIdx = window[x], targetCustmr = x;
                ans++;
                sz++;
            }
        }
        printf("%d\n",ans);
    }
return 0;
}
