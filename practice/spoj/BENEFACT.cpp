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
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef long long ll;
typedef vector<long long > vll;
typedef pair<int, int > ii;

/*main code starts from here*/
int vis[50001];
int dist[50001];
int n;

int bfs(vector< ii >v[],int source)
{
   int x,index,max_val=-1;
   queue<int>Q;
   max_val=-1;
   Q.push(source);
   dist[source]=0;
   vis[source]=1;
   while(!Q.empty())
     {
       x=Q.front();
       Q.pop();
       for(int i=0;i<v[x].size();i++)
          {
              if(vis[v[x][i].second]==0)
                {
                    
                   vis[v[x][i].second]=1;
                   Q.push(v[x][i].second); 
                   dist[v[x][i].second]=dist[x]+v[x][i].first;
                   if(max_val<dist[v[x][i].second])
                      {
                          max_val=dist[v[x][i].second];
                          index=v[x][i].second; 
                      } 
                }
          }

     }
return index;
}
int main()
{
   int t,index;
   cin>>t;
  while(t--) 
    {
      fill(vis,0);
      fill(dist,0);  
      int x,y,z;
      cin>>n;
      vector< ii >v[n+1];
      for(int i=1;i<n;i++)  
        {
           cin>>x>>y>>z;
           v[x].pb(mp(z,y)); 
           v[y].pb(mp(z,x));  
        }
       index=bfs(v,1);
       fill(vis,0);
       fill(dist,0);
       index=bfs(v,index); 
       cout<<dist[index]<<endl;
  }
return 0;
}

