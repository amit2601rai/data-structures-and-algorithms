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
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)

int clocks[101][101];
int main(){
    int n;
    int x,y;
    cin>>n;
    while(n--){
        cin>>x>>y;
        clocks[100-x][y] =  1;
    }
    int row=0,col=0;
    FOR(i,0,100){
        int sum = 0;
        FOR(j,0,100){
            sum += clocks[i][j];
        }
        if(sum>0)row++;
    }
    FOR(j,0,100){
        int sum = 0;
        FOR(i,0,100){
            sum += clocks[i][j];
        }
        if(sum>0)col++;
    }
   cout<<min(row,col);
return 0;
}
