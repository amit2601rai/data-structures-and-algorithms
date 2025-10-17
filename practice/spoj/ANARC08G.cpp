//Author Amit Kr. Rai 
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<climits>

using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define fill(a,v) memset(a, v, sizeof a)
#define sz size()
#define INF (int)1e9
#define EPS 1e-9
#define all(x) x.begin(), x.end()
 
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;

/*main code starts from here*/


int main()
{
   int counter=1;
   while(1)
   {
       int n;
       s(n);
       if(n==0)break;
       //int a[1001][1001];
       int a;
       int cost[1001];
       int total=0;
       //fill(a,0);
       fill(cost,0);
       for(int i=1;i<=n;i++)
        {
           for(int j=1;j<=n;j++)
              {
                 s(a);
                 cost[i]+=a;
                 cost[j]-=a;
                 total=total+a;
              }
        } 
     int sum=0;
     FOR(i,1,n+1)
       if(cost[i]>0)
          sum=sum+cost[i];
     printf("%d. %d %d\n",counter,total,sum);  
    counter++; 
}
return 0;
}

