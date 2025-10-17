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

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define fill(a,v) memset(a, v, sizeof a)

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef long long ll;
typedef vector<long long > vll;
typedef pair<int, int > ii;


/*main codes start from here*/

bool myfunction( const pair<int, int>& i, const pair<int, int>& j )
  {
    if( i.first > j.first ) return false;
    if( j.first > i.first ) return true;
    return j.second > i.second;
  }


int main(){
     int t,s,f,n;
     cin>>t;
     while(t--){
         vector<ii>v;
         s(n);
         while(n--){
           s(s);
           s(f);
           v.pb(mp(f,s));
         }
         sort(v.begin(), v.end(), myfunction);
         int count=1;
         int temp=v[0].first;
         for(int i=1; i<v.size(); i++){
             if(temp < v[i].second){
                temp=v[i].first;
                count++;
            }
        }
      cout<<count<<endl;
      }
 return 0;
 }
