//Amit Rai (IIIT-Hyderabad)
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
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)

vector<int>v[10];
int flag[10];
int visited[100005];
int level[100005];

int bfs(string str,int s,int e){
    queue<int>q;
    visited[s] = 1;
    level[s] = 0;
    q.push(s);
    while(!q.empty()){
        int vx = q.front();
        q.pop();
        if(vx-1>=0 && visited[vx-1] == 0){
            level[vx-1] = level[vx]+1;
            visited[vx-1] = 1;
            q.push(vx-1);
        }
         if(vx+1<=e && visited[vx+1] == 0){
            level[vx+1] = level[vx]+1;
            visited[vx+1] = 1;
            q.push(vx+1);
        }
        if(flag[str[vx]-48] == 0){
           for(int i=0; i<v[str[vx]-48].size(); i++){
            if(visited[v[str[vx]-48][i]] == 0){
               level[v[str[vx]-48][i]] = level[vx]+1;
               visited[v[str[vx]-48][i]] = 1;
               q.push(v[str[vx]-48][i]);
             }
         }
        flag[str[vx]-48] = 1;
       }
        if(level[e] != 0)break;
    }
    return level[e];
}

int main(){
    string str;
    cin>>str;
    int len = str.size();
    for(int i=0; i<len; i++){
        v[str[i]-48].push_back(i);
    }
    cout<<bfs(str,0,len-1)<<endl;
return 0;
}
