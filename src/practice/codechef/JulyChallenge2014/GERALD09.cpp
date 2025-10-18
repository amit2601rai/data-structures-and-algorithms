/*Amit Rai(IIIT Hyderabad)*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<ctime>
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

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        char mat[n+1][m+1];
        char p[4];
        p[0] = 'G';
        p[1] = 'C';
        p[2] = 'A';
        p[3] = 'T';
        int flag = 0;
        FOR(i,1,n){
            FOR(j,1,m){
                srand (time(NULL));
                flag = rand() % 4;
                mat[i][j] = p[flag];
            }
        }
        FOR(i,1,n){
            FOR(j,1,m){
                printf("%c",mat[i][j]);
            }
            printf("\n");
        }

    }
return 0;
}
